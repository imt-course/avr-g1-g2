/*
 * Calculator.c
 *
 *  Created on: Sep 9, 2022
 *      Author: ahmad
 */

#include <std_types.h>
#include <Macros.h>
#include <Lcd.h>
#include <Keypad.h>
#include <Calculator.h>

static u8 Calculator_GetActualNumber(u8 button);

void Calculator_Init(void)
{
    Keypad_Init();
    Lcd_Init();
}

void Calculator_Run(void)
{
    u32 number = 0;
    s32 result = 0;
    u8 operation = 0;
    u8 button;
    u8 actual_number;
    while (1)
    {
        do
        {
            button = Keypad_GetPressedButtonPolling();
        } while (button == KEYPAD_INVALID);

        actual_number = Calculator_GetActualNumber(button);

        if (button == CALC_BUTTON_CLR)
        {
            Lcd_DisplayClear();
            number = 0;
            result = 0;
            operation = 0;
        }
        else if ((actual_number >= 0) && (actual_number <= 9))
        {
            Lcd_DisplayNumber(actual_number);
            number = number * 10 + actual_number;
        }
        else
        {
            Lcd_DisplayCharacter(actual_number);
            switch (operation)
            {
            case '+':
                result += number;
                break;
            case '-':
                result -= number;
                break;
            case '*':
                result *= number;
                break;
            case '/':
                result /= number;
                break;
            default:
                result = number;
                break;
            }
            operation = actual_number;
            number = 0;
        }

        if (operation == '=')
        {
            Lcd_SetCursorPosition(1, 0);
            Lcd_DisplayNumber(result);
        }
    }
}

static u8 Calculator_GetActualNumber(u8 button)
{
    u8 number = 0;
    switch (button)
    {
    case CALC_BUTTON_0:
        number = 0;
        break;
    case CALC_BUTTON_1:
        number = 1;
        break;
    case CALC_BUTTON_2:
        number = 2;
        break;
    case CALC_BUTTON_3:
        number = 3;
        break;
    case CALC_BUTTON_4:
        number = 4;
        break;
    case CALC_BUTTON_5:
        number = 5;
        break;
    case CALC_BUTTON_6:
        number = 6;
        break;
    case CALC_BUTTON_7:
        number = 7;
        break;
    case CALC_BUTTON_8:
        number = 8;
        break;
    case CALC_BUTTON_9:
        number = 9;
        break;
    case CALC_BUTTON_PLUS:
        number = '+';
        break;
    case CALC_BUTTON_MINUS:
        number = '-';
        break;
    case CALC_BUTTON_MUL:
        number = '*';
        break;
    case CALC_BUTTON_DIV:
        number = '/';
        break;
    case CALC_BUTTON_EQUAL:
        number = '=';
        break;
    default:
        break;
    }
    return number;
}
