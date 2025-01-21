# Quick Sort Algoritması Nedir ?

**Quick Sort (Hızlı Sıralama)**, bir **böl ve fethet** (divide and conquer) algoritmasıdır. Bu algoritma, başlangıçta tüm diziyi bir pivot değerine göre böler. Pivot'un solundaki tüm öğeler pivot'tan küçük, sağındakiler ise büyük olur. Sonrasında her iki alt dizi (pivot'un sol ve sağındaki parçalar) için aynı işlem tekrar edilir. Bu süreç, dizinin tamamı sıralanana kadar devam eder.

1. **Pivot Seçimi**: 
   - Listenin bir elemanı pivot olarak seçilir (genellikle ilk eleman, son eleman ya da ortanca eleman tercih edilir).

2. **Bölme**: 
   - Listenin geri kalan elemanları pivot'tan küçük ve büyük olanlar olarak iki alt listeye ayrılır.

3. **Rekürsif Uygulama**:
   - Alt listeler üzerinde aynı işlem tekrarlanır.

4. **Birleştirme**:
   - Alt listeler sıralandıktan sonra pivot ile birleştirilerek sonuç elde edilir.

Quick Sort'un **ortalama zaman karmaşıklığı O(n log n)**, en kötü durumda ise **O(n²)**'dir. 
---

## Quick Sort Algoritmasının Çalışma Prensibi

1. Bir pivot seçilir.
2. Pivot'un soluna ondan küçük elemanlar, sağına ise büyük elemanlar yerleştirilir.
3. Bu işlem her alt liste üzerinde rekürsif olarak tekrarlanır.
4. En sonunda bu alt listeler birleştirilir.

## Quick Sort Code
```C
int partition(int arr[], int start, int end)
{
    int pivot = arr[end];           // Pitvotu en son öğe olarak seçiyoruz
    int i = (start - 1);            // i, pivot'tan küçük olan öğelerin son indeksini tutar.

    // Bu döngüde, dizinin her elemanı (pivot dışındaki tüm elemanlar) pivot ile karşılaştırılır.
    for (int j=start; j <= end - 1; j++)
    {
        // Eğer mevcut öğe pivot'tan küçükse, öğeyi yer değiştir
        if (arr[j] < pivot)
        {
            i++;    // küçük öğe bulundu, i'yi artır
            int tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }

    // Pivot'u doğru yerine yerleştir
    int tmp = arr[i + 1];
    arr[i + 1] = arr[end];
    arr[end] = tmp;
    return (i + 1);     // Pivot'un yeni index'i
}

void    QuickSort(int arr[], int start, int end)
{
    if (start < end)
    {
        // Bölme işlemi
        int median = partition(arr, start, end);    // median, pivot'un index'idir

        // Pivot'un sol tarafındaki alt yığını sıralamak için
        QuickSort(arr, start, median - 1);

        // Pivot'un sağ tarafındaki alt yığını sıralamak için
        QuickSort(arr, median + 1, end);
    }
}

```