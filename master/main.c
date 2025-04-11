#include "mcc_generated_files/mcc.h"

#define ADDR_OP 0x00
#define COCA 0x01
#define RHUM 0x02
#define SUZE 0x03
#define RICARD 0x04
#define JAGGER 0x05
#define PAIX_DIEU 0x06

void IT_BP1(void); //IT du BP1 (envoie de l'octet commande prete)
void IT_BP2(void); // IT du BP2 (envoie de l'octet commande recupéré)
void IT_SELECT(void); // IT pour la selection octet adresse et octet data
uint8_t IT_CW_ROT2(void); // IT pour la rotation de l'encodeur rotatif
uint8_t protocol_com_adresse(uint8_t addr); //fonction qui permet l'init du protcole sur la variable adresse 
uint8_t protocol_com_data(uint8_t data); //fonction qui permet l'init du protcole sur la variable data 

int8_t flag; // flag du BP1 dans l'IT du BP1
int8_t flag2; // flag du BP2 dans l'IT du BP2
uint8_t addr_val = 0; 
uint8_t data_val = 0;

typedef enum {
    SET_1,
    SET_2            
}state_t;
state_t etat = SET_1; //machine etat pour choisir entre octet addresse et octet data 

typedef enum {
    RX_IDLE,
    RX_CHECK_ADDR,
    RX_CHECK_DATA       
}RX_t;
RX_t RX_byte = RX_IDLE; //machine etat pour decodage entre octet addresse et octet data 
// par defaut en reception de addr

void main(void) {
    
    SYSTEM_Initialize();
    INTERRUPT_GlobalInterruptEnable();
    INTERRUPT_PeripheralInterruptEnable();
    TMR2_SetInterruptHandler(IT_BP1); //BP1 send 
    TMR4_SetInterruptHandler(IT_BP2); // BP reset 
    TMR6_SetInterruptHandler(IT_CW_ROT2); // select value
    TMR0_SetInterruptHandler(IT_SELECT); // BP3 select 
    
    uint8_t lu_addr, lu_data, addresse, boisson;
    
    ADDR_SetLow(); // init LED d'adresse 
    ACCUSE_RX_SetLow();
    RECOMMANDER_SetLow();
    
    while (1) {

        // allumé LED1 lorsque qu'on appuie sur BP1
        if (flag == 1) {
            flag = 0;
            LED1_SetHigh(); // allumé LED1 des qu'on appuie sur BP1
            __delay_ms(100);
            LED1_SetLow();
        } else {
        }
        
        // allumé LED1 lorsque qu'on appuie sur BP2
        if (flag2 == 1) {
            flag2 = 0;
            LED2_SetHigh(); // allumé LED2 des qu'on appuie sur BP2
            __delay_ms(100);
            LED2_SetLow();
        } else {
        }
        
        // reception 
        switch(RX_byte) {
            case RX_IDLE :
                if (EUSART_is_rx_ready()) {
                    uint8_t last_received_addr = EUSART_Read();
                        if (0x01 == (last_received_addr & 0x01)) {
                            lu_addr = last_received_addr;
                            RX_byte = RX_CHECK_ADDR;
                        } else {
                            RX_byte = RX_IDLE;
                        }
                }   else {}
            break;    

            case RX_CHECK_ADDR : 
                if(EUSART_is_rx_ready()) {
                    uint8_t last_received_data = EUSART_Read();
                        if (0x00 == (last_received_data & 0x01)) {
                            lu_data = last_received_data;
                            RX_byte = RX_CHECK_DATA;
                        } else {
                            RX_byte = RX_IDLE;
                        }
                }   else {}
            break;

            case RX_CHECK_DATA: 
                // après qu'on est reçu les deux octets : 
                addresse = (lu_addr & 0xFC); // extraire les 6 bits utiles dans l'addresse recu
                boisson = (lu_data & 0xFC); // extraire les 6 bits utiles dans la boisson recu 
                
                    if (addresse == ADDR_OP) { // si adresse reçu vaut l'adresse de l'operateur 
                        // on a la bonne adresse ! 
                        // partie data     
                        if (((lu_data & 0x01) == 0)) { // detection octet data
                        // on a donc bien recu l'octet de data et d'addr on peut donc tester leur contenu 
                            if ((((lu_data & 0x02)>>1) == 0) && ((lu_addr & 0x02)>>1) == 0) { // si le 2 LSB de data vaut 0 donc c'est du feedback
                                ACCUSE_RX_SetHigh();
                                __delay_ms(200);
                                ACCUSE_RX_SetLow();
                            } else if  ((((lu_data & 0x02)>>1) == 1) && ((lu_addr & 0x02)>>1) == 1) { // si le 2 LSB vaut 1 alors on ca signfie recommander 
                                RECOMMANDER_SetHigh();
                                __delay_ms(200);
                                RECOMMANDER_SetLow();
                            }
                 
                        }   
                    }   else {}
                RX_byte = RX_IDLE;    
            break;

        }        
            
    } // fin while(1)
}    


