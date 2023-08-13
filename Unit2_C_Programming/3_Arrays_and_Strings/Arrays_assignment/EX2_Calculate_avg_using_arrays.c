/*
 ============================================================================
 Name        : EX2_Calculate_avg_using_arrays.c
 Author      : Loay Tamer
 Description : C Program to Calculate Average Using Arrays
 ============================================================================
 */

#include <stdio.h>

int main(void) {
	int n;
	float arr[20], sum=0;
	printf("Enter no of data : ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		printf("%d.Enter number : ",i+1);
		fflush(stdout);fflush(stdin);
		scanf("%f", &arr[i]);
		sum+=arr[i];
	}
	printf("Average = %.2f", sum/n);
	return 0;
}
