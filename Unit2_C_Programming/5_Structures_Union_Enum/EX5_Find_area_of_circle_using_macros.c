/*
 ============================================================================
 Name        : EX5_Find_area_of_circle_using_macros.c
 Author      : Loay Tamer Mohamed
 Description : C Program to find area of a circle, passing arguments to macros.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#define PI 3.14
#define Area(r) (PI*r*r)
int main(void) {
	float radius, area;
	printf("Enter the radius: ");
	fflush(stdin);fflush(stdout);
	scanf("%f", &radius);
	area = Area(radius);
	printf("Area = %.2f", area);
	return 0;
}
