/*
 ============================================================================
 Name        : fifo.c
 Author      : Loay Tamer Mohamed
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include "fifo.h"
FIFO_status is_full(FIFO_buf_t* fifo_buf)
{
	if(!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
		return FIFO_null;
	if (fifo_buf->count == fifo_buf->length)
		return FIFO_full;
	return FIFO_no_error;
}
FIFO_status FIFO_init(FIFO_buf_t* fifo_buf, element_type* buf, element_type length)
{
	if (buf == NULL)
		return FIFO_null;
	fifo_buf->base   = buf;
	fifo_buf->head   = buf;
	fifo_buf->tail   = buf;
	fifo_buf->length = length;
	fifo_buf->count  = 0;
	return FIFO_no_error;
}
FIFO_status Enqueue(FIFO_buf_t* fifo_buf, element_type item)
{
	//check if the fifo is valid or not
	if(!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
		return FIFO_null;
	//enqueue the value
	if((is_full(fifo_buf)) == FIFO_no_error)
	{
		*(fifo_buf->head) = item;
		fifo_buf->count++;
		//check if the head ptr reach to end of queue
		if(fifo_buf->head == (fifo_buf->base + fifo_buf->length * sizeof(element_type)))
			fifo_buf->head = fifo_buf->base;
		//if head doesn't reach to end of queue, INC head
		else
			fifo_buf->head++;
		return FIFO_no_error;
	}
	else
		return FIFO_full;
}
FIFO_status Dequeue(FIFO_buf_t* fifo_buf, element_type* item)
{
	//check if the fifo is valid or not
	if(!fifo_buf->base || !fifo_buf->head || !fifo_buf->tail)
		return FIFO_null;
	//store the value in item var
	*item = *(fifo_buf->tail);
	fifo_buf->count--;
	//check if the tail ptr reach to end of queue
	if(fifo_buf->tail == (fifo_buf->base + fifo_buf->length * sizeof(element_type)))
		fifo_buf->tail = fifo_buf->base;
	//if tail doesn't reach to end of queue, INC head
	else
		fifo_buf->tail++;
	return FIFO_no_error;
}
void print_fifo(FIFO_buf_t* fifo_buf)
{
	element_type* temp;
	temp = fifo_buf->tail;
	int i;
	for(i = 0; i < fifo_buf->count; i++)
	{
		printf("%d\n", *(temp));
		if(temp == (fifo_buf->base + fifo_buf->length * sizeof(element_type)))
			temp = fifo_buf->base;
		else
			temp++;
	}
}


