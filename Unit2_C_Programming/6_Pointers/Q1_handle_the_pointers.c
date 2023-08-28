/*
 ============================================================================
 Name        : Q1_handle_the_pointers.c
 Author      : Loay Tamer Mohamed
 Description : program in C to demonstrate how to handle the pointers
			   in the program.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int m, *ab;
	m = 29;
	printf("Address of m : %p\n", &m);
	printf("Value of m : %d\n\n", m);
	printf("Now ab is assigned with the address of m.\n");
	ab = &m;
	printf("Address of pointer ab : %p\n", ab);
	printf("Content of pointer ab : %d\n\n", *ab);
	printf("The value of m assigned to 34 now.\n");
	m = 34;
	printf("Address of pointer ab : %p\n", ab);
	printf("Content of pointer ab : %d\n\n", *ab);
	printf("The pointer variable ab is assigned with the value 7 now.\n");
	*ab = 7;
	printf("Address of m : %p\n", &m);
	printf("Value of m : %d\n\n", m);
	return 0;
}
