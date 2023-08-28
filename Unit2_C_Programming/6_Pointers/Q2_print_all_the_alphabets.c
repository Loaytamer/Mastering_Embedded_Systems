/*
 ============================================================================
 Name        : Q2_print_all_the_alphabets.c
 Author      : Loay Tamer Mohamed
 Description : a program in C to print all the alphabets using a pointer.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	char* c = 65;
	for (int i = 0; i < 26; i++)
	{
		printf("%c  ", c);
		c++;
	}

	return 0;
}
