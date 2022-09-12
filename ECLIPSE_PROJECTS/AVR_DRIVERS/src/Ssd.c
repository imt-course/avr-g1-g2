/*
 * Ssd.c
 *
 *  Created on: Sep 9, 2022
 *      Author: ahmad
 */


#include <std_types.h>
#include <Macros.h>
#include <Dio.h>
#include <Ssd_cfg.h>
#include <Ssd.h>


void Ssd_Init(void) {
    Dio_SetPinMode(SSD_PIN_A  , DIO_PIN_OUTPUT);
    Dio_SetPinMode(SSD_PIN_B  , DIO_PIN_OUTPUT);
    Dio_SetPinMode(SSD_PIN_C  , DIO_PIN_OUTPUT);
    Dio_SetPinMode(SSD_PIN_D  , DIO_PIN_OUTPUT);
    Dio_SetPinMode(SSD_PIN_E  , DIO_PIN_OUTPUT);
    Dio_SetPinMode(SSD_PIN_F  , DIO_PIN_OUTPUT);
    Dio_SetPinMode(SSD_PIN_G  , DIO_PIN_OUTPUT);
    Dio_SetPinMode(SSD_PIN_DOT, DIO_PIN_OUTPUT);
}

void Ssd_Clear(void) {
#if (SSD_TYPE == SSD_COM_CATHODE)
    Dio_SetPinLevel(SSD_PIN_A  ,STD_LOW );
    Dio_SetPinLevel(SSD_PIN_B  ,STD_LOW );
    Dio_SetPinLevel(SSD_PIN_C  ,STD_LOW );
    Dio_SetPinLevel(SSD_PIN_D  ,STD_LOW );
    Dio_SetPinLevel(SSD_PIN_E  ,STD_LOW );
    Dio_SetPinLevel(SSD_PIN_F  ,STD_LOW );
    Dio_SetPinLevel(SSD_PIN_G  ,STD_LOW );
    Dio_SetPinLevel(SSD_PIN_DOT,STD_LOW );
#elif (SSD_TYPE == SSD_COM_ANODE)
    Dio_SetPinLevel(SSD_PIN_A  ,STD_HIGH);
    Dio_SetPinLevel(SSD_PIN_B  ,STD_HIGH);
    Dio_SetPinLevel(SSD_PIN_C  ,STD_HIGH);
    Dio_SetPinLevel(SSD_PIN_D  ,STD_HIGH);
    Dio_SetPinLevel(SSD_PIN_E  ,STD_HIGH);
    Dio_SetPinLevel(SSD_PIN_F  ,STD_HIGH);
    Dio_SetPinLevel(SSD_PIN_G  ,STD_HIGH);
    Dio_SetPinLevel(SSD_PIN_DOT,STD_HIGH);
#endif
}

