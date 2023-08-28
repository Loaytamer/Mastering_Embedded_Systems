/*
 ============================================================================
 Name        : Q3_.c
 Author      : Loay Tamer Mohamed
 Description : a program in C to print a string in reverse using a pointer
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"
int main(void) {
	char str[20];
	char* p_str;
	printf("Input a string : ");
	fflush(stdin);fflush(stdout);
	gets(str);
	printf("Reverse of the string is : ");
	p_str = &str[strlen(str)-1];
	for(int i = 0; i < strlen(str); i++)
	{
		printf("%c", *p_str);
		p_str--;
	}
	return 0;
}
