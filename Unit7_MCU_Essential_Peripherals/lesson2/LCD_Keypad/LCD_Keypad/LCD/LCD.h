/*
 * Author: Loay Tamer Mohamed
 * Description: LCD.h for avr
 */


#ifndef LCD_H_
#define LCD_H_
#define F_CPU 1000000UL

//===== Includes =====
#include <avr/io.h>
#include <util/delay.h>

/*========== Macros Configuration Reference ==========*/

// @ref LCD mode
#define EIGHT_BIT_MODE
//#define FOUR_BIT_MODE

// @ref LCD pins
#define LCD_PORT		  PORTA
#define DataDir_LCD_PORT DDRA
#define LCD_CTRL		  PORTB
#define DataDir_LCD_CTRL  DDRB
#define RS					1
#define RW					2
#define EN					3

// @ref LCD commands
#define LCD_FUNCTION_8BIT_2LINES   					(0x38)
#define LCD_FUNCTION_4BIT_2LINES   					(0x28)
#define LCD_MOVE_DISP_RIGHT       					(0x1C)
#define LCD_MOVE_DISP_LEFT   						(0x18)
#define LCD_MOVE_CURSOR_RIGHT   					(0x14)
#define LCD_MOVE_CURSOR_LEFT 	  					(0x10)
#define LCD_DISP_OFF   								(0x08)
#define LCD_DISP_ON_CURSOR   						(0x0E)
#define LCD_DISP_ON_CURSOR_BLINK   					(0x0F)
#define LCD_DISP_ON_BLINK   						(0x0D)
#define LCD_DISP_ON   								(0x0C)
#define LCD_ENTRY_DEC   							(0x04)
#define LCD_ENTRY_DEC_SHIFT   						(0x05)
#define LCD_ENTRY_INC_   							(0x06)
#define LCD_ENTRY_INC_SHIFT   						(0x07)
#define LCD_BEGIN_AT_FIRST_ROW						(0x80)
#define LCD_BEGIN_AT_SECOND_ROW						(0xC0)
#define LCD_CLEAR_SCREEN							(0x01)
#define LCD_ENTRY_MODE								(0x06)

/*========== APIs supported by "LCD DRIVER" ==========*/
void LCD_INIT(void);
void LCD_write_command(unsigned char cmd);
void LCD_write_data(unsigned char data);
void LCD_write_string(char* string);
void LCD_Clear_screen(void);
void LCD_kick(void);
void LCD_GOTO_XY(unsigned char line, unsigned char position);
void LCD_isBusy(void);

#endif /* LCD_H_ */