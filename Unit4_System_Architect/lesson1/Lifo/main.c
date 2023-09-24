/*
 ============================================================================
 Name        : main.c
 Author      : Loay Tamer Mohamed
 Description : Lifo implementation
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "lifo.h"

unsigned int buffer1[5];

int main(void) {
	stack_buf_t uart_lifo, i2c_lifo;
	LIFO_init(&uart_lifo, buffer1, 5);
	unsigned int* buffer2 = (unsigned int*)malloc(5*sizeof(unsigned int));
	LIFO_init(&i2c_lifo, buffer2, 5);
	int i; unsigned int temp;
	for (i = 0; i < 5; ++i) {
		temp = i+1;
		if( push(&uart_lifo, &temp) == LIFO_no_error)
			printf("add element : %d\n", temp);
	}
	printf("====================================\n");
	for (i = 0; i < 5; ++i) {
		if(pop(&uart_lifo, &temp) == LIFO_no_error)
			printf("pop element : %d\n", temp);
	}
	return 0;
}
