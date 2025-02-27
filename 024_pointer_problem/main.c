#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef struct
{
    char name[50];
    int age;
    float height;
}Person;

int main(void)
{

    //allocate memory
    Person *person = (Person*)malloc(sizeof(Person));

    if(person == NULL)
    {
        printf("memory allocation failed!\n");
        return -1;
    }

    printf("enter your name:");
    scanf("%s",person->name);

    printf("enter your age:");
    scanf("%d",&person->age);

    printf("enter your height:");
    scanf("%f",&person->height);

    printf("\n---------------------INFO---------------------\n");
    printf("name:\t %s\n",person->name);
    printf("age:\t %d\n",person->age);
    printf("height:\t %.2f\n",person->height);
    printf("------------------------------------------------\n");

    free(person);

    return 0;
}