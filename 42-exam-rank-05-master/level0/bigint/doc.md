
# bigint

## 🔹 Egzersizin Amacı (Big Picture)

Bu proje senden **C++’ta “keyfi büyüklükte” (arbitrary precision) sayıları** tutabilen bir sınıf yazman isteniyor.

Normalde:
- `unsigned int`, `unsigned long`, `size_t` gibi türlerin **üst sınırı vardır**
- Bu sınırı aşan sayılar **taşma (overflow)** yapar

👉 **bigint sınıfı**, bu sınırları aşan **çok büyük pozitif tam sayıları** **hassasiyet kaybı olmadan** saklayabilmelidir.


## 🔹 bigint Nedir?

> “A bignum is an object representing an arbitrary precision number”

Yani:
- Sayının büyüklüğü **önceden sınırlı değil**
- Sayı:
  - string
  - vector / array
  gibi yapılarla tutulur

📌 Örnek:
```cpp
"123456789123456789123456789"
```
Bu sayı hiçbir built-in C++ türüne sığmaz ama `bigint` ile saklanabilir.

---

## 🔹 bigint Sınıfının Özellikleri

### 1️⃣ **Unsigned (Pozitif) Olmalı**
- Sadece **0 ve pozitif sayılar**
- Negatif sayı yok

---

### 2️⃣ **Toplama (Addition)**
`+` operatörü desteklenmeli

Örnek:
```cpp
bigint a("999");
bigint b("1");

bigint c = a + b;  // 1000
```

---

### 3️⃣ **Karşılaştırma (Comparison)**

Şu operatörler çalışmalı:
- `==`
- `!=`
- `<`
- `<=`
- `>`
- `>=`

Örnek:
```cpp
if (a > b)
```

📌 Mantık:
- Önce **basamak sayısı**
- Sonra **tek tek digit karşılaştırması**

---

### 4️⃣ **Digit Shift (En Önemli Kısım)**

Bu, bit shift (`<<`, `>>`) gibi ama **10 tabanında** çalışır.

#### ⬅️ Left Shift (<<)
Sayının sonuna **0 ekler**

```cpp
42 << 3  == 42000
```

Mantık:
```text
42 × 10³
```

---

#### ➡️ Right Shift (>>)
Sayının **son basamaklarını siler**

```cpp
1337 >> 2 == 13
```

Mantık:
```text
1337 / 10² (tam sayı kısmı)
```

📌 Eğer tüm basamaklar silinirse:
```cpp
42 >> 5 == 0
```

---

### 5️⃣ **Yazdırma (operator<<)**

Şu çalışmalı:
```cpp
std::cout << my_bigint;
```

Kurallar:
- **Base 10** yazdır
- **Başta sıfır olamaz**

❌ Yanlış:
```txt
000123
```

✅ Doğru:
```txt
123
```

---

## 🔹 Beklenen İç Yapı (Özgürsün ama…)

Senin kararın ama genelde:

### ✔️ Yaygın Yaklaşım
```cpp
std::string digits;
```
veya
```cpp
std::vector<int> digits;
```

Örnek iç temsil:
```cpp
"12345"
```
veya
```cpp
[1, 2, 3, 4, 5]
```
