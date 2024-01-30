#include "stdio.h"
#include "stdint.h"
#include "string.h"

#ifndef FIFO_H_
#define FIFO_H_


// total number of students
#define size 50
// number of courses
#define cNum 5

typedef struct
{
    char firstName[50];
    char lastName[50];
    int rollNum;
    float gpa;
    int courses[cNum];

} Sstudent_t;

typedef struct
{
    Sstudent_t *base;
    Sstudent_t *head;
    Sstudent_t *tail;
    uint32_t length;
    uint32_t count;

} sFIFO_buff_t;

typedef enum
{
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_null,
} E_buff_status_t;

E_buff_status_t fifo_init(sFIFO_buff_t *pSFIFO, Sstudent_t *Buffer, uint32_t buffLength);
E_buff_status_t fifo_enqueue(sFIFO_buff_t *pSFIFO);
E_buff_status_t fifo_dequeue(sFIFO_buff_t *pSFIFO);
E_buff_status_t fifo_status(sFIFO_buff_t *pSFIFO);

void info(sFIFO_buff_t *pSFIFO, int id);
Sstudent_t *check_roll(sFIFO_buff_t *pSFIFO, int num);
void add_student_manually(sFIFO_buff_t *pSFIFO);
void add_student_file(sFIFO_buff_t *pSFIFO);
int find_roll_num(sFIFO_buff_t *pSFIFO);
int find_first_name(sFIFO_buff_t *pSFIFO);
void find_course(sFIFO_buff_t *pSFIFO);
void find_total_students(sFIFO_buff_t *pSFIFO);
void delete_student(sFIFO_buff_t *pSFIFO);
void update_student(sFIFO_buff_t *pSFIFO);
void show_all(sFIFO_buff_t *pSFIFO);

#endif