// fonction IT pour BP1 : prevenir le chevalet (lorsque la commande est prete !)
void IT_BP1(void) { //envoie sur appui BP1 commande prete
    if (BP1_GetValue() == 0) {
        EUSART_Write(protocol_com_adresse(addr_val) | 0x02);
        EUSART_Write(protocol_com_data(data_val) & 0xFD);
        flag = 1;
    }
}

// fonction IT pour BP2 : reset du chevalet (lorsque la commande a ete recuperé)
void IT_BP2(void) { //envoie sur appui BP2 commande recupéré 
    if (BP2_GetValue() == 0) {
        EUSART_Write(protocol_com_adresse(addr_val) | 0x00);
        EUSART_Write(protocol_com_data(data_val) & 0xFD);
        flag2 = 1;
    }
}

// fonction IT de l'encodeur rotatif 
uint8_t IT_CW_ROT2(void) { //permet l'écriture de l'adresse
    static uint8_t last_state = 0;  // Dernier état de l'encodeur (A)
    static uint8_t cpt = 0;         // Compteur pour suivre les mouvements
    uint8_t etat_actuel = ENCA_GetValue();  // Lecture de l'état actuel de A
    uint8_t direction = ENCB_GetValue();    // Lecture de l'état de B

    // Si l'état actuel de ENCA est différent du dernier état, procéder
    if (etat_actuel != last_state) {
        // Attente pour garantir la stabilité de la lecture (anti-rebond)
       
        // Relire l'état d'ENCA après un délai pour éviter les rebonds
        etat_actuel = ENCA_GetValue();
        
        // Si l'état est toujours différent, on traite la transition
        if (etat_actuel != last_state) {
            // Vérification de la direction en fonction de la relation entre A et B
            if (direction != etat_actuel) {
                // Si la direction est inversée (rotation dans un sens), décrémente de 1
                if (cpt == 0) {
                    cpt = 6;  // Réinitialisation à 6 si cpt == 0 pour la décrémentation
                } else {
                    cpt--;  // Décrémenter le compteur de 1
                }
            } else {
                // Si la direction est identique (rotation dans l'autre sens), incrémente de 1
                cpt++;  // Incrémenter le compteur de 1
                if (cpt == 7) {  // Limite supérieure du compteur
                    cpt = 0;  // Réinitialisation à 0 si on atteint 7
                }
            }
        }
    }

    // Mettre à jour l'état précédent de l'encodeur pour la prochaine comparaison
    last_state = etat_actuel;
    return cpt;  // Retourner la valeur actuelle du compteur
}

// protocole pour l'octet de adresse  
uint8_t protocol_com_adresse(uint8_t addr) {
    addr = ((addr & 0x3F) << 2) | 0x01; // protocole comm pour octet adresse => forcage du bit de poids faible a 1 
    return addr;
}

// protocole pour l'octet de data 
uint8_t protocol_com_data(uint8_t data) {
    data = ((data & 0x3F) << 2) & 0xFE; //protocole comm pour octet data => forcage du bit de poids faible a 0 
    return data;
}

// fonction IT pour selectionner entre octet adresse et octet data 
void IT_SELECT(void) { //added
    if (BP3_GetValue()==0) {
        etat = ! etat;
    }
    switch(etat) {
        case SET_1 : 
            addr_val = IT_CW_ROT2();
            TEST_SetHigh();
            break;
        case SET_2 : 
            data_val = IT_CW_ROT2();
            TEST_SetLow();
            break;
        }
}





