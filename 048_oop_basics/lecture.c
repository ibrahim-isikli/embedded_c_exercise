//////////// Adım 4 — VTable (Virtual Table) ve Polimorfizm //////////////////////////

// Amaç

/*
 Bir arayüz üzerinden (ör:shape) farklı türlerin (circle, square) kendine özgü davranış göstermesini sağlamak.
 Yani "hangi tür olduğunu bilmeden ortak fonksiyonları çağırabilmek"
*/

// Neden ?

/*
 C dilinde her struct'ın metotları farklıdır. Ama bazen elimizde birden fazla benzer struct olur.
 Örneğin UART_driver,SPI_Driver,I2C_driver ya da Circle, Square, Triangle 
 Bu türlerin hepsi aynı işi yapar. Örn: init(), write(), get_area()
 ama her biri farklı şekilde uygular

 Biz bu farklılıkla if-else zinciri yazmadan başa çıkmak isteriz

 Yani 

 if(share_type == CIRCLE)
    area = circle_area(c);
 else if(share_type == SQUARE)
    area = square_area(s)


 Yerine
 
  area = shape_get_area(shape);

  demek isteriz. VTable'da tam dda bu "hangi fonksiyon çağırılacak ? " bilgisini çözer.
 
*/

// Nasıl Çalışır ?

/*
 Her nesnenin (shape) içinde bir vptr vardırç Bu fonksiyon adreslerini tutan VTable'a işaret eder.

 Shape
 ├─ name
 └─ vptr → [get_area, get_perimeter, print]

 Circle oluşturulduğunda vptr’ı Circle_vtable’a bağlarız.
 Square oluşturulduğunda Square_vtable’a bağlarız.

 Artık Shape_get_area() çağrıldığında derleyici bilmez ama program “vptr” üzerinden doğru fonksiyonu bulur:
 
 return s->vptr->get_area(s);

Yani bu satır “hangi struct olursa olsun” doğru davranışı çağırır.
İşte bu: run-time polymorphism.


*/

// Kavramlar 

/*
| Kavram                       | Açıklama                                                                                                |
| ---------------------------- | ------------------------------------------------------------------------------------------------------- |
| **VTable (Virtual Table)**   | Fonksiyon pointer’larından oluşan bir tablo. Her tür (örneğin Circle, Square) kendi tablosunu tanımlar. |
| **Base Struct (üst tip)**    | Ortak alanları ve `vtable` pointer’ını içerir. (ör. `Shape`)                                            |
| **Derived Struct (alt tip)** | Base struct’ı içerir (`Shape base;`) ve kendine özgü veri/fonksiyonları vardır.                         |
| **Polimorfizm**              | Aynı arayüz (ör. `Shape_print()`) → farklı davranış (Circle için farklı, Square için farklı).           |

*/


#include <stdio.h>
#include <math.h>

/* ====================== */
/* 1) Ortak Arayüz (base) */
/* ====================== */
typedef struct Shape Shape;

/* vtable yapısı: fonksiyon imzaları */
typedef struct {
    double (*get_area)(Shape *self);
    double (*get_perimeter)(Shape *self);
    void   (*print)(Shape *self);
} ShapeVTable;

/* base struct: vtable pointer içerir */
struct Shape {
    const ShapeVTable *vptr;
    const char *name;
};

/* ortak arayüz fonksiyonları (wrapper) */
double Shape_get_area(Shape *s)        { return s->vptr->get_area(s); }
double Shape_get_perimeter(Shape *s)   { return s->vptr->get_perimeter(s); }
void   Shape_print(Shape *s)           { s->vptr->print(s); }

/* ====================== */
/* 2) Circle (alt tip)    */
/* ====================== */
typedef struct {
    Shape base;
    double radius;
} Circle;

/* Circle metotları */
double Circle_get_area(Shape *s) {
    Circle *c = (Circle*)s;
    return M_PI * c->radius * c->radius;
}
double Circle_get_perimeter(Shape *s) {
    Circle *c = (Circle*)s;
    return 2 * M_PI * c->radius;
}
void Circle_print(Shape *s) {
    Circle *c = (Circle*)s;
    printf("[Circle '%s'] r=%.2f area=%.2f peri=%.2f\n",
           c->base.name, c->radius,
           Circle_get_area(s),
           Circle_get_perimeter(s));
}

/* Circle vtable (tek bir kopya) */
const ShapeVTable Circle_vtable = {
    .get_area = Circle_get_area,
    .get_perimeter = Circle_get_perimeter,
    .print = Circle_print
};

/* Circle oluşturucu */
void Circle_init(Circle *c, const char *name, double r) {
    c->base.vptr = &Circle_vtable;
    c->base.name = name;
    c->radius = r;
}

/* ====================== */
/* 3) Square (alt tip)    */
/* ====================== */
typedef struct {
    Shape base;
    double side;
} Square;

/* Square metotları */
double Square_get_area(Shape *s) {
    Square *sq = (Square*)s;
    return sq->side * sq->side;
}
double Square_get_perimeter(Shape *s) {
    Square *sq = (Square*)s;
    return 4 * sq->side;
}
void Square_print(Shape *s) {
    Square *sq = (Square*)s;
    printf("[Square '%s'] side=%.2f area=%.2f peri=%.2f\n",
           sq->base.name, sq->side,
           Square_get_area(s),
           Square_get_perimeter(s));
}

/* Square vtable */
const ShapeVTable Square_vtable = {
    .get_area = Square_get_area,
    .get_perimeter = Square_get_perimeter,
    .print = Square_print
};

/* Square oluşturucu */
void Square_init(Square *sq, const char *name, double side) {
    sq->base.vptr = &Square_vtable;
    sq->base.name = name;
    sq->side = side;
}

/* ====================== */
/* 4) Kullanım            */
/* ====================== */
int main(void) {
    Circle c1;
    Square s1;

    Circle_init(&c1, "c1", 5.0);
    Square_init(&s1, "s1", 3.0);

    /* polimorfik kullanım — aynı arayüz, farklı davranış */
    Shape *shapes[] = { (Shape*)&c1, (Shape*)&s1 };
    for (int i = 0; i < 2; ++i) {
        Shape_print(shapes[i]);
    }

    return 0;
}



// Çıktı

/*
 [Circle 'c1'] r=5.00 area=78.54 peri=31.42
 [Square 's1'] side=3.00 area=9.00 peri=12.00
*/