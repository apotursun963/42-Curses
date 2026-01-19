
# Ford–Johnson Algoritması

**Merge Insertion Sort** (diğer adıyla **Ford–Johnson algoritması**), karşılaştırma sayısını mümkün olduğunca **azaltmak** amacıyla tasarlanmış, teorik olarak çok güçlü ama pratikte uygulanması zor bir sıralama algoritmasıdır.

Özellikle **42 school – PmergeMe** gibi projelerde karşına çıkar.

---

## Merge Insertion Sort nedir? 🧠

Merge Insertion Sort, **Merge Sort** ve **Insertion Sort** fikirlerini birleştirir ama aslında ikisinden de **daha özel** bir yaklaşıma sahiptir.

🎯 **Amaç:**
Bir diziyi **en az karşılaştırma** yaparak sıralamak.

Bu algoritma:

* “Karşılaştırma temelli sıralamalar” arasında **en az karşılaştırmaya yaklaşan** algoritmalardan biridir
* Donald Knuth’un *The Art of Computer Programming* kitabında anlatılır
* Teorik olarak çok güçlü, kodlaması zor

---

## Temel fikir (yüksek seviyede)

Algoritma 3 ana aşamadan oluşur:

---

### 1️⃣ Elemanları **ikili gruplara ayırma**

Dizi baştan sona **ikili (pair)** olarak ayrılır:

```text
[5, 2, 9, 1, 6, 3]

→ (5,2) (9,1) (6,3)
```

Her çift **kendi içinde sıralanır**:

```text
(2,5) (1,9) (3,6)
```

📌 Bu aşamada sadece **n / 2 karşılaştırma** yapılır.

---

### 2️⃣ Büyük elemanlardan ana zincir oluşturma (main chain)

Her çiftteki **büyük elemanlar** alınır:

```text
Büyükler → [5, 9, 6]
```

Bu büyük elemanlar **recursive olarak** tekrar Merge Insertion Sort ile sıralanır:

```text
[5, 6, 9]
```

📌 Bu listeye **main chain** denir.

---

### 3️⃣ Küçük elemanları özel sırayla ekleme (Insertion)

Küçük elemanlar:

```text
Küçükler → [2, 1, 3]
```

Bunlar main chain içine **normal insertion sort gibi değil**,
**Jacobsthal sayı dizisine göre belirlenen özel bir sırayla** eklenir.

Bu sayede:

* Gereksiz karşılaştırmalar önlenir
* Her ekleme **binary search** ile yapılır

---

## Jacobsthal Sayıları nedir? 🔢

Merge Insertion Sort’un “sihirli” kısmı burasıdır.

Jacobsthal dizisi:

```text
0, 1, 1, 3, 5, 11, 21, ...
```

Bu dizi, küçük elemanların **hangi sırayla** main chain’e ekleneceğini belirler.

📌 Amaç:

* En kötü durumda bile minimum karşılaştırma yapmak

---

## Görsel olarak akış

![Image](https://media.geeksforgeeks.org/wp-content/uploads/20200601174332/Merge-Sort-Tutorial.png)

![Image](https://www.dinocajic.com/wp-content/uploads/2023/12/Dec-7-16.webp)

![Image](https://visualgo.net/img/merge.png)

---

## Zaman Karmaşıklığı ⏱️

| Özellik              | Değer                              |
| -------------------- | ---------------------------------- |
| Karşılaştırma sayısı | **≈ n log n (en iyiye çok yakın)** |
| Big-O                | **O(n log n)**                     |
| Bellek               | O(n)                               |
| Stabil mi?           | ❌ Hayır                            |

📌 Diğer O(n log n) algoritmalarına göre **daha az karşılaştırma** yapar.

---

## Avantajları ✅

✔ En az karşılaştırmaya çok yakın
✔ Teorik olarak çok güçlü
✔ Küçük veri setlerinde çok verimli
✔ Akademik olarak önemli

---

## Dezavantajları ❌

❌ Kodlaması çok karmaşık
❌ Jacobsthal dizisi mantığı zor
❌ Pratikte quicksort / mergesort daha basit
❌ Hatalı implementasyon riski yüksek

---

## Merge Sort & Insertion Sort ile farkı

| Algoritma           | Temel Mantık                                            |
| ------------------- | ------------------------------------------------------- |
| Merge Sort          | Böl → sırala → birleştir                                |
| Insertion Sort      | Tek tek yerleştir                                       |
| **Merge Insertion** | Çiftle → büyükleri sırala → küçükleri özel sırayla ekle |

---

## PmergeMe ile bağlantısı (önemli!) 🔥

42’de senden şunlar beklenir:

* **Ford–Johnson algoritmasını** kullanman
* `std::vector` ve `std::deque` ile karşılaştırman
* Süreyi **mikrosaniye** cinsinden ölçmen
* “Before / After” çıktısı vermen

Yani:

> ❌ Normal merge sort yazmak **yetmez**
> ✅ Merge Insertion mantığını uygulaman gerekir

