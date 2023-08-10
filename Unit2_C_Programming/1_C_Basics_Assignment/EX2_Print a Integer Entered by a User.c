/*
 ============================================================================
 Name        : EX2_Print.c
 Author      : Loay Tamer
 Description : Print a Integer Entered by a User
 ============================================================================
 */
#include "stdio.h"
int main(void) {
	char x;
	printf("Enter a integer: ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &x);
	printf("You entered: %d", x);
	return 0;
}
