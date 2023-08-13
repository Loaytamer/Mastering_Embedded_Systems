/*
 ============================================================================
 Name        : EX1_Multidimensional_Array.c
 Author      : Loay Tamer
 Description : Multidimensional Array in C
 ============================================================================
 */

#include <stdio.h>

int main(void) {
	float arr1[2][2], arr2[2][2];
	printf("Enter the elements of 1st array : \n");
	fflush(stdout);
	for(int i = 0;i<2;i++)
	{
		for(int j=0 ; j<2; j++)
		{
			printf("Enter element a(%d,%d) = ",i,j);
			fflush(stdout);fflush(stdin);
			scanf("%f",&arr1[i][j]);
		}
	}
	printf("Enter the elements of 2nd array : \n");
	for(int i = 0;i<2;i++)
	{
		for(int j=0 ; j<2; j++)
		{
			printf("Enter element b(%d,%d) = ",i,j);
			fflush(stdout);fflush(stdin);
			scanf("%f",&arr2[i][j]);
		}
	}
	printf("sum of 2 matrices : \n");
	for(int i = 0; i < 2; i++)
	{
		for(int j = 0; j < 2; j++)
		{
			printf("%.1f\t",arr1[i][j]+arr2[i][j]);
		}
		printf("\n");
	}
	return 0;
}
