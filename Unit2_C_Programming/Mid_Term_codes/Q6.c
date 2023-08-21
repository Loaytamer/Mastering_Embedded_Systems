/*
 ============================================================================
 Name        : Q6.c
 Author      : Loay Tamer
 Description : c function to return unique number in array with one loop
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int unique(int arr[], int size)
{
	int res = 0;
	for (int i = 0; i < size; i++)
	{
		res^=arr[i];
	}
	return res;
}
int main(void) {
	int n,t=2,arr[15];
	while(t--)
	{
		printf("Enter number of elements : ");
		fflush(stdin);fflush(stdout);
		scanf("%d", &n);
		printf("Enter elements of array : ");
		fflush(stdin);fflush(stdout);
		for(int i = 0; i < n; i++ )
			scanf("%d", &arr[i]);
		printf("output:%d\n", unique(arr, n));
	}

	return 0;
}
