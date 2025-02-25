#include <stdio.h>
#include <stdlib.h>

int main() {
    int num_students; 

    printf("ogrenci sayisini girin: ");
    scanf("%d", &num_students);

    // ogrencilerin notlarini tutacak dinamik bellek tahsisi
    int **grades = (int**)malloc(num_students * sizeof(int*));
    int *exam_count = (int*)malloc(num_students * sizeof(int)); // Her ogrencinin kac sinavi var

    if (grades == NULL || exam_count == NULL) {
        printf("Bellek tahsisi basarisiz!\n");
        return 1;
    }

    // Her ogrenci icin sinav sayisini ve notlarini al
    for (int i = 0; i < num_students; i++) {
        printf("ogrenci %d kac sinava girdi? ", i + 1);
        scanf("%d", &exam_count[i]);

        grades[i] = (int*)malloc(exam_count[i] * sizeof(int)); // Sinav sayisi kadar bellek tahsis et

        if (grades[i] == NULL) {
            printf("Bellek tahsisi basarisiz!\n");
            return 1;
        }

        printf("ogrenci %d icin sinav notlarini girin:\n", i + 1);
        for (int j = 0; j < exam_count[i]; j++) {
            printf("Not %d: ", j + 1);
            scanf("%d", &grades[i][j]);
        }
    }

    // Ortalama hesaplama ve ekrana yazdirma
    printf("\nogrencilerin not ortalamalari:\n");
    for (int i = 0; i < num_students; i++) {
        int sum = 0;
        for (int j = 0; j < exam_count[i]; j++) {
            sum += grades[i][j];
        }
        printf("ogrenci %d: %.2f\n", i + 1, (double)sum / exam_count[i]);
    }

    // Bellegi temizleme
    for (int i = 0; i < num_students; i++) {
        free(grades[i]); // Her ogrencinin notlarini iceren diziyi temizle
    }
    free(grades);
    free(exam_count);

    return 0;
}
