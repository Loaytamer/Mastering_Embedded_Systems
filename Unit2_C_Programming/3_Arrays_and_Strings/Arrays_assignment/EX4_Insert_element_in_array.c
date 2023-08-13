/*
 ============================================================================
 Name        : EX4_Insert_element_in_array.c
 Author      : Loay Tamer
 Description : C Program to Insert an element in an Array
 ============================================================================
 */

#include <stdio.h>

int main(void) {
	int n, arr[20], num, loc;
	printf("Enter no of elements : ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &n);
	printf("Enter elements : ");
	fflush(stdout);fflush(stdin);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("Enter the element to be inserted : ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &num);
	printf("Enter the location : ");
	fflush(stdout);fflush(stdin);
	scanf("%d", &loc);
	for(int i = n; i >= loc-1; i--)
	{
		arr[i+1] = arr[i];
	}
	arr[loc-1] = num;
	for(int i = 0; i <= n; i++ )
	{
		printf("%d ", arr[i]);
	}
		return 0;
}
