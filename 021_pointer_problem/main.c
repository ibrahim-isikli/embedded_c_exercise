#include <stdio.h>
#include <stdlib.h>
/* Problem: Two-Dimensional Dynamic Array Operation

Scenario: In a classroom, each student has a different number of exams. We will write a program to store and analyze students' exam scores using dynamic memory allocation.

Requirements:

Get the number of students from the user.

Ask for the number of exam scores for each student.

Enter each student's exam scores.

Calculate and print the average score for each student.

Properly free the allocated memory. */

/*
    THE STRUCTURE

       PTP         PTP        PTP                      MAIN POINTER (POINTER TO POINTER)
        |           |          |                       (SPACE NUM_STUDENTS) 
    [STUDENT 1] [STUDENT 2] [STUDENT 3]                
        |           |          |                       (SPACE EXAM COUNT)
      [EXAM1]    [EXAM1]     [EXAM1]
      [EXAM2]    [EXAM2]     [EXAM2]
      [EXAM3]                [EXAM3]
                             [EXAM4]



    PTP[i] -> student
    PTP[i][j] -> student's grade
*/


int main(void) 
{

    int num_students;

    printf("enter the num of students:\t");
    scanf("%d",&num_students); // example num_students = 3

    int **grades = (int**)malloc(num_students*sizeof(int*));  // 3 ptp [student 1] [student 2] [student 3]
    int *exam_count =  (int*)malloc(num_students*sizeof(int));  // Has [student 1] How many exam ?

    if((grades == NULL) || (exam_count == NULL))
    {
        printf("mem allocation failed!\n");
        return -1;
    }

    // get exam_count and grades for each studens
    for(int i=0; i<num_students; i++)
    {
        printf("How many exams did the student take ?\n"); 
        scanf("%d",&exam_count[i]);
        // memory allocate up to number of exams
        grades[i] = (int*)malloc(exam_count[i]*sizeof(int));

        if(grades[i] == NULL)
        {
            printf("memory allocation failed!\n");
            return -1;
        }

        // enter the grades for each students
        for(int j=0; j<exam_count[i]; j++)
        {
            printf("|Student %d| Grade[%d] |\t",i+1,j+1);
            scanf("%d",&grades[i][j]);
        }

    }

    // calculete average of grades for each student
    printf("\naverage of grades\n");
    for(int i=0; i<num_students; i++)
    {
        int sum = 0;
        for(int j=0; j<exam_count[i]; j++)
        {
            sum+=grades[i][j];
        }
        printf("|Student %d| Average[%.2f] |\t",i+1,(double)sum/exam_count[i]);

    }
    

    // free memory

    for(int i=0; i<num_students; i++)
    {
        free(grades[i]);
    }

    free(grades);
    free(exam_count);


    return 0;
}
