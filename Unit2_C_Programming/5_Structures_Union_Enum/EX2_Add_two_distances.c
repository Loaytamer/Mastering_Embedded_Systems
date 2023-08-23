/*
 ============================================================================
 Name        : EX2_Add_two_distances.c
 Author      : Loay Tamer Mohamed
 Description : C Program to Add Two Distances (in inch-feet) System Using structure
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Distance
{
	int feet;
	float inch;
};

struct Distance readData()
{
	struct Distance d;
	printf("Enter feet: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &d.feet);
	printf("Enter inch: ");
	fflush(stdin);fflush(stdout);
	scanf("%f", &d.inch);
	return d;
}

void displayAdd(struct Distance d1, struct Distance d2)
{
	struct Distance sum;
	sum.feet = d1.feet + d2.feet;
	sum.inch = d1.inch + d2.inch;
	if(sum.inch>12)
	{
		sum.inch-=12;
		sum.feet++;
	}
	printf("\nsum of distances = %d '-%.1f\"", sum.feet, sum.inch);
}
int main(void) {
	struct Distance d1, d2;
	printf("Enter information for 1st distance:\n");
	d1 = readData();
	printf("\nEnter information for 2nd distance:\n");
	d2 = readData();
	displayAdd(d1, d2);

	return 0;
}
