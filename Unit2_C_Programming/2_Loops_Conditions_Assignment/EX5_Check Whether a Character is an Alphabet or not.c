/*
 ============================================================================
 Name        : EX5_Check.c
 Author      : Loay Tamer
 Description : Check Whether a Character is an Alphabet or not
 ============================================================================
 */

#include "stdio.h"

int main(void) {
	char x;
	printf("Enter an alphabet : ");
	fflush(stdout); fflush(stdin);
	scanf("%c", &x);
	if((x >= 65 && x <= 90) || (x >= 97 && x <= 122))
		printf("%c is an alphabet \n",x);
	else
		printf("%c is no an alphabet \n",x);
	return 0;
}
