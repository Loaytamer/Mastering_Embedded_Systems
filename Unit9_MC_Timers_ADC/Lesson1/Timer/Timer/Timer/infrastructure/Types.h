/*
 * Types.h
 *
 * Created: 19/04/2024 00:48:48
 *  Author: Loay
 */ 


#ifndef TYPES_H_
#define TYPES_H_

/*========== Typedefs ==========*/
typedef unsigned char uint8_t;
typedef	char		  sint8_t;

typedef unsigned char* ptr_uint8_t;
typedef  char*         ptr_sint8_t;

typedef void(*ptr_voidFunVoid_t)(void);
#define NULL_PTR	((void*)(0))

typedef unsigned char E_STATUS_t;
#define E_OK	(E_STATUS_t)(0)
#define E_NOK	(E_STATUS_t)(1)

#endif /* TYPES_H_ */