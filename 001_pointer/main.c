#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "calculate_grade.h"


int main() {
    int numStudents;
    printf("enter the number of students: \t");
    scanf("%d",&numStudents);

    // lets allocate dynamic memory 
    float *grades = (float*)malloc(numStudents*sizeof(float));

    if(grades == NULL)
    {
        printf("memory allocation failed!\n");
        return 1;
    }

    // get grades
    inputGrades(grades,numStudents);

    // print grades
    printGrades(grades,numStudents);

    // calculate the average
    float avg = calculateAverage(grades, numStudents);
    printf("\nAverage grade: %.2f\n",avg);

    // find the max grade
    float maxGrade = findMaxGrade(grades,numStudents);
    printf("\nMax grade: %.2f\n",maxGrade);

    // memory free
    free(grades);

}

