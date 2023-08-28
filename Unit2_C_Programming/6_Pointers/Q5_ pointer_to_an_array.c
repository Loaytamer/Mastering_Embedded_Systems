/*
 ============================================================================
 Name        : Q5_.c
 Author      : Loay Tamer Mohamed
 Description : C program to show a pointer to an array which contents
			   are pointer to structure.
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct employee
{
	char* empname;
	int id;
};

int main(void) {
	struct employee emp1 = {"John",1001}, emp2 = {"Alex", 1002}, emp3 = {"Taylor", 1003};
	struct employee (*arr[]) = {&emp1, &emp2, &emp3};
	struct employee (*(*pt)[3]) = &arr;
	printf("Exmployee Name : %s\nExmployee ID : %d", (**(*pt+1)).empname, (**(*pt+1)).id);
	return 0;
}
