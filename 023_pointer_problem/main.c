#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>

typedef struct 
{
    char name[50];
    int id;
    int examCount;
    float *grades;
}Student;

/*@brief get info and allocate memort for each students
*/
Student *createStudents(int numStudents)
{
    Student *students = (Student*)malloc(numStudents*(sizeof(Student)));

    // get informations for students
    printf("---------enter student's informations---------\n");
    for(uint8_t i=0; i<numStudents;i++)
    {
        printf("             [STUDENT %d]             \n",i+1);
        printf("Name:\t");;
        scanf("%s",students[i].name);
        printf("Number:\t");
        scanf("%d",&students[i].id);
        printf("Num of exam:\t");
        scanf("%d",&students[i].examCount);

        // memory allocate up to exam count
        students[i].grades = (float*)malloc(students[i].examCount*sizeof(float));
        printf("             [%s 's grades]             \n",students[i].name);
        for(uint8_t j=0; j<students[i].examCount; j++)
        {
            printf("grade[%d] :\t",j+1);
            scanf("%f",&students[i].grades[j]);
        }
    }
    printf("----------------------------------------------\n");
    return students;
}

void printStudents(Student *students, int numStudents)
{
    printf("\n\n--------------STUDENT INFORMATION SYSTEM----------------\n");
    printf("|                                                           |\n");
    for(uint8_t i=0; i<numStudents; i++)
    {
        printf("                     %s - %d - grades           \n",students[i].name,students[i].id);
        for(uint8_t j=0; j<students[i].examCount; j++)
        {
            printf("           %.2f\t",students[i].grades[j]);
        }
        printf("\n");
    }
    printf("|                                                           |\n");
    printf("--------------------------------------------------------\n\n");
}

void freeStudents(Student *students, int numStudents)
{
    for(uint8_t i=0; i<numStudents; i++)
    {
        free(students[i].grades);
    }

    free(students);
}

int main(void)
{

    int numStudents;
    printf("How many students ? :\t");
    scanf("%d",&numStudents);

    Student *students = createStudents(numStudents);
    printStudents(students,numStudents);
    freeStudents(students,numStudents);


    return 0;

}