/*
 ============================================================================
 Name        : main.c
 Author      : Loay Tamer Mohamed
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "fifo.h"

element_type buf[5];
int main(void) {
	FIFO_buf_t uart_fifo;
	FIFO_init(&uart_fifo, buf, 5);
	int i;
	element_type item;
	for(i = 0; i < 7 ; i++)
	{
		printf("Enqueue(%d):\n", i);
		if(Enqueue(&uart_fifo, i) == FIFO_no_error)
			printf("\t Enqueue successfully\n");
		else
			printf("\t Enqueue failed\n");
	}
	printf("======== Queue ========\n");
	print_fifo(&uart_fifo);
	printf("======== End ========\n");
	for(i = 0; i < 2 ; i++)
	{
		if(Dequeue(&uart_fifo, &item) == FIFO_no_error)
		{
			printf("Dequeue successfully\n");
			printf("\titem = %d\n", item);
		}
		else
			printf("\t Enqueue failed\n");
	}
	printf("======== Queue ========\n");
	print_fifo(&uart_fifo);
	printf("======== End ========\n");
	for(i = 0; i < 3 ; i++)
	{
		printf("Enqueue(%d):\n", i);
		if(Enqueue(&uart_fifo, i) == FIFO_no_error)
			printf("\t Enqueue successfully\n");
		else
			printf("\t Enqueue failed\n");
	}
	printf("======== Queue ========\n");
	print_fifo(&uart_fifo);
	printf("======== End ========\n");
	return 0;
}
