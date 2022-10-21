/*
 * Usart.c
 *
 *  Created on: Oct 7, 2022
 *      Author: ahmad
 */
#include <std_types.h>
#include <Macros.h>
#include <Registers.h>
#include <Dio.h>
#include <Interrupts.h>
#include <cpu_freq.h>
#include <stdarg.h>
#include <Usart.h>
#include <Utils.h>

void (*Usart_ReceiveCallback)(u8 data);
ISR(VECTOR_USART_RX)
{
    Usart_ReceiveCallback(UDR);
}

void Usart_Init(void)
{
    u8 temp = 0;
    /* Select UCSRC Register */
    SET_BIT(temp, 7);
    /* Data Size Select = 8 bit */
    SET_BIT(temp, 1);
    SET_BIT(temp, 2);
    CLR_BIT(UCSRB, 2);
    UCSRC = temp;

    /* Baud Rate Select = 9600 */
    u16 baud = (F_CPU / ((u32)16 * 9600)) - 1;
    UBRRL = (u8)baud;
    UBRRH = (u8)((baud >> 8) & 0x0F);

    /* Rx Enable */
    SET_BIT(UCSRB, 4);
    Dio_SetPinMode(DIO_PORTD, DIO_PIN0, DIO_PIN_INPUT_FLOATING);

    /* Tx Enable */
    SET_BIT(UCSRB, 3);
    Dio_SetPinMode(DIO_PORTD, DIO_PIN1, DIO_PIN_OUTPUT);
}

void Usart_Transmit(u8 data)
{
    while (GET_BIT(UCSRA, 5) == 0)
        ;
    UDR = data;
    while (GET_BIT(UCSRA, 6) == 0)
        ;
    SET_BIT(UCSRA, 6);
}

u8 Usart_Receive(void)
{
    while (GET_BIT(UCSRA, 7) == 0)
        ;
    return UDR;
}

void Usart_EnableReceiveNotification(void (*callback)(u8 data))
{
    Usart_ReceiveCallback = callback;
    SET_BIT(UCSRB, 7);
}

void Usart_DisableReceiveNotification(void)
{
    CLR_BIT(UCSRB, 7);
}

void Usart_SendString(const u8 *str)
{
    while (*str != 0)
    {
        Usart_Transmit(*str);
        str++;
    }
}

void Usart_SendNumber(s64 num)
{
    u64 reversed = 0;
    u8 counter = 0;
    if (num < 0)
    {
        Usart_Transmit('-');
        num *= -1;
    }
    do
    {
        reversed = reversed * 10 + (num % 10);
        num = num / 10;
        counter++;
    } while (num != 0);
    do
    {
        Usart_Transmit(reversed % 10 + '0');
        reversed = reversed / 10;
        counter--;
    } while (counter != 0);
}

void Usart_Print(const u8 *str, ...)
{
    u8 i = 0;
    va_list valist;
    va_start(valist, str);
    while (str[i] != '\0')
    {
        if (str[i] == '%')
        {
            u8 arr[32];
            u8 count;
            i++;
            switch (str[i])
            {
            case 'c':
                Usart_Transmit((u8)va_arg(valist, int));
                break;
            case 'd':
                Usart_SendNumber(va_arg(valist, int));
                break;
            case 'u':
                if (str[i + 1] == 'l')
                {
                    i++;
                    Usart_SendNumber(va_arg(valist, unsigned long));
                }
                else
                {
                    Usart_SendNumber(va_arg(valist, unsigned int));
                }
                break;
            case 'l':
                Usart_SendNumber(va_arg(valist, long));
                break;
            case 'x':
                if (str[i + 1] == 'l')
                {
                    i++;
                    count = Utils_NumberToHex(va_arg(valist, unsigned long), arr);
                }
                else
                {
                    count = Utils_NumberToHex(va_arg(valist, unsigned int), arr);
                }
                for (u8 j = count; j > 0; j--)
                {
                    Usart_Transmit(arr[j]);
                }
                Usart_Transmit(arr[0]);
                break;
            case 'b':
                if (str[i + 1] == 'l')
                {
                    i++;
                    count = Utils_NumberToBin(va_arg(valist, unsigned long), arr);
                }
                else
                {
                    count = Utils_NumberToBin(va_arg(valist, unsigned int), arr);
                }
                for (u8 j = count; j > 0; j--)
                {
                    Usart_Transmit(arr[j]);
                }
                Usart_Transmit(arr[0]);
                break;
            default:
                if (str[i] == '\0')
                {
                    i--;
                }
                else
                {
                    Usart_Transmit(str[i]);
                }
                break;
            }
        }
        else
        {
            Usart_Transmit(str[i]);
        }
        i++;
    }
    va_end(valist);
}
