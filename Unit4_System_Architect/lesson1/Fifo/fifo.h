/*
 ============================================================================
 Name        : fifo.h
 Author      : Loay Tamer Mohamed
 Description : header file for Queue
 ============================================================================
 */

#ifndef FIFO_H_
#define FIFO_H_
#include "stdio.h"
#include "stdint.h"

//User Configration
//select data type of elements like (uint8_t, uint16_t, ...)
#define element_type uint8_t

typedef struct{
	element_type* base;
	element_type* head;
	element_type* tail;
	element_type  length;
	element_type  count;
}FIFO_buf_t;

typedef enum{
	FIFO_no_error,
	FIFO_full,
	FIFO_empty,
	FIFO_null,
}FIFO_status;

FIFO_status FIFO_init(FIFO_buf_t* fifo_buf, element_type* buf, element_type length);
FIFO_status Enqueue(FIFO_buf_t* fifo_buf, element_type item);
FIFO_status Dequeue(FIFO_buf_t* fifo_buf, element_type* item);
void print_fifo(FIFO_buf_t* fifo_buf);
#endif /* FIFO_H_ */
