/*
 ============================================================================
 Name        : EX2_Check.c
 Author      : Loay Tamer
 Description : Check Vowel or Consonant
 ============================================================================
 */

#include "stdio.h"

int main(void) {
	char x;
	printf("Enter an alphabet : ");
	fflush(stdout); fflush(stdin);
	scanf("%c", &x);
	switch(x)
	{
	case 'a':
	case 'e':
	case 'i':
	case 'o':
	case 'u':
	{printf("%c is a vowel. \n",x);}
	break;
	default :
	{printf("%c is a consonant. \n",x);}
	}
	return 0;
}
