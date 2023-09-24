/*
 ============================================================================
 Name        : student_database.c
 Author      : Loay Tamer Mohamed
 Description : create student database system using linked list
 ============================================================================
 */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "stdint.h"
#define Dprintf(...) {fflush(stdout);fflush(stdin);\
		printf(__VA_ARGS__);\
		fflush(stdout);fflush(stdin);}

struct Sdata{
	int id;
	char name[40];
	float height;
};

struct Sstudent{
	struct Sdata Student;
	struct Sstudent* pNextStudent;
};

struct Sstudent* gpFirstStudent = NULL;

// Add new student
void addStudent()
{
	struct Sstudent* newStudent;
	char text_temp[40];
	newStudent = (struct Sstudent*) malloc(sizeof(struct Sstudent));
	Dprintf("Enter student id: ");
	gets(text_temp);
	newStudent->Student.id = atoi(text_temp);
	Dprintf("Enter student name: ");
	gets(newStudent->Student.name);
	Dprintf("Enter student height: ");
	gets(text_temp);
	newStudent->Student.height = atof(text_temp);
	newStudent->pNextStudent = NULL;
	if(!gpFirstStudent)
	{
		// list is empty
		gpFirstStudent = newStudent;
	}
	else
	{
		//list is not empty
		struct Sstudent* lastStudent;
		lastStudent = gpFirstStudent;
		while(lastStudent->pNextStudent)
		{
			lastStudent = lastStudent->pNextStudent;
		}
		lastStudent->pNextStudent = newStudent;
	}
}

//Remove student with specific id
void deleteStudent()
{
	char text_temp[40];
	Dprintf("Enter id of student to be deleted : ");
	gets(text_temp);
	int id_temp;
	id_temp = atoi(text_temp);
	struct Sstudent* selectedStudent;
	struct Sstudent* prevStudent;
	selectedStudent = gpFirstStudent;
	prevStudent = gpFirstStudent;
	if(!gpFirstStudent)
	{
		Dprintf("Empty List");
	}
	else
	{
		while(selectedStudent)
		{
			if(selectedStudent->Student.id == id_temp)
			{
				if(selectedStudent == gpFirstStudent)
					gpFirstStudent = selectedStudent->pNextStudent;
				else
				{
					prevStudent->pNextStudent = selectedStudent->pNextStudent;
					free(selectedStudent);
				}
			}
			else
			{
				prevStudent = selectedStudent;
				selectedStudent = selectedStudent->pNextStudent;
			}
		}
	}
}

//delete all students
void deleteAll()
{
	struct Sstudent* crrentStudent;
	struct Sstudent* tempStudent;
	crrentStudent = gpFirstStudent;
	tempStudent   = gpFirstStudent;
	if(!gpFirstStudent)
	{
		Dprintf("Empty List\n");
	}
	while(crrentStudent)
	{
		tempStudent   = crrentStudent;
		crrentStudent = crrentStudent->pNextStudent;
		free(tempStudent);
	}
	gpFirstStudent =NULL;
}

// get length of the list
int getLength()
{
	if(!gpFirstStudent)
	{
		return 0;
	}
	else
	{
		struct Sstudent* selectedStudent;
		selectedStudent = gpFirstStudent;
		int count = 0;
		while(selectedStudent)
		{
			count++;
			selectedStudent = selectedStudent->pNextStudent;
		}
		return count;
	}
}

//get count using recrsion
int getCount(struct Sstudent* head)
{
	if(head == NULL)
	{
		return 0;
	}
	else
	{
		return 1 + getCount(head->pNextStudent);
	}
}

void getNth()
{
	if(!gpFirstStudent)
	{
		Dprintf("Empty List\n");
	}
	else
	{
		Dprintf("Enter id of student to be deleted : ");
		char text_temp[40];
		gets(text_temp);
		int id_temp = atoi(text_temp), count = 0;
		struct Sstudent* selectedStudent;
		selectedStudent = gpFirstStudent;
		while(selectedStudent)
		{
			if(count > getLength())
			{
				Dprintf("student not found.");
			}
			else if(selectedStudent->Student.id == id_temp)
			{
				Dprintf("student found at node %d\n", count+1);
				break;
			}
			else
			{
				count++;
				selectedStudent = selectedStudent->pNextStudent;
			}
		}
	}
}

//find nth node from end
void find_from_end()
{
	struct Sstudent* mainStudent;
	struct Sstudent* refStudent;
	mainStudent = gpFirstStudent;
	refStudent = gpFirstStudent;
	int count = 0, diff=0;
	if(!gpFirstStudent)
	{
		Dprintf("Empty List\n");
	}
	else
	{
		while(refStudent)
		{
			count++;
			refStudent = refStudent->pNextStudent;
		}
		Dprintf("Enter no of stdent from end: ");
		char text_temp[40];
		gets(text_temp);
		diff = atoi(text_temp);
		while(diff < count)
		{
			mainStudent = mainStudent->pNextStudent;
			count--;
		}
		Dprintf("Student Name : %s\n", mainStudent->Student.name);
	}
}


// print data of all students
void viewStudents()
{
	struct Sstudent* tempStudent;
	tempStudent = gpFirstStudent;
	if(!gpFirstStudent)
	{
		Dprintf("Empty List\n");
	}
	else
	{
		int count = 0;
		while(tempStudent)
		{
			Dprintf("\tRecord number %d\n", count+1);
			count++;
			Dprintf("ID : %d\n", tempStudent->Student.id);
			Dprintf("Name : %s\n", tempStudent->Student.name);
			Dprintf("Height : %.2f\n", tempStudent->Student.height);
			tempStudent = tempStudent->pNextStudent;
		}
	}
}
int main(void) {

	char text_temp[40];
	int option;
	while(1)
	{
		Dprintf("====================================\n");
		Dprintf("\tchoose one of the following options\n");
		Dprintf("1: Add Student\n");
		Dprintf("2: Delete Student\n");
		Dprintf("3: View Students\n");
		Dprintf("4: Delete All\n");
		Dprintf("5: Get Length\n");
		Dprintf("6: GetNth\n");
		Dprintf("7: Find student from end\n");
		Dprintf("8: Exit\n")
		Dprintf("Enter option Number: ");
		gets(text_temp);
		option = atoi(text_temp);
		Dprintf("\n====================================\n");
		switch(option)
		{
		case 1: addStudent();
		break;
		case 2: deleteStudent();
		break;
		case 3: viewStudents();
		break;
		case 4: deleteAll();
		break;
		case 5: Dprintf("List have %d students.\n", getCount(gpFirstStudent));
		break;
		case 6: getNth();
		break;
		case 7: find_from_end();
		break;
		case 8: Dprintf("Bye Bye\n");
		break;
		default: Dprintf("Wrong Option!\n");
		}
	}
	return 0;
}
