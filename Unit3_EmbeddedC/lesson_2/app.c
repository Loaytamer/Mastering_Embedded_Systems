#include "uart.h"
unsigned char string_buffer[100] = "Learn-In-Depth:<Loay>";
unsigned char const string_buffer2[100] = "Learn-In-Depth:<Loay>";
void main(void)
{
	Uart_send_string(string_buffer);
}