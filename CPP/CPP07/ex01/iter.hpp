
#pragma once

#include <iostream>

/*
`iter` fonksiyonu iki tür parametresi (`T` ve `F`) alır:
* **`T`** → dizinin eleman türünü temsil eder.
* **`F`** → fonksiyonun (örneğin `cout`) parametre türünü temsil eder.
Bu iki türün **bağımsız olması**, `iter`’in hem **const** hem **non-const** dizilerle ve farklı 
türde fonksiyon parametreleriyle çalışmasını sağlar.
Yani F, T’den bağımsız çıkarılır.
Bu sayede derleyici iki türü ayrı ayrı değerlendirir.

*** Önemli 
int arr[] = {1, 2, 3};
iter(arr, 3, cout<int>);
    - iter<int, const int&>(arr, 3, cout<int>);
- arr → int*, dolayısıyla T = int
- cout<int> → void(const int&) alıyor, dolayısıyla F = const int&
- Yani derleyici F’yi otomatik olarak const int& olarak çıkarıyor.
- Bu sayede arr[i] (yani int) → const int& dönüşümü geçerli oluyor.

const int arr[] = {1, 2, 3};
iter(arr, 3, cout<int>);
    - iter<const int, const int&>(arr, 3, cout<int>);
- T = const int | F = const int&
- Bu da geçerli çünkü cout fonksiyonu const int& alıyor.
- Derleyici bu durumda arr[i] (yani const int) → const int& bağlamasına izin verir.
***

Yok eğer sadece tek tür olsaydır (T) Bu durumda func’ın aldığı tür T’ye bağımlı olurdu.
Yani T = const int olduğunda, func da void(const int) olmalıydı.
Ama cout void(const int&) alıyor → eşleşmezdi ❌
İşte bu yüzden T ve F’yi ayrı ayrı tanımlamak gerekir.
Böylece fonksiyonun aldığı parametre türü (F) dizinin eleman türüne (T) tam bağlı olmaz,
derleyici her ikisini bağımsızca uygun hale getirir.
- const & parametre türü her tür değere bağlanabiliyor

---

### 🔍 Neden İki Tür (T ve F)?

* Eğer dizi `const` ise elemanlar `const T` olur.
* `T&` alan (non-const ref) bir fonksiyona **bağlanamaz**.
* Bu yüzden fonksiyonun ya `const T&` alması gerekir, ya da `F` tipi sayesinde uygun dönüştürme yapılmalıdır.

`iter` bu iki türü ayrı tuttuğu için, `const` dizilerle de uyumlu hale gelir.

---

### 🧩 Derleyici Ne Yapar?

* Her çağrıda `T` ve `F`’yi **ayrı ayrı çıkarır (deduction).**
* `cout` fonksiyonu `T const &` aldığı için hem `const` hem `non-const` dizilerle çalışır.
* `T&` alsaydı sadece `non-const` dizilerle çalışırdı.

---

### 🧠 C++ Dönüşüm Mantığı (Reference Binding Rules)

`int → const int&` geçerli bir dönüşümdür çünkü:

* `const &` hem normal, hem `const`, hem geçici değerlere bağlanabilir.
* Gerekirse derleyici **geçici bir nesne** oluşturur.
* Bu sayede değer **kopyalanmadan okunabilir**, ama **değiştirilemez**.

➡️ “`const &` = her türlü değeri güvenli biçimde oku, ama dokunma.”

| Durum             | `T`         | `F`          | Çalışır mı? |
| ----------------- | ----------- | ------------ | ----------- |
| `int arr[]`       | `int`       | `const int&` | ✅           |
| `const int arr[]` | `const int` | `const int&` | ✅           |

---

### 🔚 Sonuç

`iter` fonksiyonunun her durumda çalışabilmesini sağlayan temel noktalar:

1. `T` ve `F`’nin **bağımsız template parametreleri** olması
2. `cout`’un **`const &` parametresiyle** tanımlanması
3. C++’ta **`int → const int&` dönüşümünün geçerli** olması
4. **Template tür çıkarımının** her çağrı için ayrı ayrı yapılması

👉 Kısacası:
**“const &” sayesinde `cout` fonksiyonu her tür değeri güvenli biçimde okuyabilir,
`iter` de bu esneklikten yararlanarak hem const hem non-const dizilerle çalışabilir.**

- int → const int& bağlanabilir

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
