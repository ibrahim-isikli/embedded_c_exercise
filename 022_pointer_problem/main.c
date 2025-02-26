

/*
Bir okulda her sınıfta farklı sayıda öğrenci var. Biz,
 her sınıfa farklı sayıda öğrenci ekleyip, onların yaşlarını tutacağız.
  (Pointer to Pointer ile dinamik bellek tahsisi yapacağız.)
*/

/*
    THE STRUCTURE

       PTP         PTP        PTP                      MAIN POINTER (POINTER TO POINTER)
        |           |          |                       (SPACE NUM_STUDENTS) 
    [CLASS 1] [CLASS 2]    [CLASS 3]                
        |           |          |                       (SPACE EXAM COUNT)
      [EXAM1]    [EXAM1]     [EXAM1]
      [EXAM2]    [EXAM2]     [EXAM2]
      [EXAM3]                [EXAM3]
                             [EXAM4]



    PTP[i] -> student
    PTP[i][j] -> student's grade
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


int main(void)
{
    int num_classes;
    printf("enter the number of classes:\t");
    scanf("%d",&num_classes);

    int32_t **school = (int32_t**)malloc(num_classes*sizeof(int32_t*)); // main pointer (classes)

    if(school == NULL)
    {
        printf("memory allocation failed!\n");
        return -1;
    }

    // determine the number of students for each class
    int32_t *students_per_class = (int*)malloc(num_classes*sizeof(int32_t)); // students

    for(uint8_t i=0; i<num_classes; i++)
    {
        printf("how many students in the for class %d :\t",i+1);
        scanf("%d",&students_per_class[i]);

        // create an array to hold student ages for each class
         school[i] =(int*)malloc(students_per_class[i]*sizeof(int32_t));

         if(school[i] == NULL)
         {
            printf("memory allocation failed!\n");
            return -1;
         }

         // get ages
         printf("-------------|CLASS %d| ages of students-------------\n\n",i+1);
         
         for(uint8_t j=0; j<students_per_class[i]; j++)
         {
            printf("student %d. :\t",j+1);
            scanf("%d",&school[i][j]);
         }
         printf("-----------------------------------------------------\n\n",i+1);

    }


    // print ages
    printf("----------------------|INFO|----------------------\n");
    for(uint8_t i=0; i<num_classes; i++)
    {
        printf("-------[[[[[  %d class ]]]]-------\n",i+1);
        for(uint8_t j=0; j<students_per_class[i]; j++)
         {
            printf("student num: %d ages: %d\n",j+1,school[i][j]);
         }
         printf("-------------------------------------------\n");
    }


    // free memory

    for(uint8_t i=0; i<num_classes; i++)
    {
        free(school[i]);
    }

    free(school);
    free(students_per_class);


    return 0;
}