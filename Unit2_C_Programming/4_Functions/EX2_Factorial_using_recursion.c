/*
 ============================================================================
 Name        : EX2_Factorial_using_recursion.c
 Author      : Loay Tamer
 Description : C program to Calculate Factorial of a Number Using Recursion
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int factorial(int num)
{
	if (num == 0 || num == 1)
		return 1;
	else
		return num * factorial(num-1);
}

int main(void) {
	int n;
	printf("Enter an positive integer: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &n);
	printf("Factorial of %d = %d", n, factorial(n));
	return 0;
}
