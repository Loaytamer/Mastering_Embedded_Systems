/*
 ============================================================================
 Name        : EX4_positive.c
 Author      : Loay Tamer
 Description : Check Whether a Number is Positive or Negative
 ============================================================================
 */

#include "stdio.h"

int main(void) {
	float x;
	printf("Enter a number : ");
	fflush(stdout); fflush(stdin);
	scanf("%f", &x);
	if (x > 0)
		printf("%f is positive.\n", x);
	else if (x < 0)
		printf("%f is negative.\n", x);
	else
		printf("You entered zero.\n");
	return 0;
}
