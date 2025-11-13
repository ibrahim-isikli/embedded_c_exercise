#include "sensor.h"
#include <stdio.h>

int main(void)
{
    sensor_t *s1 = sensor_hw_create();
    sensor_t *s2 = sensor_fake_create(42.0f);

    float val;

    s1->vptr->read(s1, &val);
    printf("App got: %.2f\n", val);

    s2->vptr->read(s2, &val);
    printf("App got: %.2f\n", val);

    sensor_destroy(s1);
    sensor_destroy(s2);
    return 0;
}
