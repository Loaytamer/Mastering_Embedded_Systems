/*
 ============================================================================
 Name        : EX3_Reverse_sentence_using_recursion.c
 Author      : Loay Tamer
 Description : C program to Reverse a Sentence Using Recursion
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "string.h"

void reverse_sentence(char str[], int size, int counter)
{
	if (counter == size/2)
		return;
	else
	{
		char temp = str[counter];
		str[counter] = str[size-counter-1];
		str[size-counter-1] = temp;
		reverse_sentence(str, size, ++counter );
	}
}
int main(void) {
	char str[50];
	printf("Enter a sentence: ");
	fflush(stdin);fflush(stdout);
	gets(str);
	reverse_sentence(str, strlen(str), 0);
	printf("%s", str);
	return 0;
}
