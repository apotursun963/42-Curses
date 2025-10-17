
#pragma once

#include <iostream>

/*
T -> dizinin elemanlarının türünü temsil eder.
F -> Fonksiyonun parametre olarak aldığı türdür.


İki tür tipi (T ve F) tanımlamamızın nedeneni örnek olarak:
Eğer Array const ise, dizi elemanları const olur ve bunlar 
non-const reference (T&) alan bir fonksiyona bağlanamaz. 
Bunun yerine fonksiyon by-value veya const T& almalı ya da 
fonksiyon parametresi dizenin eleman tipine dönüştürülebilir olmalı.

- Derleyici hem T hem F'yi ayrı ayrı çıkarır; böylece bir fonksiyon const T& alıyorsa 
hem const hem non-const dizilerle çalışır, ama fonksiyon T& (non-const ref)
alıyorsa yalnızca non-const dizilerle çalışır 
(const dizi ile derleme hatası verir — bu beklenen, doğru davranış).

iter fonksiyonu F’yi bağımsız tanımladığı için cout’un const & parametresine uygun şekilde eşleşebiliyor.
C++’ta int → const int& geçerli bir dönüşümdür.
Derleyici çağrı sırasında cout<int> versiyonunu otomatik oluşturup iter’e uygun hale getiriyor.
| Durum             | `T`         | `F`          | Çalışır mı? |
| ----------------- | ----------- | ------------ | ----------- |
| `int arr[]`       | `int`       | `const int&` | ✅           |
| `const int arr[]` | `const int` | `const int&` | ✅           |

🔚 Sonuç
iter fonksiyonunun hem const hem de non-const array’lerle, ayrıca cout(T const&) gibi bir fonksiyonla çalışabilmesini sağlayan şey şudur:
✅ T ve F’nin bağımsız template parametreleri olması
✅ cout’un parametresinin const & olması
✅ C++’taki int → const int& dönüşümünün geçerli olması
✅ Template çıkarımının (deduction) her çağrı için ayrı ayrı yapılması

“cout’un parametresinin const & olması neden önemli?”
Çünkü bu sayede cout fonksiyonu:
    - Her tür değeri (const, non-const, geçici) kabul edebiliyor,
    - Değerleri değiştirmiyor,
    - iter fonksiyonu ile const veya non-const dizilerle uyumlu hale geliyor.
Yani “const &” = her şeyi oku ama dokunma anlamına geliyor 💡
kısacası, cout funcs const int & olduğu için farklı veri tipleri ile uygun dönüşümler yapabiliyor
peki bu dönüşümü nasıl yapıyor o da (reference binding rules)

C++’ta int → const int& dönüşümü otomatik olur çünkü:
- const & (sabit referans) hem normal değişkenlere, hem const değişkenlere, hem de geçici değerlere (ör. 10) bağlanabilir.
- Derleyici bu durumda gerekirse geçici bir nesne oluşturur ve referansı ona bağlar.
- Bu sayede değer kopyalanmaz, değiştirilemez, ama okunabilir olur.
- Yani const & = “her türlü değeri güvenli bir şekilde al ama değiştirme.” ✅

reference binding rules
---

*/

template <typename T, typename F>   // bu funcs iki tür parametre alır (T, F)
void    iter(T *arr, int len, void(*func)(F)) {
    int i = -1;
    while (++i < len)
        func(arr[i]);
}

template <typename T>
void    cout(T const &value) {
    std::cout << value << std::endl;
}

