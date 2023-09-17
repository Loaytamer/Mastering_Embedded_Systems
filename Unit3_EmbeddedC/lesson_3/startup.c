#include "stdint.h"
extern int main(void);
extern unsigned int _stack_top;
extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;
void Reset_Handler(void)
{
	int i;
	//copy data from flash to sram
	unsigned int Data_size = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
	unsigned char* p_src = (unsigned char*)&_E_text;
	unsigned char* p_dist = (unsigned char*)&_S_data;
	for(i = 0; i < Data_size; i++)
	{
		*((unsigned char*)p_dist++) = *((unsigned char*)p_src++);
	}

	// initialize bss 
	unsigned int Bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss;
	p_dist = (unsigned char*)&_S_bss;
	for (i = 0; i < Bss_size; ++i)
	{
		*((unsigned char*)p_dist++) = (unsigned char)0;
	}
	main();
}
void Default_Handler()
{
	Reset_Handler();
}
void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));

void H_fault_Handler(void) __attribute__((weak, alias("Default_Handler")));

void MM_fault_Handler(void) __attribute__((weak, alias("Default_Handler")));

void Bus_Fault(void) __attribute__((weak, alias("Default_Handler")));

void Usage_Fault_Handler(void) __attribute__((weak, alias("Default_Handler")));


uint32_t vectors[] __attribute__((section(".vectors")))={
	(uint32_t) &_stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &MM_fault_Handler,
	(uint32_t) &Bus_Fault,
	(uint32_t) &Usage_Fault_Handler
};