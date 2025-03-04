#include <stdio.h>

// Dört işlem fonksiyonları
double add(double a, double b) { return a + b; }
double subtract(double a, double b) { return a - b; }
double multiply(double a, double b) { return a * b; }
double divide(double a, double b) { return (b != 0) ? a / b : 0; }

// Hesap makinesi fonksiyonu (Fonksiyon pointer kullanımı)
void calculator(double a, double b, double (*operation)(double, double)) {
    printf("Sonuç: %.2f\n", operation(a, b));
}

int main() {
    double num1, num2;
    int choice;

    // Kullanıcıdan iki sayı alma
    printf("Birinci sayıyı girin: ");
    scanf("%lf", &num1);
    printf("İkinci sayıyı girin: ");
    scanf("%lf", &num2);

    // Kullanıcıdan işlem seçme
    printf("İşlem seçin (1: Toplama, 2: Çıkarma, 3: Çarpma, 4: Bölme): ");
    scanf("%d", &choice);

    // Seçime göre ilgili fonksiyon pointer'ını çağırma
    switch (choice) {
        case 1: calculator(num1, num2, add); break;
        case 2: calculator(num1, num2, subtract); break;
        case 3: calculator(num1, num2, multiply); break;
        case 4: calculator(num1, num2, divide); break;
        default: printf("Geçersiz seçim!\n");
    }

    return 0;
}
