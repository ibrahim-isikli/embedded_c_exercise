#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// homework : add triangle

// base interface 
typedef struct Shape Shape;

// vtable
typedef struct
{
    double (*get_area)(Shape *self);
    double (*get_perimeter)(Shape *self);
    void (*print)(Shape *self);
    void (*to_string)(Shape *self, char *buf, size_t len);

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
    // old version
    //s->vptr->print(s);
    
    // abstract version
    char buff[128];
    s->vptr->to_string(s,buff,sizeof(buff));
    printf("%s\n",buff);

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

void circle_to_string(Shape *s, char *buff, size_t len)
{
    Circle *c = (Circle*)s;
    snprintf(buff,len,"[Circle %s] r = %.2f area = %.2f peri=%.2f",c->base.name,c->radius,circle_get_area(s),circle_get_perimeter(s));

}

void circle_print(Shape *s)
{
    Circle *c = (Circle*)s;
    printf("[Circle %s] r = %.2f area = %.2f peri=%.2f\n ",c->base.name,c->radius,circle_get_area(s),circle_get_perimeter(s));
}

// circle vtable (one of copy)
const ShapeVTable circle_vtable = 
{
    .get_area = circle_get_area,
    .get_perimeter = circle_get_perimeter,
    .print = circle_print,
    .to_string = circle_to_string
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
// methods of square
double square_get_area(Shape *s)
{
    Square *sq = (Square*)s;
    return sq->side * sq->side;
}

double square_get_perimeter(Shape *s)
{
    Square *sq = (Square*)s;
    return sq->side * 4;
}

void square_to_string(Shape *s, char *buff, size_t len)
{
    Square *sq = (Square*)s;
    snprintf(buff,len,"[Square '%s'] side = %.2f area = %.2f perimeter = %.2f",sq->base.name,sq->side,square_get_area(s),square_get_perimeter(s));
}

void square_print(Shape *s)
{
    Square *sq = (Square*)s;
    printf("[Square '%s'] side = %.2f area = %.2f perimeter = %.2f\n",sq->base.name,sq->side,square_get_area(s),square_get_perimeter(s));
}

// square vector table
const ShapeVTable square_vtable =
{
    .get_area = square_get_area,
    .get_perimeter = square_get_perimeter,
    .print = square_print,
    .to_string = square_to_string
};


// square maker
void square_init(Square *sq, const char *name, double side)
{
    sq->base.vptr = &square_vtable;
    sq->base.name = name;
    sq->side = side;
}

/*----------- triangle --------------*/
typedef struct
{
    Shape base;
    double side;
    double height;

}Triangle;
// methods of triangle
double triangle_get_area(Shape *t)
{
    Triangle *tg = (Triangle*)t;
    return(tg->side * tg->height /2.00f);

}

double triangle_get_perimeter(Shape *t)
{
    Triangle *tg = (Triangle*)t;
    return(tg->side*3);
}

void triangle_to_string(Shape *s, char *buff, size_t len)
{
    Triangle *t = (Triangle*)s;
    snprintf(buff,len,"[Triangle '%s'] height = %.2f area = %.2f perimeter = %.2f",t->base.name,t->height,triangle_get_area(s),triangle_get_perimeter(s));
}

void triangle_print(Shape *t)
{
    Triangle *tg = (Triangle*)t;
    printf("[Triangle '%s'] height = %.2f area = %.2f perimeter = %.2f\n",tg->base.name,tg->height,triangle_get_area(t),triangle_get_perimeter(t));
}

// triangle vector table 

const ShapeVTable triangle_vtable = 
{
    .get_area      = triangle_get_area,
    .get_perimeter = triangle_get_perimeter,
    .print         = triangle_print,
    .to_string     = triangle_to_string
};

// triangle maker
void triangle_init(Triangle *tg, const char *name, double side, double height)
{
    tg->base.vptr    = &triangle_vtable;
    tg->base.name    = name;
    tg->height       = height;
    tg->side         = side; 

}

int main(void)
{
    printf("test\ntest");
    Circle c1;
    Square s1;
    Triangle t1;

    circle_init(&c1,"circle",5.0);
    square_init(&s1,"square",3.0);
    triangle_init(&t1,"triangle",3.0,5.0);
    // polimorfic using -> same interface different behavior
    Shape *shapes [] = {(Shape*)&c1, (Shape*)&s1, (Shape*)&t1};
    for(uint8_t i=0; i<3; ++i)
        shape_print(shapes[i]);

    return 0;
}