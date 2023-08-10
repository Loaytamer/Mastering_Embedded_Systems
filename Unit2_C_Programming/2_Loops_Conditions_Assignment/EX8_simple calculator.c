/*
 ============================================================================
 Name        : EX8_simple.c
 Author      : Loay Tamer
 Description : simple calculator
 ============================================================================
 */

#include "stdio.h"

int main(void) {
	char c;
	float x, y;
	printf("Enter operator either + or - or * or divide : ");
	fflush(stdout); fflush(stdin);
	scanf("%c", &c);
	printf("Enter two operands : ");
	fflush(stdout); fflush(stdin);
	scanf("%f %f", &x, &y);
	switch(c)
	{
	case '+':
		printf("%1.2f + %1.2f = %1.2f", x, y, x+y);
		break;
	case '-':
		printf("%1.2f - %1.2f = %1.2f", x, y, x-y);
		break;
	case '*':
		printf("%1.2f * %1.2f = %1.2f", x, y, x*y);
		break;
	case '/':
		printf("%1.2f / %1.2f = %1.2f", x, y, x/y);
		break;
	default:
		printf("Error");
		break;
	}
	return 0;
}
