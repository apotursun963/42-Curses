
**Ford–Johnson algoritması** (diğer adıyla **Merge–Insertion Sort**), karşılaştırma sayısını **teorik olarak en aza indirmeyi** amaçlayan, oldukça sofistike bir **sıralama algoritmasıdır**.
Özellikle “**en az karşılaştırma ile sıralama**” problemiyle ilgilenen teorik bilgisayar biliminde önemlidir.
Fazla karşılaştırma = daha yavaş çalışma + daha fazla kaynak tüketimi + teorik verimsizlik
bu yüzden bu algoritma kullanmak daha iyi çünkü karşılaştırmayı çok aza indiriyor
eğer çiftleme sonrasında tek bir eleman kalmışsa bu sayı 
*Straggler* olarak kalır. en sonunda bu dizeye eklenir



---

## 1️⃣ Temel fikir (neden özel?)

Karşılaştırma tabanlı sıralamada alt sınır şudur:

[
\lceil \log_2(n!) \rceil
]

Ford–Johnson algoritması, bu sınıra **bilinen en yakın** algoritmalardan biridir.
Pratikte ise karmaşıklığı yüzünden standart kütüphanelerde **kullanılmaz**.

---

## 2️⃣ Yüksek seviyede mantık

Algoritma üç ana fikir üzerine kuruludur:

### 🔹 1. Elemanları çiftlere ayır

Dizi şu şekilde bölünür:

```
(a1, a2), (a3, a4), (a5, a6), ...
```

Her çift **kendi içinde sıralanır** (1 karşılaştırma).

---

### 🔹 2. Büyük elemanlardan ana dizi oluştur

Her çiftin **büyük elemanı** alınır:

```
max(a1,a2), max(a3,a4), max(a5,a6), ...
```

Bu büyük elemanlar **rekürsif olarak Ford–Johnson ile sıralanır**.

---

### 🔹 3. Küçük elemanları özel sırayla ekle

Her çiftin küçük elemanı,
büyük elemanların oluşturduğu sıralı listeye **ikili arama** ile eklenir.

Ama kritik nokta şu:

> Küçük elemanlar **rastgele değil**,
> **Jacobsthal dizisi** ile belirlenen sırada eklenir.

Bu sıra, **karşılaştırma sayısını minimuma indirir**.

---

## 3️⃣ Jacobsthal dizisi (neden önemli?)

Jacobsthal dizisi:

```
J(0)=0
J(1)=1
J(n)=J(n−1)+2·J(n−2)
```

Dizi:

```
0, 1, 1, 3, 5, 11, 21, ...
```

👉 Küçük elemanların **hangi sırayla ekleneceğini** belirler
👉 Gereksiz karşılaştırmaları engeller

---

## 4️⃣ Algoritmanın adım adım özeti

1. Elemanları **ikili gruplara ayır**
2. Her çiftte **küçük–büyük ayır**
3. Büyükleri **rekürsif sırala**
4. Küçükleri **Jacobsthal sırasına göre** ikili arama ile ekle

*Çiftle → ayır → büyükleri sırala → küçükleri ekle → bitir*

---

## 5️⃣ Zaman karmaşıklığı

| Ölçüt                | Değer                    |
| -------------------- | ------------------------ |
| Karşılaştırma sayısı | **≈ log₂(n!) (optimal)** |
| Asimptotik süre      | `O(n log n)`             |
| Uygulama zorluğu     | ⭐⭐⭐⭐⭐                    |

---

## 6️⃣ Basitleştirilmiş C++ örnek kod

> ⚠️ Not: Aşağıdaki kod **eğitici** ve **basitleştirilmiş** bir versiyondur
> Tam Ford–Johnson implementasyonu oldukça uzundur.

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void fordJohnson(vector<int>& arr) {
    if (arr.size() <= 1)
        return;

    vector<int> small;
    vector<int> large;

    // 1. Çiftlere ayır
    for (size_t i = 0; i + 1 < arr.size(); i += 2) {
        if (arr[i] < arr[i + 1]) {
            small.push_back(arr[i]);
            large.push_back(arr[i + 1]);
        } else {
            small.push_back(arr[i + 1]);
            large.push_back(arr[i]);
        }
    }

    // Tek eleman varsa
    if (arr.size() % 2 == 1)
        large.push_back(arr.back());

    // 2. Büyükleri sırala (rekürsif)
    fordJohnson(large);

    // 3. Küçükleri ikili arama ile ekle
    for (int x : small) {
        auto pos = lower_bound(large.begin(), large.end(), x);
        large.insert(pos, x);
    }

    arr = large;
}

int main() {
    vector<int> v = {7, 3, 2, 9, 5, 1, 8, 4, 6};

    fordJohnson(v);

    for (int x : v)
        cout << x << " ";
}
```


## Algoritmalarda Karşılaştırma oranları

