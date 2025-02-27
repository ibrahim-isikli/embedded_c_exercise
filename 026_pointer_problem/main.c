#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct 
{
    char name[50];
    int age;
    int no;
}Student;


Student* addStudent(Student *students, int *size)
{
    *(size++);
    students = (Student*)realloc(students,(*size)*sizeof(Student));

    if(students == NULL)
    {
        printf("memory allocation failed!\n");
        exit(1);
    }

    printf("enter student name: ");
    scanf("%s",students[(*size)-1].name);
    printf("enter student age:  ");
    scanf("%d",&students[(*size)-1].age);
    printf("Enter student id:  ");
    scanf("%d",&students[(*size)-1].no);

    printf("+ + + student added succesfully! + + +\n");
    return students;
}


void listStudents(Student *students,int size)
{
    if(size==0)
    {
        printf("no students found\n");
        return;
    }
    else
    {
        printf("----------Student List--------------\n");
        for(uint8_t i=0; i<size; i++)
        {
            printf("ID: %d Name: %s Age: %d\n",students[i].no,students[i].name,students[i].age);
        }
        printf("\n----------------------------------\n");


    }
}


int main(void)
{

    Student *students = NULL;
    int size = 0;
    int choice;

    printf("______________________________________________________MENU______________________________________________________\n\n");
    
    do
    {
        printf("\n[1] add student\n[2] list students\n[3] exit\n\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                students = addStudent(students,&size);
                break;
            
            case 2:
                listStudents(students,size);
                break;

            case 3:
                printf("Exiting...\n");
                break;
            
            default:
                printf("Invalid option ! Try again.\n");

        }

    } while (choice !=3);
    
    free(students);
    return 0;
}