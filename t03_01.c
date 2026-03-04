//12S25033 - Maria Octavia Simorangkir

#include <stdio.h>
#include <limits.h>

int main() {
    int n;

    printf("Masukkan jumlah bilangan (n): ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Jumlah bilangan (n) harus merupakan bilangan bulat positif.\n");
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

    return 0;
}