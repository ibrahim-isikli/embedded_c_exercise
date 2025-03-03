#include <stdio.h>

// Dizideki elemanları toplayan fonksiyon
int sum(int arr[], int size) {
    int total = 0;
    for (int i = 0; i < size; i++) {
        total += arr[i];
    }
    return total;
}

// Dizideki elemanları çarpan fonksiyon
int multiply(int arr[], int size) {
    int product = 1;
    for (int i = 0; i < size; i++) {
        product *= arr[i];
    }
    return product;
}

// Dizideki en büyük elemanı bulan fonksiyon
int find_max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Genel işlem fonksiyonu (Callback kullanımı)
void process_array(int arr[], int size, int (*operation)(int[], int)) {
    printf("Sonuç: %d\n", operation(arr, size));
}

int main() {
    int arr[] = {2, 4, 6, 8, 10}; // Örnek dizi
    int size = sizeof(arr) / sizeof(arr[0]);

    // Kullanıcıdan seçim alma
    int choice;
    printf("İşlem seçin (1: Toplama, 2: Çarpma, 3: En büyük değeri bulma): ");
    scanf("%d", &choice);

    // Seçime göre uygun fonksiyonu çağırma
    if (choice == 1)
        process_array(arr, size, sum);
    else if (choice == 2)
        process_array(arr, size, multiply);
    else if (choice == 3)
        process_array(arr, size, find_max);
    else
        printf("Geçersiz seçim!\n");

    return 0;
}
