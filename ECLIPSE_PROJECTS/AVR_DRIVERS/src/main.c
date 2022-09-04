/*
 * main.c
 *
 *  Created on: Aug 26, 2022
 *      Author: ahmad
 */

#include <std_types.h>
#include <Keypad.h>
#include <Lcd.h>

int main(void)
{
	Lcd_Init();
	Keypad_Init();
	Keypad_ButtonType button;
	while (1)
	{
		button = Keypad_GetPressedButton();
		if (button != KEYPAD_INVALID)
		{
			Lcd_DisplayNumber(button);
			while (Keypad_GetButtonState(button) == KEYPAD_PRESSED)
				;
		}
	}
}