void Ssd_DisplayNumber(u8 number) {
    switch (number)
    {
    case 0: // 0b00111111
    #if SSD_TYPE == SSD_COM_CATHODE
        Dio_SetPinLevel(SSD_PIN_A, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_B, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_C, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_D, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_E, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_F, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_G, STD_LOW );
    #elif SSD_TYPE == SSD_COM_ANODE
        Dio_SetPinLevel(SSD_PIN_A, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_B, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_C, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_D, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_E, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_F, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_G, STD_HIGH);
    #else 
        #error "Invalid SSD Type"
    #endif
        break;

    case 1: // 0b00000110
    #if SSD_TYPE == SSD_COM_CATHODE
        Dio_SetPinLevel(SSD_PIN_A, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_B, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_C, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_D, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_E, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_F, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_G, STD_LOW );
    #elif SSD_TYPE == SSD_COM_ANODE
        Dio_SetPinLevel(SSD_PIN_A, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_B, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_C, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_D, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_E, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_F, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_G, STD_HIGH);
    #else 
        #error "Invalid SSD Type"
    #endif
        break;

    case 2: // 0b01011011
    #if SSD_TYPE == SSD_COM_CATHODE
        Dio_SetPinLevel(SSD_PIN_A, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_B, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_C, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_D, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_E, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_F, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_G, STD_HIGH);
    #elif SSD_TYPE == SSD_COM_ANODE
        Dio_SetPinLevel(SSD_PIN_A, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_B, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_C, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_D, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_E, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_F, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_G, STD_LOW );
    #else 
        #error "Invalid SSD Type"
    #endif
        break;

    case 3: // 0b01001111
    #if SSD_TYPE == SSD_COM_CATHODE
        Dio_SetPinLevel(SSD_PIN_A, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_B, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_C, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_D, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_E, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_F, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_G, STD_HIGH);
    #elif SSD_TYPE == SSD_COM_ANODE
        Dio_SetPinLevel(SSD_PIN_A, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_B, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_C, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_D, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_E, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_F, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_G, STD_LOW );
    #else 
        #error "Invalid SSD Type"
    #endif
        break;
    case 4: // 0b01100110
    #if SSD_TYPE == SSD_COM_CATHODE
        Dio_SetPinLevel(SSD_PIN_A, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_B, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_C, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_D, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_E, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_F, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_G, STD_HIGH);
    #elif SSD_TYPE == SSD_COM_ANODE
        Dio_SetPinLevel(SSD_PIN_A, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_B, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_C, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_D, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_E, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_F, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_G, STD_LOW );
    #else 
        #error "Invalid SSD Type"
    #endif
        break;
    case 5: // 0b01101101
    #if SSD_TYPE == SSD_COM_CATHODE
        Dio_SetPinLevel(SSD_PIN_A, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_B, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_C, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_D, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_E, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_F, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_G, STD_HIGH);
    #elif SSD_TYPE == SSD_COM_ANODE
        Dio_SetPinLevel(SSD_PIN_A, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_B, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_C, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_D, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_E, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_F, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_G, STD_LOW );
    #else 
        #error "Invalid SSD Type"
    #endif
        break;
    case 6: // 0b01111101
    #if SSD_TYPE == SSD_COM_CATHODE
        Dio_SetPinLevel(SSD_PIN_A, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_B, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_C, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_D, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_E, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_F, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_G, STD_HIGH);
    #elif SSD_TYPE == SSD_COM_ANODE
        Dio_SetPinLevel(SSD_PIN_A, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_B, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_C, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_D, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_E, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_F, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_G, STD_LOW );
    #else 
        #error "Invalid SSD Type"
    #endif
        break;
    case 7: // 0b00000111
    #if SSD_TYPE == SSD_COM_CATHODE
        Dio_SetPinLevel(SSD_PIN_A, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_B, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_C, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_D, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_E, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_F, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_G, STD_LOW );
    #elif SSD_TYPE == SSD_COM_ANODE
        Dio_SetPinLevel(SSD_PIN_A, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_B, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_C, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_D, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_E, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_F, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_G, STD_HIGH);
    #else 
        #error "Invalid SSD Type"
    #endif
        break;
    case 8: // 0b01111111
    #if SSD_TYPE == SSD_COM_CATHODE
        Dio_SetPinLevel(SSD_PIN_A, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_B, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_C, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_D, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_E, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_F, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_G, STD_HIGH);
    #elif SSD_TYPE == SSD_COM_ANODE
        Dio_SetPinLevel(SSD_PIN_A, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_B, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_C, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_D, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_E, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_F, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_G, STD_LOW );
    #else 
        #error "Invalid SSD Type"
    #endif
        break;
    case 9: // 0b01101111
    #if SSD_TYPE == SSD_COM_CATHODE
        Dio_SetPinLevel(SSD_PIN_A, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_B, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_C, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_D, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_E, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_F, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_G, STD_HIGH);
    #elif SSD_TYPE == SSD_COM_ANODE
        Dio_SetPinLevel(SSD_PIN_A, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_B, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_C, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_D, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_E, STD_HIGH);
        Dio_SetPinLevel(SSD_PIN_F, STD_LOW );
        Dio_SetPinLevel(SSD_PIN_G, STD_LOW );
    #else 
        #error "Invalid SSD Type"
    #endif
        break;

    default:
        Ssd_Clear();
        break;
    }
}


void Ssd_DisplayDot(void) {
#if SSD_TYPE == SSD_COM_CATHODE
    Dio_SetPinLevel(SSD_PIN_DOT, STD_HIGH);
#elif SSD_TYPE == SSD_COM_ANODE
    Dio_SetPinLevel(SSD_PIN_DOT, STD_LOW );
#else 
    #error "Invalid SSD Type"
#endif
}
