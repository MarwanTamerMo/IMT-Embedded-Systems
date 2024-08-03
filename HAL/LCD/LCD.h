/*
 * LCD.h
 *
 *  Created on: Apr 8, 2024
 *      Author: Marwan
 */

#ifndef LCD_H_
#define LCD_H_

#define LCD_CLR 0x01
#define LCD_HOME 0x02
#define LCD_DEC_CURSOR 0x04
#define LCD_INC_CURSOR 0x06
#define LCD_SHIFT_RIGHT 0x05
#define LCD_SHIFT_LEFT 0x07
#define LCD_DISPLAY_OFF_CURSOR_OFF 0x08
#define LCD_DISPLAY_OFF_CURSOR_ON 0x0A
#define LCD_DISPLAY_ON_CURSOR_OFF 0x0C
#define LCD_DISPLAY_ON_CURSOR_BLINK 0x0E
#define LCD_DISPLAY_ON_CURSOR_ON_BLINK 0x0F
#define LCD_SHIFT_CURSOR_LEFT 0x10
#define LCD_SHIFT_CURSOR_RIGHT 0x14
#define LCD_SHIFT_DISPLAY_LEFT 0x18
#define LCD_SHIFT_DISPLAY_RIGHT 0x1C
#define LCD_FORCE_CURSOR_1ST_LINE 0x80
#define LCD_FORCE_CURSOR_2ND_LINE 0xC0

void LCD_vidInit(void);
void LCD_vidSendCmd(uint8 u8LcdIndxCpy, uint8 u8CmdCpy);
void LCD_vidWriteData(uint8 u8LcdIndxCPy, uint8 u8DataCpy);

void LCD_vidWriteString(uint8 u8LcdIndxCpy, char* charString); /* to write string */
void LCD_vidWriteNumber(uint8 u8LCDIndx, uint32 u32NumberCpy);

#endif /* LCD_H_ */
