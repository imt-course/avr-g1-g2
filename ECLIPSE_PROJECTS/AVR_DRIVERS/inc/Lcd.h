/*
 * Lcd.h
 *
 *  Created on: Sep 2, 2022
 *      Author: ahmad
 */

#ifndef INC_LCD_H_
#define INC_LCD_H_


typedef enum {
    LCD_DISPLAY_OFF,
    LCD_DISPLAY_ON
} Lcd_DisplayType;

typedef enum {
    LCD_CURSOR_OFF,
    LCD_CURSOR_ON_BLINK,
    LCD_CURSOR_ON_NOT_BLINK,
} Lcd_CursorType;

typedef enum {
    LCD_ONE_LINE,
    LCD_TWO_LINES
} Lcd_LineType;

typedef enum {
    LCD_FONT_5X7,
    LCD_FONT_5X10
} Lcd_FontType;

typedef struct 
{
    Lcd_DisplayType display_status;
    Lcd_CursorType cursor_status;
    Lcd_LineType line_status;
    Lcd_FontType font_status;
} Lcd_DisplayControlType;

void Lcd_Init(void);
void Lcd_DisplayCharacter (u8 character);
void Lcd_DisplayString (u8* str);
void Lcd_DisplayNumber (s32 num);
void Lcd_DisplayClear(void);
void Lcd_SetCursorPosition(u8 row, u8 col);
void Lcd_DisplayShiftLeft(u8 counter);
void Lcd_DisplayShiftRight(u8 counter);
void Lcd_ReturnHome(void);
void Lcd_DisplayControl(Lcd_DisplayControlType display);
void Lcd_SaveSpecialCharacter(u8* data, u8 location);

#endif /* INC_LCD_H_ */
