/*
 * Keypad.c
 *
 *  Created on: Sep 3, 2022
 *      Author: ahmad
 */
#include <std_types.h>
#include <Macros.h>
#include <Dio.h>
#include <cpu_freq.h>
#include <util/delay.h>
#include <Keypad_cfg.h>
#include <Keypad.h>

static Dio_PinLevelType Keypad_GetRowLevel(u8 row);
static void Keypad_SetColumnLevel(u8 column, Dio_PinLevelType level);

void Keypad_Init(void)
{
    /* Set rows pins to input pullup */
    Dio_SetPinMode(KEYPAD_PIN_R1, DIO_PIN_INPUT_PULLUP);
    Dio_SetPinMode(KEYPAD_PIN_R2, DIO_PIN_INPUT_PULLUP);
    Dio_SetPinMode(KEYPAD_PIN_R3, DIO_PIN_INPUT_PULLUP);
    Dio_SetPinMode(KEYPAD_PIN_R4, DIO_PIN_INPUT_PULLUP);
    /* Set columns pins to output */
    Dio_SetPinMode(KEYPAD_PIN_C1, DIO_PIN_OUTPUT);
    Dio_SetPinMode(KEYPAD_PIN_C2, DIO_PIN_OUTPUT);
    Dio_SetPinMode(KEYPAD_PIN_C3, DIO_PIN_OUTPUT);
    Dio_SetPinMode(KEYPAD_PIN_C4, DIO_PIN_OUTPUT);
    /* Set columns pins to high */
    Dio_SetPinLevel(KEYPAD_PIN_C1, STD_HIGH);
    Dio_SetPinLevel(KEYPAD_PIN_C2, STD_HIGH);
    Dio_SetPinLevel(KEYPAD_PIN_C3, STD_HIGH);
    Dio_SetPinLevel(KEYPAD_PIN_C4, STD_HIGH);
}

Keypad_ButtonStateType Keypad_GetButtonState(Keypad_ButtonType button)
{
    Keypad_ButtonStateType state = KEYPAD_NOT_PRESSED;
    u8 row = button / 4;
    u8 column = button % 4;
    Keypad_SetColumnLevel(column, STD_LOW);
    if (Keypad_GetRowLevel(row) == STD_LOW)
    {
        _delay_ms(5);
        if (Keypad_GetRowLevel(row) == STD_LOW)
        {
            state = KEYPAD_PRESSED;
        }
    }
    Keypad_SetColumnLevel(column, STD_HIGH);
    return state;
}

Keypad_ButtonType Keypad_GetPressedButton(void)
{
    u8 i;
    Keypad_ButtonType button = KEYPAD_INVALID;
    for (i = 0; i < 16; i++)
    {
        if (Keypad_GetButtonState(i) == KEYPAD_PRESSED)
        {
            button = i;
            break;
        }
    }
    return button;
}

Keypad_ButtonType Keypad_GetPressedButtonPolling(void)
{
    u8 i;
    Keypad_ButtonType button = KEYPAD_INVALID;
    for (i = 0; i < 16; i++)
    {
        if (Keypad_GetButtonState(i) == KEYPAD_PRESSED)
        {
            button = i;
            while (Keypad_GetButtonState(i) == KEYPAD_PRESSED)
                ;
            break;
        }
    }
    return button;
}

static Dio_PinLevelType Keypad_GetRowLevel(u8 row)
{
    Dio_PinLevelType level = STD_HIGH;
    switch (row)
    {
    case 0:
        level = Dio_ReadPinLevel(KEYPAD_PIN_R1);
        break;
    case 1:
        level = Dio_ReadPinLevel(KEYPAD_PIN_R2);
        break;
    case 2:
        level = Dio_ReadPinLevel(KEYPAD_PIN_R3);
        break;
    case 3:
        level = Dio_ReadPinLevel(KEYPAD_PIN_R4);
        break;

    default:
        break;
    }
    return level;
}

static void Keypad_SetColumnLevel(u8 column, Dio_PinLevelType level)
{
    switch (column)
    {
    case 0:
        Dio_SetPinLevel(KEYPAD_PIN_C1, level);
        break;
    case 1:
        Dio_SetPinLevel(KEYPAD_PIN_C2, level);
        break;
    case 2:
        Dio_SetPinLevel(KEYPAD_PIN_C3, level);
        break;
    case 3:
        Dio_SetPinLevel(KEYPAD_PIN_C4, level);
        break;
    default:
        break;
    }
}
