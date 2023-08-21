/*
 ============================================================================
 Name        : Q10.c
 Author      : Loay Tamer
 Description : c function to count the max number of ones between two zeros
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int count_max_ones_between_two_zeros(int num)
{
	int arr[10];
	for(int i = 10; i >= 0; i--)
	{
		arr[i] = (num>>i)&1;
	}
	int maxCount = 0;
	int count = 0;
	int zeroCount = 0;
	for (int i = 0; i < 32; i++) {
		if (arr[i] == 1) {
			count++;
		}
		else if (arr[i] == 0) {
			zeroCount++;
			if (zeroCount == 1) {
				maxCount = count;
			}
			else if (zeroCount > 1 && count > maxCount) {
				maxCount = count;
			}
			count = 0;
		}
	}
	return maxCount;
}
int main(void) {
	int t = 2;
	while(t--)
	{
		int num;
		printf("Enter a number : ");
		fflush(stdin);fflush(stdout);
		scanf("%d", &num);
		printf("output : %d\n", count_max_ones_between_two_zeros(num));
	}
	return 0;
}
