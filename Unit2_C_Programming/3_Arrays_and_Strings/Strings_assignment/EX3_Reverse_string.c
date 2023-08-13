/*
 ============================================================================
 Name        : EX3_Reverse_string.c
 Author      : Loay Tamer
 Description : C Program to Reverse String Without Using Library Function
 ============================================================================
 */

#include <stdio.h>
#include "string.h"

int main(void) {
	char str[40];
	printf("Enter a string : ");
	fflush(stdin);fflush(stdout);
	gets(str);
	for(int i = 0; i < (strlen(str)/2) ; i++)
	{
		int temp;
		temp = str[i];
		str[i] = str[strlen(str)-1-i];
		str[strlen(str)-1-i] = temp;
	}
	printf("Reverse string is : %s", str);
	return 0;
}
