/*
 ============================================================================
 Name        : EX1_Even.c
 Author      : Loay Tamer
 Description : Even or Odd
 ============================================================================
 */
#include "stdio.h"

int main(void) {
	int x;
	printf("Enter an integer you want to check : ");
	fflush(stdout); fflush(stdin);
	scanf("%d", &x);
	if (x%2 == 0)
		printf("%d is even", x);
	else
		printf("%d is odd \n", x);
	return 0;
}

