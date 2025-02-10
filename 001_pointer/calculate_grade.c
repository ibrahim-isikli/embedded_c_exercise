
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include "calculate_grade.h"

void inputGrades(float *grades, int size)
{   
    for(uint8_t i = 0; i<size; i++)
    {
        printf("Please enter the grade for student %d: ", i+1);
        scanf("%f",&grades[i]);
    }

}


void printGrades(float *grades, int size)
{
    printf("\nStudent grades: \n");
    for(uint8_t i = 0; i<size; i++)
    {
        printf("[%d] -> %.2f \n",i+1,*(grades + i)); // acces with pointer
    }
    printf("\n");
}

float calculateAverage(float *grades, int size)
{
    float sum = 0.00;
    for(uint8_t i=0; i<size; i++)
    {
        sum += *(grades+i);
    }

    return (sum/size);
}

float findMaxGrade(float *grades, int size)
{
    float max = *grades;
    for(uint8_t i=1; i<size; i++)
    {
        if(*(grades+i) > max)
        {
            max = *(grades+i);
        }
    }
    return max;
}