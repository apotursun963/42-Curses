
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

- Özet: "const T& alan bir fonksiyon hem const hem non-const dizilerle çalışır"
dememin nedeni bu bağlama (binding) kuralıdır; const-reference hem const hem de 
non-const lvalue'leri kabul eder. Non-const reference kabul etmesi için dizi non-const olmalı.

bağlama (binding) Mantığı
---
- 

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
