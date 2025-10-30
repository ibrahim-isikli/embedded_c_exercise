#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// base interface 
typedef struct Shape Shape;

// vtable
typedef struct
{
    double (*get_area)(Shape *self);
    double (*get_perimeter)(Shape *self);
    void (*print)(Shape *self);

} ShapeVTable;


// base struct
struct Shape
{
    const ShapeVTable *vptr;
    const char *name;
};


// wrappers
double shape_get_area(Shape *s)
{
    s->vptr->get_area(s);
}

double shape_get_perimeter(Shape *s)
{
    s->vptr->get_perimeter(s);
}

void shape_print(Shape *s)
{
    s->vptr->print(s);
}

// -- subtypes

// circle
typedef struct
{
    /* data */
};


int main(void)
{

    return 0;
}