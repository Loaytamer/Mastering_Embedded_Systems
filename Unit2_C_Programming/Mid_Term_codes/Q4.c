/*
 ============================================================================
 Name        : Q4.c
 Author      : Loay Tamer
 Description : c function to reverse digits in number
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int reverse_digits(int number)
{
	int  reversed = 0;
	while(number != 0)
	{
		reversed = (reversed * 10) + (number % 10);
		number /= 10;
	}
	return reversed;
}
int main(void) {
	int t = 2;
	while(t--)
	{
		int num;
		printf("Enter number: ");
		fflush(stdin);fflush(stdout);
		scanf("%d", &num);
		printf("output:%d\n",reverse_digits(num));
	}

	return 0;
}
