/*
 ============================================================================
 Name        : EX3_ADD.c
 Author      : Loay Tamer
 Description : Add Two Integers
 ============================================================================
 */
#include "stdio.h"
int main(void) {
	int x, y;
	printf("Enter two integers: ");
	fflush(stdout); fflush(stdin);
	scanf("%d %d", &x, &y);
	printf("Sum: %d", x+y);
	return 0;
}
