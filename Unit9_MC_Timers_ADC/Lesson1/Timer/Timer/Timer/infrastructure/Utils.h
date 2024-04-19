/*
 * Utils.h
 *
 * Created: 19/04/2024 00:49:02
 *  Author: Loay
 */ 


#ifndef UTILS_H_
#define UTILS_H_

/*========== Generic Macros ==========*/
#define SET_BIT(port, bit)			port |= (1<<bit)
#define RESET_BIT(port, bit)		port &= ~(1<<bit)
#define TOGGLE_BIT(port, bit)		port ^= (1<<bit)
#define GET_BIT(port, bit)		    port & (1<<bit)



#endif /* UTILS_H_ */