#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

uint8_t arr_u8[10];
uint16_t arr_u16[10];
uint32_t arr_u32[10];
uint64_t arr_u64[10];

int8_t arr_s8[10];
int16_t arr_s16[10];
int32_t arr_s32[10];
int64_t arr_s64[10];

int main(void) {

    printf("\n\n--sizeof--\n\n");
    printf("sizeof arr_u8  = %zu bytes, sizeof elements of array = %zu bytes\n",sizeof(arr_u8),sizeof(arr_u8[0]));
    printf("sizeof arr_u16 = %zu bytes, sizeof elements of array = %zu bytes\n",sizeof(arr_u16),sizeof(arr_u16[0]));
    printf("sizeof arr_u32 = %zu bytes, sizeof elements of array = %zu bytes\n",sizeof(arr_u32),sizeof(arr_u32[0]));
    printf("sizeof arr_u64 = %zu bytes, sizeof elements of array = %zu bytes\n",sizeof(arr_u64),sizeof(arr_u64));

    printf("sizeof arr_s8  = %zu bytes, sizeof elements of array = %zu bytes\n",sizeof(arr_s8),sizeof(arr_s8[0]));
    printf("sizeof arr_s16 = %zu bytes, sizeof elements of array = %zu bytes\n",sizeof(arr_s16),sizeof(arr_s16[0]));
    printf("sizeof arr_s32 = %zu bytes, sizeof elements of array = %zu bytes\n",sizeof(arr_s32),sizeof(arr_s32[0]));
    printf("sizeof arr_s64 = %zu bytes, sizeof elements of array = %zu bytes\n",sizeof(arr_s64),sizeof(arr_s64));


    printf("\n\n--address--\n\n");
    printf("\n\n\n");
    for(uint8_t i=0; i<(sizeof(arr_u8)/sizeof(arr_u8[0])); i++)
    {
        printf("aar_u8 [%d] ---value---> %u ---addr--->%d\n",i,*(arr_u8+i),(arr_u8+i));
    }
    printf("\n\n\n");
    for(uint8_t i=0; i<(sizeof(arr_u16)/sizeof(arr_u16[0])); i++)
    {
        printf("aar_u16 [%d] ---value---> %u ---addr--->%d\n",i,*(arr_u16+i),(arr_u16+i));
    }
    printf("\n\n\n");
    for(uint8_t i=0; i<(sizeof(arr_u32)/sizeof(arr_u32[0])); i++)
    {
        printf("aar_u32 [%d] ---value---> %u ---addr--->%d\n",i,*(arr_u32+i),(arr_u32+i));
    }
    printf("\n\n\n");
    for(uint8_t i=0; i<(sizeof(arr_u64)/sizeof(arr_u64[0])); i++)
    {
        printf("aar_u64 [%d] ---value---> %llu ---addr--->%d\n",i,*(arr_u64+i),(arr_u64+i));
    }

    printf("\n\n\n");
    for(uint8_t i=0; i<(sizeof(arr_s8)/sizeof(arr_s8[0])); i++)
    {
        printf("aar_s8 [%d] ---value---> %d ---addr--->%d\n",i,*(arr_s8+i),(arr_s8+i));
    }
    printf("\n\n\n");
    for(uint8_t i=0; i<(sizeof(arr_s16)/sizeof(arr_s16[0])); i++)
    {
        printf("aar_s16 [%d] ---value---> %d ---addr--->%d\n",i,*(arr_s16+i),(arr_s16+i));
    }
    printf("\n\n\n");
    for(uint8_t i=0; i<(sizeof(arr_s32)/sizeof(arr_s32[0])); i++)
    {
        printf("aar_s32 [%d] ---value---> %d ---addr--->%d\n",i,*(arr_s32+i),(arr_s32+i));
    }
    printf("\n\n\n");
    for(uint8_t i=0; i<(sizeof(arr_s64)/sizeof(arr_s64[0])); i++)
    {
        printf("aar_s64 [%d] ---value---> %lld ---addr--->%d\n",i,*(arr_s64+i),(arr_s64+i));
    }

    return 0;
}
