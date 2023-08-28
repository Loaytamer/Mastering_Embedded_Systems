/*
 ============================================================================
 Name        : Q4_.c
 Author      : Loay Tamer Mohamed
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int arr[15], n, *p_arr;
	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &n);
	printf("Input %d number of elements in the array :\n", n);
	for(int i = 0; i < n; i++)
	{
		printf("element - %d : ", i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d", arr+i);

	}
	printf("The elements of array in reverse order are :");
	p_arr = &arr[n-1];
	for(int i = n; i > 0; i--)
	{
		printf("\nelement - %d : %d", i, *p_arr);
		p_arr--;
	}
	return 0;
}
