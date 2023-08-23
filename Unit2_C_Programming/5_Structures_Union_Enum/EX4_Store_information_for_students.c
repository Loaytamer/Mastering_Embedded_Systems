/*
 ============================================================================
 Name        : EX4_Store_information_for_students.c
 Author      : Loay Tamer Mohamed
 Description : C Program to Store Information of Students Using Structure
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

struct Student
{
	char name[50];
	int roll;
	int marks;
};

struct Student readData(int i)
{
	struct Student s;
	printf("For roll number %d\n", i+1);
	printf("Enter name: ");
	fflush(stdin);fflush(stdout);
	scanf("%s", &s.name);
	printf("Enter marks: ");
	fflush(stdin);fflush(stdout);
	scanf("%d", &s.marks);
	return s;
}

void display(struct Student s, int i)
{
	printf("Information for roll number %d", i+1);
	printf("Name: %s\n", s.name);
	printf("Marks: %d\n", s.marks);
}
int main(void) {
	struct Student s[10];
	printf("Enter information of students:\n");
	for(int i = 0; i < 10; i++)
	{
		s[i] = readData(i);
	}
	printf("\nDisplaying Information\n");
	for(int i = 0; i < 10; i++)
	{
		display(s[i],i);
	}
	return 0;
}
