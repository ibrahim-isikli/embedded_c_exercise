#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct 
{
    char title[100];
    float price;
}Book;



int main(void)
{
    int bookCount;

    printf("How many books do you want to add?");
    scanf("%d",&bookCount);

    Book *books = (Book*)malloc(bookCount*sizeof(Book));
    
    if(books == NULL)
    {
        printf("Memory allocation failed\n");
        return -1;
    }

    // get info of books
    for(uint8_t i=0; i<bookCount; i++)
    {
        printf("name of book %d: ",i+1);
        scanf("%s",&books[i].title);
        printf("price of book %d:",i+1);
        scanf("%f",&books[i].price);
    }


    printf("\n--------------LIBRARY--------------\n");
    for(uint8_t i=0; i<bookCount; i++)
    {
        printf("[book %d] name: %s price %.2f\n",i+1,books[i].title,books[i].price);
    }

    free(books);

    return 0;
}