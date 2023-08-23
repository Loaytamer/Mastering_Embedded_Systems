/*
 ============================================================================
 Name        : EX3_Add_two_complex_numbers.c
 Author      : Loay Tamer Mohamed
 Description : C Program to Add Two Complex Numbers by Passing Structure to a function
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct scomplex{
	float R;
	float I;
};
struct scomplex Readcomplex()
{
	struct scomplex c;
	printf("Enter real and imaginary respectively: ");
	fflush(stdin);fflush(stdout);
	scanf("%f %f",&c.R,&c.I);
	return c;
}
struct scomplex AddComplex(struct scomplex x, struct scomplex y)
{
	struct scomplex c;
	c.R = x.R + y.R;
	c.I = x.I + y.I;
	return c;
}
void print(struct scomplex c)
{
	printf("Sum = %.1f + %.1fi", c.R, c.I);
}

int main(void) {
	struct scomplex x, y;
	printf("For 1st complex number\n");
	x = Readcomplex();
	printf("For 2nd complex number\n");
	y = Readcomplex();
	print(AddComplex(x, y));
	return 0;
}
