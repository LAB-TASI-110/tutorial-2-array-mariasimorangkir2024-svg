//12S25033 - Maria octavia Simorangkir

#include <stdio.h>
#include <limits.h>
#include <float.h>
#include <stdlib.h> // Untuk malloc dan free

int main() {
    int n;

    printf("Masukkan jumlah bilangan (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Jumlah bilangan (n) harus merupakan bilangan bulat positif.\n");
        return 1;
    }

    int *numbers = (int *)malloc(n * sizeof(int));
    if (numbers == NULL) {
        printf("Alokasi memori gagal.\n");
        return 1;
    }

    int min_val = INT_MAX;
    int max_val = INT_MIN;
    long long sum = 0;

    printf("Masukkan %d bilangan bulat antara -100 dan 100:\n", n);

    for (int i = 0; i < n; i++) {
        int num;
        printf("Bilangan ke-%d: ", i + 1);
        scanf("%d", &num);
        numbers[i] = num;

        if (num < -100 || num > 100) {
            printf("Peringatan: Bilangan %d berada di luar rentang -100 hingga 100. Tetap diproses.\n", num);
        }

        if (num < min_val) {
            min_val = num;
        }

        if (num > max_val) {
            max_val = num;
        }

        sum += num;
    }

    printf("\n--- Hasil Analisis ---\n");
    printf("Nilai terkecil: %d\n", min_val);
    printf("Nilai terbesar: %d\n", max_val);
    printf("Jumlah total: %lld\n", sum);

    if (n < 2) {
        printf("Rata-rata terendah tidak dapat dihitung karena jumlah bilangan kurang dari dua.\n");
        printf("Rata-rata tertinggi tidak dapat dihitung karena jumlah bilangan kurang dari dua.\n");
    } else {
        double min_consecutive_avg = DBL_MAX;
        double max_consecutive_avg = -DBL_MAX;

        for (int i = 0; i < n - 1; i++) {
            double current_avg = (double)(numbers[i] + numbers[i+1]) / 2.0;
            if (current_avg < min_consecutive_avg) {
                min_consecutive_avg = current_avg;
            }
            if (current_avg > max_consecutive_avg) {
                max_consecutive_avg = current_avg;
            }
        }
        printf("Nilai rata-rata terendah dari dua nilai berturut: %.2f\n", min_consecutive_avg);
        printf("Nilai rata-rata tertinggi dari dua nilai berturut: %.2f\n", max_consecutive_avg);
    }
    
    free(numbers);

    return 0;
}