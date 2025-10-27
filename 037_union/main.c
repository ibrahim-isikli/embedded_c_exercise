#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

union data_parser 
{
    uint32_t raw_data;
    uint8_t  data_of_bytes[4];
};

union IntBytes 
{
    unsigned int value;
    unsigned char bytes[4];
};

int main(void)
{
    union data_parser data;
    data.raw_data = 0x12345678;
    printf("raw data 0x%x\n",data.raw_data);

    for(uint8_t i=0; i<4; i++)
        printf("byte %d 0x%x\n",i,data.data_of_bytes[i]);
        
    union IntBytes data2;
    data2.value = 0x12345678;

    printf("bytes: %02X %02X %02X %02X\n",
    data2.bytes[0], data2.bytes[1], data2.bytes[2], data2.bytes[3]);
    return 0;
}