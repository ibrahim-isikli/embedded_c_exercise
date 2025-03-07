#include <stdio.h>

// Swap fonksiyonu (İki elemanı yer değiştirir)
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Bubble Sort algoritması
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

// Selection Sort algoritması
void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

// Diziyi ekrana yazdıran fonksiyon
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Sıralama işlemi (Fonksiyon pointer ile seçilen algoritmayı çalıştırır)
void sortArray(int arr[], int size, void (*sortingFunction)(int[], int)) {
    sortingFunction(arr, size);
}

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int size = sizeof(arr) / sizeof(arr[0]);
    int choice;

    printf("Mevcut dizi: ");
    printArray(arr, size);

    printf("Sıralama algoritmasını seçin (1: Bubble Sort, 2: Selection Sort): ");
    scanf("%d", &choice);

    // Kullanıcının seçimine göre ilgili sıralama algoritmasını çalıştır
    switch (choice) {
        case 1:
            sortArray(arr, size, bubbleSort);
            break;
        case 2:
            sortArray(arr, size, selectionSort);
            break;
        default:
            printf("Geçersiz seçim!\n");
            return 1;
    }

    printf("Sıralanmış dizi: ");
    printArray(arr, size);

    return 0;
}
