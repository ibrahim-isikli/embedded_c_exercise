#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef union 
{
    struct
    {
        //byte 0
        uint8_t en          : 1; //bit 0
        uint8_t cfg         : 1; //bit 1
        uint8_t mode        : 2;
        uint8_t int_flag    : 4;

        // byte 1
        uint8_t cntrl       : 2;
        uint8_t wake_up     : 4;
        uint8_t state       : 1;
        uint8_t comp_flag   : 1; //bit 15

    }bits;

    uint16_t my_reg;

}control_reg_td;


int main(void)
{
    control_reg_td control_register;
    control_register.my_reg = 0x2359;
    printf("\n bits \n\n");
    printf("en           : %d\n",control_register.bits.en);
    printf("cfg          : %d\n",control_register.bits.cfg);
    printf("mode         : %d\n",control_register.bits.mode);
    printf("int_flag     : %d\n",control_register.bits.int_flag);
    printf("cntrl        : %d\n",control_register.bits.cntrl);
    printf("wake_up      : %d\n",control_register.bits.wake_up);
    printf("state        : %d\n",control_register.bits.state);
    printf("comp_flag    : %d\n",control_register.bits.comp_flag);
    return 0;
}