#include "sensor.h"
#include <stdio.h>
#include <stdlib.h>

// ----------------             ------------------
// ---------------- REAL HW API ------------------
// ----------------             ------------------

typedef struct 
{
    sensor_t base;
}hw_sensor_t;

static sensor_status_t hw_read(sensor_t *self, float *out)
{
    (void)self;
    *out = 24.32; // example adc value
    printf("[HW] sensor read -> %.2f C\n",*out);
    return SENSOR_OK;
}

// create vtable for hw's API
static const sensor_vtbl_t hw_vtbl = 
{
    .read = hw_read
};

sensor_t *sensor_hw_create(void)
{
    hw_sensor_t *s = malloc(sizeof(hw_sensor_t));
    if(!s)
        return NULL;
    
    s->base.vptr = &hw_vtbl;
    
    return (sensor_t*)s;
}


// ----------------             ------------------
// ---------------- TEST HW API ------------------
// ----------------             ------------------



typedef struct 
{
  sensor_t base;
  float fixed_value;  
}fake_sensor_t;

static sensor_status_t fake_read(sensor_t *self, float *out)
{
    fake_sensor_t *f = (fake_sensor_t*)self;
    *out = f->fixed_value;
    printf("[FAKE] returning %.2fC",*out);
    return SENSOR_OK;
}

static const sensor_vtbl_t fake_vtbl =
{
    .read = fake_read
};

sensor_t *sensor_fake_create(float fixed_value)
{
    fake_sensor_t *f = malloc(sizeof(fake_sensor_t));
    
    if(!f)
        return NULL;

    f->base.vptr = &fake_vtbl;
    f->fixed_value = fixed_value;
    return (sensor_t*)f;
}

// ----------------             ------------------
// ---------------- GLOBAL API ------------------
// ----------------             ------------------

void sensor_destroy(sensor_t *s)
{
    free(s);
}