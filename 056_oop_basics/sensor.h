#ifndef SENSOR_H
#define SENSOR_H

// encapsulation both of side (sensor and vtable of sensor)
typedef struct sensor sensor_t;
typedef struct sensor_vtbl sensor_vtbl_t;

typedef enum
{
    SENSOR_OK = 0,
    SENSOR_ERR_IO
}sensor_status_t;

// vtable
struct sensor
{
    const sensor_vtbl_t *vptr;
};

struct  sensor_vtbl
{
    sensor_status_t (*read)(sensor_t *self, float *out);
};

// GLOBAL API's Funcs
sensor_t *sensor_hw_create(void);
sensor_t *sensor_fake_create(float fixed_value);
void      sensor_destroy(sensor_t *s);


#endif