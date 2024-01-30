#include "fifo.h"

E_buff_status_t fifo_init(sFIFO_buff_t *pSFIFO, Sstudent_t *Buffer, uint32_t buffLength)
{
    if (!Buffer)
        return FIFO_null;

    pSFIFO->base = Buffer;
    pSFIFO->head = Buffer;
    pSFIFO->tail = Buffer;
    pSFIFO->length = buffLength;
    pSFIFO->count = 0;
    return FIFO_no_error;
}

E_buff_status_t fifo_enqueue(sFIFO_buff_t *pSFIFO)
{
    if (fifo_status(pSFIFO) == FIFO_full)
        return FIFO_full;
    else if (fifo_status(pSFIFO) == FIFO_null)
        return FIFO_null;
    else
    {
        if (pSFIFO->tail != pSFIFO->base)
            pSFIFO->head = pSFIFO->base;
        else
            pSFIFO->head++;
        pSFIFO->count++;
    }
    return FIFO_no_error;
}

E_buff_status_t fifo_dequeue(sFIFO_buff_t *pSFIFO)
{
    if (fifo_status(pSFIFO) == FIFO_null)
        return FIFO_null;

    if (!pSFIFO->count)
        return FIFO_empty;

    pSFIFO->tail++;
    pSFIFO->count--;
    return FIFO_no_error;
}

E_buff_status_t fifo_status(sFIFO_buff_t *pSFIFO)
{
    if (!pSFIFO->base || !pSFIFO->head || !pSFIFO->tail)
        return FIFO_null;

    if (pSFIFO->count == pSFIFO->length)
        return FIFO_full;

    if (!pSFIFO->count)
        return FIFO_empty;

    return FIFO_no_error;
}

void info(sFIFO_buff_t *pSFIFO, int id)
{
    switch (id)
    {
    case 1:
        printf("\n[INFO] Student details are added successfully\n");
        printf("----------------------\n");
        printf("[INFO] You can add up to %d students\n", size);
        printf("[INFO] You can add %d more students\n", (pSFIFO->length - pSFIFO->count));
        break;

    default:
        printf("[INFO] The Roll Number was removed successfully\n");
        printf("----------------------\n");
        break;
    }
}

Sstudent_t *check_roll(sFIFO_buff_t *pSFIFO, int num)
{
    int i, j;
    Sstudent_t *temp = pSFIFO->base;

    for (i = 0; i < pSFIFO->count; i++)
    {
        if (temp->rollNum == num)
            return temp;

        temp++;
    }

    return 0;
}

void add_student_manually(sFIFO_buff_t *pSFIFO)
{
    if (fifo_status(pSFIFO) == FIFO_full)
        printf("\n[FIFO_FULL] You can't add more students\n");

    else
    {
        int i;
        printf("----------------------\n");
        printf("Add the students details\n");
        printf("\nEnter the Roll Number: ");
        scanf("%d", &pSFIFO->head->rollNum);

        if (!check_roll(pSFIFO, pSFIFO->head->rollNum))
        {
            printf("\nEnter the First Name of student: ");
            scanf("%s", pSFIFO->head->firstName);
            printf("\nEnter the Last Name of student: ");
            scanf("%s", pSFIFO->head->lastName);
            printf("\nEnter the GPA you obtained: ");
            scanf("%f", &pSFIFO->head->gpa);
            printf("\nEnter the course ID of each course\n");
            for (i = 0; i < cNum; i++)
            {
                printf("\nCourse %d ID: ", i + 1);
                scanf("%d", &pSFIFO->head->courses[i]);
            }
            fifo_enqueue(pSFIFO);
            info(pSFIFO, 1);
        }
        else
        {
            printf("[ERROR] Roll Number %d is already taken\n", pSFIFO->head->rollNum);
        }
    }
}

void add_student_file(sFIFO_buff_t *pSFIFO)
{
    int i, num;
    char ch[50];
    FILE *text = fopen("data.txt", "r");
    char *line = NULL;
    int line_buf_size = 0;

    if (!text)
    {
        printf("\nText File doesn't exist!");
    }

    else
    {

        while (!feof(text))
        {

            fscanf(text, "%d", &pSFIFO->head->rollNum);
            if (check_roll(pSFIFO, pSFIFO->head->rollNum))
            {
                printf("\n[ERRPR] Roll Number %d is already taken\n", pSFIFO->head->rollNum);

                fscanf(text, "%*[^\n]");
                continue;
            }
            fscanf(text, "%s", pSFIFO->head->firstName);
            fscanf(text, "%s", pSFIFO->head->lastName);
            fscanf(text, "%f", &pSFIFO->head->gpa);

            for (i = 0; i < cNum; i++)
            {
                fscanf(text, "%d", &pSFIFO->head->courses[i]);
            }
            fifo_enqueue(pSFIFO);
            info(pSFIFO, 1);
        }
        fclose(text);
    }
}

