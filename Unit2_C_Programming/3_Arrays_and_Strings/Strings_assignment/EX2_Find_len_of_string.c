/*
 ============================================================================
 Name        : EX2_Find_len_of_string.c
 Author      : Loay Tamer
 Description : C Program to Find the Length of a String
 ============================================================================
 */

#include <stdio.h>

int main(void) {
	int count = 0;
	char str[40];
	printf("Enter a string : ");
	fflush(stdin);fflush(stdout);
	gets(str);
	for(int i = 0; i <40 && str[i] != 0; i++)
	{
		count++;
	}
	printf("Length of string : %d", count);
	return 0;
}
