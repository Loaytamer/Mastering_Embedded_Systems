/*
 ============================================================================
 Name        : EX1_prime_numbers_between_interval.c
 Author      : Loay Tamer
 Description : Prime Numbers Between two Intervals by Making User-defined function
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

void primeNumbers(int start, int end)
{
	int flag;
	printf("Prime numbers between %d and %d are: ", start, end);
	for (int i = start; i <= end; i++)
	{
		if (i == 0 || i == 1)
			continue;
		flag = 1;
		for (int j = 2; j < i/2; j++)
		{
			if (i%j == 0)
			{
				flag = 0;
				break;
			}
		}
		if(flag)
			printf("%d ",i);
	}
}
int main(void) {
	int start, end;
	printf("Enter two numbers (intervals): ");
	fflush(stdin);fflush(stdout);
	scanf("%d %d", &start, &end);
	primeNumbers(start, end);
	return 0;

}
