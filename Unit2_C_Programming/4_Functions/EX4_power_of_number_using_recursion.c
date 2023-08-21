/*
 ============================================================================
 Name        : EX4_power_of_number_using_recursion.c
 Author      : Loay Tamer
 Description : C program to Calculate the Power of a Number Using Recursion
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int power_of_num(int base, int power)
{
	if (power == 0)
		return 1;
	else
		return base * power_of_num(base, power-1);
}
int main(void) {
	int base, power;
	printf("Enter base number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &base);
	printf("Enter power number (positive integer): ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &power);
	printf("%d ^ %d = %d", base, base, power_of_num(base,power));

	return 0;
}
