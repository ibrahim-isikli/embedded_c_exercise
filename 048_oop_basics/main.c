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


/*----------- circle --------------*/
typedef struct
{
    Shape base;
    double radius;
}Circle;

// methods of circle
double circle_get_area(Shape *s)
{
    Circle *c = (Circle*)s;
    return (3.14f * c->radius * c->radius);
}

double circle_get_perimeter(Shape *s)
{
    Circle *c = (Circle*)s;
    return (2 * 3.14f * c->radius);
}

void circle_print(Shape *s)
{
    Circle *c = (Circle*)s;
    printf("[Circle %s] r = %.2f area = %.2f peri=%.2f\n ",c->base.name,c->radius,,circle_get_area(s),circle_get_perimeter(s));
}

// circle vtable (one of copy)
const ShapeVTable circle_vtable = 
{
    .get_area = circle_get_area,
    .get_perimeter = circle_get_perimeter,
    .print = circle_print
};  


// circle maker
void circle_init(Circle *c, const char *name, double r)
{
    c->base.vptr = &circle_vtable;
    c->base.name = name;
    c->radius = r;
}

/*----------- square --------------*/
typedef struct 
{
    Shape base;
    double side;
}Square;








int main(void)
{

    return 0;
}