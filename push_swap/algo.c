
/*

Radix sıralama algoritması:
Bu algoritma, sayıları birer birer rakamlarına ayırarak sıralama işlemi yapar.
Diğer sıralama algoritmalarından farklı olarak, Radix sıralaması sayıların tam değerlerini değil, 
basamak düzeyinde çalışır.
Mantığı:
Radix sıralama, sıralanacak sayıları her basamağına göre sıralayarak çalışır. 
Örneğin, 3 basamaktan oluşan bir sayıyı sıralarken ilk olarak en sağdaki basamaktan başlanır, 
ardından orta basamağa geçilir ve en sol basamaya kadar devam edilir. 
Bu işlem, belirli bir basamağa odaklanarak yapılır. 
Bu işlem sırasıyla, sayılar "radix" (taban) değerine göre sıralanır.
Radix sıralama genellikle Stable Sort (kararlı sıralama) gerektirir. 
Yani, aynı değere sahip öğeler sıralama sonunda orijinal sıralarını korurlar.
*/

#include <stdio.h>
#include <stdlib.h>

// Basamağa göre sıralama yapan geçici fonksiyon
void countingSort(int arr[], int n, int step) {
    int output[n]; // sıralı çıktı dizisi
    int count[10] = {0};  //Bu sayaç dizisi, her basamağın (0'dan 9'a kadar olan) kaç kez göründüğünü sayar.

    // Her basamağa göre sayıları say
    for (int i = 0; i < n; i++) {
        count[(arr[i] / step) % 10]++;
    }

    // Sayaçları birleştir
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Sayıları sıralı şekilde output dizisine aktar
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / step) % 10] - 1] = arr[i];
        count[(arr[i] / step) % 10]--;
    }

    // Sonuçları orijinal diziye aktar
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

// Radix sıralama fonksiyonu
void radixSort(int arr[], int n) {
    // En büyük sayıyı bul
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // En büyük sayının basamağı kadar sıralama yap
    // step: basamağı temsil edir(birler, yüzler, binler...).
    for (int step = 1; max / step > 0; step *= 10) {
        countingSort(arr, n, step);
    }
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Orijinal:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    // Radix sıralaması uygula
    radixSort(arr, n);

    printf("Sorted:\n");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
