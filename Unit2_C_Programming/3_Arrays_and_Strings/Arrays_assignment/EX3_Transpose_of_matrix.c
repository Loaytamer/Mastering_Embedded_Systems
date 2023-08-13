/*
 ============================================================================
 Name        : EX3_Transpose_of_matrix.c
 Author      : Loay Tamer
 Description : program to find transpose of matrix
 ============================================================================
 */


#include <stdio.h>

int main(void) {
	int arr[20][20], c, r;
	printf("Enter number of rows and columns of matrix : ");
	fflush(stdout);fflush(stdin);
	scanf("%d %d", &r, &c);
	for(int i = 0;i<r;i++)
	{
		for(int j=0 ; j<c; j++)
		{
			printf("Enter element(%d,%d) = ",i,j);
			fflush(stdout);fflush(stdin);
			scanf("%d",&arr[i][j]);
		}
	}
	printf("The matrix is : \n");
	for(int i = 0;i<r;i++)
	{
		for(int j=0 ; j<c; j++)
		{
			printf("%d\t",arr[i][j]);
			fflush(stdout);fflush(stdin);
		}
		printf("\n");
	}
	printf("Transpose of matrix : \n");
	for(int i = 0;i<c;i++)
	{
		for(int j=0 ; j<r; j++)
		{
			printf("%d\t",arr[j][i]);
			fflush(stdout);fflush(stdin);
		}
		printf("\n");
	}
	return 0;
}
