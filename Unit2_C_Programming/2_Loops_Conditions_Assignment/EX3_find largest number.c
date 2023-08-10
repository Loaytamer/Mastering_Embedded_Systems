/*
 ============================================================================
 Name        : EX3_find.c
 Author      : Loay Tamer
 Description : Find largest number
 ============================================================================
 */
#include "stdio.h"

int main(void) {
	float x, y, z;
	printf("Enter three numbers : ");
	fflush(stdout); fflush(stdin);
	scanf("%f %f %f", &x, &y, &z);
	if(x > y)
	{
		if(x > z)
			printf("Largest number = %f", x);
		else
			printf("Largest number = %f", z);
	}
	else
	{
		if(y > z)
			printf("Largest number = %f", y);
		else
			printf("Largest number = %f", z);
	}
	return 0;
}

