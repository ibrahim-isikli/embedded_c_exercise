#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


void findCommonElements(int *arr1, uint8_t size1, int *arr2, uint8_t size2)
{
    uint8_t count = 0;

    int *common = (int*)malloc(sizeof(int)*size1);

    for(uint8_t i=0; i<size1; i++)
    {
        for(uint8_t j=0; j<size2; j++)
        {
            if(*(arr1+i)==*(arr2+j))
            {
                *(common+count) =*(arr1+i);
                printf("\n++\n");
                count++;
                break;
            }
        }
    }

    printf("\ncommon elements\n");

    for(uint8_t i=0; i<count; i++)
    {
        printf("%d\t",*(common+i));
    }

    printf("\n");

    free(common);

}

int main(void)
{
    uint8_t arr1Size, arr2Size;
    
    printf("arr 1 size:\t");
    scanf("%hhu",&arr1Size);

    int *arr1 = (int*)malloc(sizeof(int)*arr1Size);
    arr1 == NULL ? printf("arr1 memory allocated failed\n") : 0;

    printf("enter the elements of the first arr\n");

    for(uint8_t i=0; i<arr1Size; i++)
    {
        printf("arr1[%d]:\t",i);
        scanf("%d",(arr1+i));
    }

    printf("arr 2 size\t");
    scanf("%hhu",&arr2Size);

    int *arr2 = (int*)malloc(sizeof(int)*arr2Size);
    arr2 == NULL ? printf("arr2 memory allocated failed!\n") : 0;

    printf("enter the elements of the second arr\n");
    
    for(uint8_t i=0; i<arr2Size; i++)
    {
        printf("arr2[%d]:\t",i);
        scanf("%d",(arr2+i));
    }

    findCommonElements(arr1,arr1Size,arr2,arr2Size);

    free(arr1);
    free(arr2);

    return 0;
}
