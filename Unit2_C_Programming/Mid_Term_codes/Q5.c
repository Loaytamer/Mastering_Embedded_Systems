/*
 ============================================================================
 Name        : Q5.c
 Author      : Loay Tamer
 Description : function to count number of ones in binary number
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
int ones_counter(int x)
{
	int sum = 0;
	for(int i = 8; i >= 0; i--)
	{
		sum+= (x>>i)&1;
	}
	return sum;
}
int main(void) {
	int t = 2;
	while (t--)
	{
		int num;
		printf("Enter a number : ");
		fflush(stdin);fflush(stdout);
		scanf("%d", &num);
		printf("input:%d -> output:%d \n", num, ones_counter(num));
	}
	return 0;
}
