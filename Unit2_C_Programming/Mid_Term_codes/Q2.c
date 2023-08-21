/*
 ============================================================================
 Name        : Q2.c
 Author      : Loay Tamer
 Description : function to take an integer number and calculate it's square root
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
float square_root(int num)
{
	return sqrt(num);
}
int main(void) {
	int t=2;
	while(t--)
	{
		int num;
		printf("Enter a number : ");
		fflush(stdin);fflush(stdout);
		scanf("%d", &num);
		printf("input:%d -> output:%.3f\n",num,square_root(num));
	}
	return 0;
}
