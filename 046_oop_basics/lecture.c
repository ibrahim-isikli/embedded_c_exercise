//////////// Adım 3 — Struct + Fonksiyon Pointer → “Metot” //////////////////////////

// Neden ?

/*
 Bir struct içine bir fonksiyon pointer koyarak "o struct'a ait fonksiyon" yani metot gibi kullanım yaparız.
 Boylece hem state hem de behavior aynı kapsül içinde durur
*/

// Kavramlar 

/*
 self / this : Fonksiyonun "hangi örnek" üzerinde çalıştığını belirtir. C'de açıkca self parametresi olarak verilir.
 struct içi fonksiyon pointer : struct behavior'u temsil eder (örn: increment, reset)
 kapsülleme : veriyi ve onu işleyen fonksiyonları aynı yerde toplar.
*/



#include <stdio.h>

/* 1) Struct tanımı: veri + davranış (fonksiyon pointer) */
typedef struct Counter 
{
    int value;
    /* “metotlar” */
    void (*inc)(struct Counter *self);
    void (*reset)(struct Counter *self);
    void (*print)(struct Counter *self);
} Counter;

/* 2) Metot implementasyonları */
void Counter_inc(Counter *self)   { self->value++; }
void Counter_reset(Counter *self) { self->value = 0; }
void Counter_print(Counter *self) { printf("[Counter] value = %d\n", self->value); }

/* 3) Kurucu benzeri init fonksiyonu */
void Counter_init(Counter *c) 
{
    c->value = 0;
    c->inc   = Counter_inc;
    c->reset = Counter_reset;
    c->print = Counter_print;
}

/* 4) Kullanım */
int main(void) 
{
    Counter c1, c2;

    Counter_init(&c1);
    Counter_init(&c2);

    c1.inc(&c1);
    c1.inc(&c1);
    c1.print(&c1);   // [Counter] value = 2

    c2.inc(&c2);
    c2.print(&c2);   // [Counter] value = 1

    c1.reset(&c1);
    c1.print(&c1);   // [Counter] value = 0
    return 0;
}
