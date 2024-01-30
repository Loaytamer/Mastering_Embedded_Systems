#include "fifo.h"
#include "fifo.c"

int main()
{
    sFIFO_buff_t sFIFO;
    Sstudent_t student[size];
    if (fifo_init(&sFIFO, student, size) == FIFO_no_error)
    {

        int option;
        printf("Welcome to the Student Management System\n");
        while (1)
        {
            printf("----------------------\n");
            printf("Choose the task that you want to perform\n");
            printf("----------------------\n");
            printf("1. Add the student details manually\n");
            printf("2. Add the student details from text file\n");
            printf("3. Find the student details by roll number\n");
            printf("4. Find the student details by first name\n");
            printf("5. Find the student details by course ID\n");
            printf("6. Find the total number of students\n");
            printf("7. Delete the students details by roll number\n");
            printf("8. Update the students details by roll number\n");
            printf("9. Show all intofrmation\n");
            printf("10. Exit\n");
            printf("----------------------\n");
            printf("\nEnter your choice to perform the task:\n");

            scanf("%d", &option);

            switch (option)
            {
            case 1:
                add_student_manually(&sFIFO);
                break;
            case 2:
                add_student_file(&sFIFO);
                break;
            case 3:
                find_roll_num(&sFIFO);
                break;
            case 4:
                find_first_name(&sFIFO);
                break;
            case 5:
                find_course(&sFIFO);
                break;
            case 6:
                find_total_students(&sFIFO);
                break;
            case 7:
                delete_student(&sFIFO);
                break;
            case 8:
                update_student(&sFIFO);
                break;
            case 9:
                show_all(&sFIFO);
                break;
            case 10:
                return 0;
            default:
                printf("Error! Wrong choice!");
                break;
            }
        }
    }
    else
        printf("fifo init failed");

    return 0;
}
