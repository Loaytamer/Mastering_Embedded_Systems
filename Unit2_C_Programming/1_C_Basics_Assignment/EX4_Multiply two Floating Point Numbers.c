/*
 ============================================================================
 Name        : EX4_multiply.c
 Author      : Loay Tamer
 Description : C Program to Multiply two Floating Point Numbers
 ============================================================================
 */
#include "stdio.h"
int main(void) {
	float x, y;
	printf("Enter two numbers : ");
	fflush(stdout); fflush(stdin);
	scanf("%f %f", &x, &y);
	printf("Sum: %f", x*y);
	return 0;
}
