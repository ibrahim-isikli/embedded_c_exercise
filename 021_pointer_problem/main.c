/* Problem: Two-Dimensional Dynamic Array Operation

Scenario: In a classroom, each student has a different number of exams. We will write a program to store and analyze students' exam scores using dynamic memory allocation.

Requirements:

Get the number of students from the user.

Ask for the number of exam scores for each student.

Enter each student's exam scores.

Calculate and print the average score for each student.

Properly free the allocated memory. */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(void)
{
    int numberOfStudents,numberOfExams;
    printf("enter the number of students:\t");
    scanf("%d",&numberOfStudents);

    int **students = (int**)malloc(sizeof(int*)*numberOfStudents);

    if(students == NULL)
    {
        printf("memory allocation failed !\n");
        return -1;
    }

    for(int i=0; i<numberOfStudents; i++)
    {
        printf("enter the number of exam scores for each student\n\n");

        printf("enter the number of exams:\t");
        scanf("%d",&numberOfExams);

        students[i] = (int*)malloc(sizeof(int)*numberOfExams);

        if(students[i] == NULL)
        {
            printf("memory allocation failed for student %d!\n",i);
            return -1;
        }

        for(int j=0; j<numberOfExams; j++)
        {
            
            printf("STUDENT [%d] - NOTE [%d] =>\t",i+1,j+1);
            scanf("%d",&students[i][j]);
        }

    }


    // print
    for(int i =0; i<numberOfStudents; i++)
    {
        printf("--- exam scores for student %d ---\n",i);
        for(int j=0; j<numberOfExams; j++)
        {
            printf("%d\t",students[i][j]);
        }
        printf("\n");
    }

    // free
    for(int i=0; i<numberOfStudents; i++)
    {
        free(students[i]);
    }

    free(students);

    return 0;
}