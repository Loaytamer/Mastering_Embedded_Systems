/*
 ============================================================================
 Name        : q3.c
 Author      : Loay Tamer
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
void primeNumbers(int start, int end)
{
	int flag;
	fflush(stdin);fflush(stdout);
	printf("input:n1=%d,n2=%d ->output: ", start, end);
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
	fflush(stdin);fflush(stdout);
	primeNumbers(start,end);
	return 0;
}
