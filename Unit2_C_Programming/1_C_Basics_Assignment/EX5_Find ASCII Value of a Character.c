/*
 ============================================================================
 Name        : EX5_Find.c
 Author      : Loay Tamer
 Description : C Program to Find ASCII Value of a Character
 ============================================================================
 */
#include "stdio.h"
int main(void) {
	char x ;
	printf("Enter a character: ");
	fflush(stdout); fflush(stdin);
	scanf("%c", &x);
	printf("ASCII value of %c = %d", x, x);
	return 0;
}
