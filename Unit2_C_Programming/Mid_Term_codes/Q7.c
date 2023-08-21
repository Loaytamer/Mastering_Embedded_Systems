/*
 ============================================================================
 Name        : Q7.c
 Author      : Loay Tamer
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int sum_of_numbers(int num)
{
	return num*(num+1)/2;

}
int main(void) {
	int num;
	printf("Enter a number : ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &num);
	printf("sum of numbers from 1 to %d = %d ", num, sum_of_numbers(num));
	return 0;
}