int find_roll_num(sFIFO_buff_t *pSFIFO)
{
    int num, i, j;

    printf("\nEnter the Roll Number of the student: ");
    scanf("%d", &num);
    Sstudent_t *temp = check_roll(pSFIFO, num);
    if (temp)
    {
        printf("The students details are:\n");
        printf("\nThe first name is %s", temp->firstName);
        printf("\nThe last name is %s", temp->lastName);
        printf("\nThe GPA is %.2f", temp->gpa);
        printf("\nThe course ID of each course is\n");
        for (j = 0; j < cNum; j++)
            printf("Course %d ID: %d\n", j + 1, temp->courses[j]);

        return 1;
    }

    printf("[ERROR] Roll Number %d was not found\n", num);
    return 0;
}

int find_first_name(sFIFO_buff_t *pSFIFO)
{
    int i, j;
    char name[50];
    Sstudent_t *temp = pSFIFO->base;
    printf("\nEnter the First Name of the student: ");
    scanf("%s", name);
    for (i = 0; i < size; i++)
    {
        if (!stricmp(temp->firstName, name))
        {
            printf("The students details are:\n");
            printf("\nThe first name is %s", temp->firstName);
            printf("\nThe last name is %s", temp->lastName);
            printf("\nThe GPA is %.2f", temp->gpa);
            printf("\nThe course ID of each course is\n");
            for (j = 0; j < cNum; j++)
                printf("Course %d ID: %d\n", j + 1, temp->courses[j]);
            return 1; // found
        }
        temp++;
    }
    printf("[ERROR] First Name %s was not found\n", name);
    return 0; // not found
}
void find_course(sFIFO_buff_t *pSFIFO)
{
    int id, i, j, k, flag = 0;
    Sstudent_t *temp = pSFIFO->base;
    printf("\nEnter the Course ID: ");
    scanf("%d", &id);
    for (i = 0; i < pSFIFO->count; i++)
    {
        for (j = 0; j < cNum; j++)
        {
            if (temp->courses[j] == id)
            {
                printf("The students details are:\n");
                printf("\nThe first name is %s", temp->firstName);
                printf("\nThe last name is %s", temp->lastName);
                printf("\nThe GPA is %.2f", temp->gpa);
                printf("\nThe course ID of each course is\n");
                for (k = 0; k < cNum; k++)
                    printf("Course %d ID: %d\n", k + 1, temp->courses[k]);
                flag++;
            }
        }
        temp++;
    }
    if (!flag)
        printf("[ERROR] Course ID %d was not found\n", id);
}

void find_total_students(sFIFO_buff_t *pSFIFO)
{
    printf("[INFO] The total number of students is %d\n", pSFIFO->count);
    printf("[INFO] You can add up to %d students\n", size);
    printf("[INFO] You can add %d more students\n", (pSFIFO->length - pSFIFO->count));
}
void delete_student(sFIFO_buff_t *pSFIFO)
{
    int num, i;
    printf("\nEnter the Roll Number that you want to delete: ");
    scanf("%d", &num);
    Sstudent_t *temp = check_roll(pSFIFO, num);
    if (temp)
    {
        fifo_dequeue(pSFIFO);
        info(pSFIFO, 0);
    }
    else
        printf("[ERROR] The Roll Number %d was not found\n", num);
}

void update_student(sFIFO_buff_t *pSFIFO)
{
    int num, option, i;
    printf("\nEnter the Roll Number to update the entry: ");
    scanf("%d", &num);
    Sstudent_t *temp = check_roll(pSFIFO, num);
    if (temp)
    {
        printf("\n1. First Name");
        printf("\n2. Last Name");
        printf("\n3. Roll Number");
        printf("\n4. GPA");
        printf("\n5. Courses\n");
        scanf("%d", &option);

        switch (option)
        {
        case 1:
            printf("\nEnter the new First Name: ");
            scanf("%s", temp->firstName);
            break;
        case 2:
            printf("\nEnter the new Last Name: ");
            scanf("%s", temp->lastName);
            break;
        case 3:
            printf("\nEnter the new Roll Number: ");
            scanf("%d", &temp->rollNum);
            break;
        case 4:
            printf("\nEnter the new GPA: ");
            scanf("%d", &temp->gpa);
            break;
        case 5:
            printf("\nEnter the new Course ID");
            for (i = 0; i < cNum; i++)
            {
                printf("\nCourse %d ID: ", i + 1);
                scanf("%d", &temp->courses[i]);
            }
            break;
        default:
            printf("\nError! Wrong choice!");
            break;
        }
    }

    else
        printf("[ERROR] Roll Number %d was not found\n", num);
}

void show_all(sFIFO_buff_t *pSFIFO)
{
    Sstudent_t *temp = pSFIFO->base;
    int i, j;
    if (!pSFIFO->count)
        printf("\nThe list is empty!\n");

    else
    {
        for (i = 0; i < pSFIFO->count; i++)
        {
            printf("\nThe students details are:\n");
            printf("\nThe first name is %s", temp->firstName);
            printf("\nThe last name is %s", temp->lastName);
            printf("\nThe roll number is %d", temp->rollNum);
            printf("\nThe GPA is %.2f", temp->gpa);

            printf("\nThe course ID of each course is\n");
            for (j = 0; j < cNum; j++)
                printf("Course %d ID: %d\n", j + 1, temp->courses[j]);
            temp++;
        }
    }
}
