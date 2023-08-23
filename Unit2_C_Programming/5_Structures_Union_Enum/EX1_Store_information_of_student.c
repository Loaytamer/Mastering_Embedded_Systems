/*
 ============================================================================
 Name        : Ex1_Store_information_of_student.c
 Author      : Loay Tamer Mohamed
 Description : C Program to Store Information(name, roll and marks) of a Student using structure
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Student
{
	char name[50];
	int roll;
	float marks;
};

struct Student readData()
{
	struct Student s;
	printf("Enter information of student:\n");
	printf("Enter name: ");
	fflush(stdin);fflush(stdout);
	scanf("%s", &s.name);
	printf("Enter roll number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &s.roll);
	printf("Enter marks: ");
	fflush(stdin);fflush(stdout);
	scanf("%f", &s.marks);
	return s;
}

void display(struct Student s)
{
	printf("\nDisplaying Information\n");
	printf("Name: %s\n", s.name);
	printf("Roll: %d\n", s.roll);
	printf("Marks: %.2f\n", s.marks);
}
int main(void) {
	struct Student s;
	s = readData();
	display(s);
	return 0;
}
