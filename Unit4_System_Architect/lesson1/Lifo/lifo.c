/*
 ============================================================================
 Name        : Lifo.c
 Author      : Loay Tamer Mohamed
 ============================================================================
 */
#include "lifo.h"
#include "stdio.h"
lifo_status LIFO_init(stack_buf_t* lifo_buf, unsigned int* buf, unsigned int length)
{
	if (buf == NULL)
		return LIFO_null;
	lifo_buf->base   = buf;
	lifo_buf->top    = lifo_buf->base;
	lifo_buf->length = length;
	lifo_buf->count  = 0;
	return LIFO_no_error;
}

lifo_status push(stack_buf_t* lifo_buf, unsigned int* item)
{
	//check lifo_buf is valid
	if(lifo_buf->base == NULL)
		return LIFO_null;
	//check lifo_buf is full
	if(lifo_buf->count == lifo_buf->length)
		return LIFO_is_full;
	//add item
	*(lifo_buf->top) = *(item);
	lifo_buf->top++;
	lifo_buf->count++;
	return LIFO_no_error;
}
lifo_status pop(stack_buf_t* lifo_buf, unsigned int* item)
{
	//check lifo_buf is valid
	if(lifo_buf->base == NULL)
		return LIFO_null;
	//check lifo_buf is full
	if(lifo_buf->count == 0)
		return LIFO_is_empty;
	//pop item
	lifo_buf->top--;
	*item = *(lifo_buf->top);
	lifo_buf->count--;
	return LIFO_no_error;
}

