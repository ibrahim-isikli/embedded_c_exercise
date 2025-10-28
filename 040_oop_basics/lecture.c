//////////// adım 1 — fonksiyon işaretçileri (temel) //////////////////////////

// Neden ?

/*
    Bir imzaya (parametre/dönüş tipine) uyan farklı fonksiyonları değiştirerek çağırabilmek için. 
    FreeRTOS’ta gördüğün “kancalar” (hook) ve driver tabloları bunun üstüne kurulur.
 */

 // Kavramlar 

 /*
    imza (signature): Fonksiyonun parametre ve dönüş tiplerinin toplam tarifi.
    function pointer: Belirli bir imzaya sahip fonksiyonun adresini tutan değişken.
    typedef: Uzun imzaları kısaltıp okunur yapmak için takma ad.
 */


 // Mantık

 /*
    compute fonksiyonun ne yaptığını bilmez, “nasıl yapılacağını” parametre olarak alır. Bu, “değişebilir davranış”ın en yalın hali.
 */

 #include <stdio.h>

/* 1) İmzayı tarif eden typedef */
typedef int (*op_t)(int a, int b);

/* 2) Aynı imzaya sahip birkaç fonksiyon */
int add(int a, int b) { return a + b; }
int mul(int a, int b) { return a * b; }
int max2(int a, int b){ return (a > b) ? a : b; }

/* 3) Bir "hesapla" yardımcı fonksiyonu: davranışı parametre olarak alır */
int compute(op_t op, int x, int y) {
    return op(x, y); // hangi fonksiyon gelirse onu çağırır
}

int main(void) {
    /* 4) Tek tek çağırma */
    printf("add(3,4) = %d\n", compute(add, 3, 4));
    printf("mul(3,4) = %d\n", compute(mul, 3, 4));
    printf("max(3,4) = %d\n", compute(max2, 3, 4));

    /* 5) Bir tablo (dizi) içinde saklama */
    op_t table[] = { add, mul, max2 };
    const char *names[] = { "add", "mul", "max" };

    for (int i = 0; i < 3; ++i) {
        int r = table[i](10, 5); // fonksiyonu doğrudan çağırdık
        printf("%s(10,5) = %d\n", names[i], r);
    }
    return 0;
}


// Output

/*
    add(3,4) = 7
    mul(3,4) = 12
    max(3,4) = 4
    add(10,5) = 15
    mul(10,5) = 50
    max(10,5) = 10
 
*/