#include "mcc_generated_files/mcc.h"
#include "mcc_generated_files/eusart.h"
#include "mcc_generated_files/examples/i2c1_master_example.h"

// adresse LCD I2C 
#define LCD_I2C_ADDRESS 0x27 // LCD i2c adresse 
#define LCD_DATA_REG 0x40 // => bit RS=0
#define LCD_COMMAND_REG 0x00 // => RS=1

void LCD_SendCommand(uint8_t command);
void LCD_SendData(uint8_t data);
void LCD_Init(void);
void LCD_Print(const char *text);

// adresse chevalet + adresse boisson
#define ADDR_OP 0x00
#define ADDR_CHEV 0x05 // adresse propre du chevalet 5 
#define COCA 0x01
#define RHUM 0x02
#define SUZE 0x03
#define RICARD 0x04
#define JAGGER 0x05
#define PAIX_DIEU 0x06

void IT_BP1(void);
uint8_t protocol_com_adresse(uint8_t addr);
uint8_t protocol_com_data(uint8_t data);

typedef enum {
    RX_IDLE,
    RX_CHECK_ADDR,
    RX_CHECK_DATA       
}RX_t;
RX_t RX_byte = RX_IDLE; // machine etat pour decodage entre octet addresse et octet data 
uint8_t addresse, boisson; // reutiliser dans l'IT 
uint8_t flag_test; 

void main(void) { 
    SYSTEM_Initialize(); 
    LCD_Init();
    COCA_SetLow();
    ADDR_SetLow();
    uint8_t lu_addr, lu_data, feedback;
    feedback =0;
    
    INTERRUPT_GlobalInterruptEnable();    
    INTERRUPT_PeripheralInterruptEnable();
    TMR4_SetInterruptHandler(IT_BP1);
    
    while (1) {  
        if (flag_test==1) {
                flag_test=0;
                INFO_SetHigh();
                __delay_ms(200);
                INFO_SetLow();
        } else {}
        LCD_SendCommand(0x80);
        LCD_Print("Hello ");
        
        // Decodeur du protocole 
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
                addresse = (lu_addr & 0xFC)>>2; // extraire les 6 bits utiles dans l'addresse recu
                boisson = (lu_data & 0xFC)>>2; // extraire les 6 bits utiles dans la boisson recu 
                
                    if (addresse == ADDR_CHEV) { // si adresse reçu vaut l'adresse de l'operateur 
                        ADDR_SetHigh(); // on allume la LED_ADDR 
                        __delay_ms(200);
                        ADDR_SetLow();
                        feedback=1;
                        if ((lu_data & 0x01) == 0) { // detection octet data 
                            switch (boisson) {
                                case COCA : 
                                    COCA_SetHigh();
                                    __delay_ms(200);
                                    COCA_SetLow();
                                break;
                                case RHUM : 
                                    RHUM_SetHigh();
                                    __delay_ms(200);
                                    RHUM_SetLow();
                                break;
                            }
                        }   
                    }   else {}
                
                if (feedback==1) { //renvoie octet feedback 
                    EUSART_Write(protocol_com_adresse(ADDR_OP) & 0xFD); // 2 LSB non definis lors feedback  
                    EUSART_Write(protocol_com_data(boisson) & 0xFD); // 2 LSB a 0 
                    feedback=0;
                }
                
                RX_byte = RX_IDLE;    
            break;
        }
    }
}

void IT_BP1(void) { //recommander 
    if(BP1_GetValue()==0) {
        EUSART_Write(protocol_com_adresse(ADDR_OP) | 0x02); // 2 LSB a 1 
        EUSART_Write(protocol_com_data(boisson) | 0x02); // 2 LSB a 1 
        flag_test=1;
    }
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


void LCD_SendCommand(uint8_t command) {
    I2C1_Write1ByteRegister(LCD_I2C_ADDRESS, LCD_COMMAND_REG, (command & 0xF0)); // Envoyer les 4 bits hauts
    I2C1_Write1ByteRegister(LCD_I2C_ADDRESS, LCD_COMMAND_REG, (command << 4)); // Envoyer les 4 bits bas
}


void LCD_SendData(uint8_t data) {
    I2C1_Write1ByteRegister(LCD_I2C_ADDRESS, LCD_DATA_REG, ((data & 0xF0) | 0x01)); // Envoyer les 4 bits hauts avec le bit de données activé
    I2C1_Write1ByteRegister(LCD_I2C_ADDRESS, LCD_DATA_REG, (((data << 4) & 0xF0) | 0x01)); // Envoyer les 4 bits bas
}


void LCD_Init(void) {
    __delay_ms(50); // Attente pour la mise sous tension
    LCD_SendCommand(0x30); // Séquence d'initialisation
    __delay_ms(5);
    LCD_SendCommand(0x28); // Mode 4 bits, 2 lignes
    LCD_SendCommand(0x0C); // Activer écran, désactiver curseur
    LCD_SendCommand(0x06); // Mode d'incrémentation
    LCD_SendCommand(0x01); // Effacer l'écran
}


void LCD_Print(const char *text) {
    while (*text) {
        LCD_SendData(*text++);
    }
}