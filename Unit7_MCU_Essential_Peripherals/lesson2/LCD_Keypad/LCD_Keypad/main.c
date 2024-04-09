/*
 * LCD_Keypad.c
 * Author : Loay
 */ 

#include "LCD/LCD.h"
#include "KEYPAD/Keypad.h"


int calculator(){
	;
}
int main(void)
{
    LCD_INIT();
	Keypad_init();	
    while (1) 
    {
		char key;
		key = Keypad_getKey();
		switch (key){
			case 'N':break;
			case 'O':LCD_Clear_screen();break;
			default:LCD_write_data(key); break;
		}
    }
}

