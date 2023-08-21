/*
 ============================================================================
 Name        : Q8.c
 Author      : Loay Tamer
 Description : c function to take an array and revers its elements
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
void reverse(int str[],int size)
{
	int i;
	for(i = 0; i < (size)/2 ; i++)
	{
		int temp;
		temp = str[i];
		str[i] = str[size-1-i];
		str[size-1-i] = temp;
	}

}
int main(void) {
	int a[20], n;
	printf("Enter number of elements : ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	reverse(a, n);
	printf("output : ");
	for(int i = 0; i < n; i++)
			printf("%d  ", a[i]);
	return 0;
}
