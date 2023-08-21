/*
 ============================================================================
 Name        : Q1.c
 Author      : Loay Tamer
 Description : function to take a number and sum all digits
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int sum_of_digits(int num)
{
	int sum = 0;
	while(num!=0)
	{
		sum+=num%10;
		num/=10;
	}
	return sum;
}
int main(void) {
	int t=2;
	while(t--)
	{
		int num;
		printf("Enter a number : ");
		fflush(stdin);fflush(stdout);
		scanf("%d", &num);
		printf("input:%d -> output:%d\n",num,sum_of_digits(num));
	}
	return 0;
}
