/*
 ============================================================================
 Name        : EX1_Find_freq_of_char.c
 Author      : Loay Tamer
 Description : C Program to Find the Frequency of Characters in a String
 ============================================================================
 */
#include <stdio.h>
#include "string.h"

int main(void) {
	int count = 0;
	char str[40], c;
	printf("Enter a string : ");
	fflush(stdin);fflush(stdout);
	gets(str);
	printf("Enter a character to find frequency : ");
	fflush(stdin);fflush(stdout);
	scanf("%c", &c);
	for(int i = 0; i < strlen(str); i++)
	{
		if (str[i] == c)
			count++;
	}
	printf("frequency of %c : %d", c, count);
	return 0;
}
