/*
 ============================================================================
 Name        : EX5_Search_in_array.c
 Author      : Loay Tamer
 Description : C Program to Search an element in Array
 ============================================================================
 */

#include <stdio.h>

int main(void) {
	int n, arr[20], num;
	printf("Enter no of elements : ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &n);
	printf("Enter elements : ");
	fflush(stdout);fflush(stdin);
	for(int i = 0; i < n; i++)
	{
		scanf("%d",&arr[i]);
	}
	printf("Enter the element to be searched : ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &num);
	int i;
	for(i = 0; i < n; i++)
	{
		if (arr[i] == num)
		{
			printf("Number found at the location : %d",i+1);
			break;
		}
	}
	if (i>n)
	{
		printf("Number not found in array.");
	}
	return 0;
}
