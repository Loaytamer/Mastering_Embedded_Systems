/*
 ============================================================================
 Name        : Lifo.h
 Author      : Loay Tamer Mohamed
 ============================================================================
 */

#ifndef LIFO_H_
#define LIFO_H_

typedef struct{
	unsigned int* base;
	unsigned int* top;
	unsigned int length;
	unsigned int count;
}stack_buf_t;

typedef enum {
	LIFO_no_error,
	LIFO_is_full,
	LIFO_is_empty,
	LIFO_null
}lifo_status;

lifo_status LIFO_init(stack_buf_t* lifo_buf, unsigned int* buf, unsigned int length);
lifo_status push     (stack_buf_t* lifo_buf, unsigned int* item);
lifo_status pop 	 (stack_buf_t* lifo_buf, unsigned int* item);
#endif /* LIFO_H_ */
