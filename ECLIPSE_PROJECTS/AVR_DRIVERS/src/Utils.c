/*
 * utils.c
 *
 *  Created on: Oct 1, 2022
 *      Author: ahmad
 */

#include <std_types.h>

void Utils_NumberToHex(u32 number, u8 arr[])
{
    u8 counter = 0;
    u8 remainder;
    do
    {
        remainder = number % 16;
        number /= 16;
        if (remainder < 10)
        {
            arr[counter] = remainder + '0';
        }
        else
        {
            arr[counter] = remainder - 10 + 'A';
        }
        counter++;
    } while (number != 0);
    arr[counter] = '\0';
}


void Utils_NumberToBin(u32 number, u8 arr[])
{
    u8 counter = 0;
    do
    {
        arr[counter] = number % 2;
        number /= 2;
        counter++;
    } while (number != 0);
    arr[counter] = '\0';
}
