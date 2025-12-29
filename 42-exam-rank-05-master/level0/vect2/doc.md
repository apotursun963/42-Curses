
# Bu egzersizin temel konusu **operatör aşırı yükleme (operator overloading)**

## 1️⃣ vect2 sınıfı neyi temsil ediyor?

Bu sınıf:

* 📐 **2 boyutlu matematiksel bir vektörü**
* 📦 İçinde **iki adet int (x, y)** barındıracak şekilde
  tasarlanmış.

Yani matematikteki şu yapı:

```
v = (x, y)
```

Kodda:

```cpp
class vect2 {
    int x;
    int y;
};
```

Amaç:
Bu vektörle **toplama, çıkarma, çarpma, karşılaştırma, yazdırma** gibi işlemleri **doğal C++ sözdizimiyle** yapabilmek.

---

## 2️⃣ Ortodoks (Canonical) Form – Sınıfın omurgası

Bu egzersiz sana **C++ sınıfının temel yaşam döngüsünü** öğretiyor:

```cpp
vect2();
vect2(int, int);
vect2(const vect2&);
vect2& operator=(const vect2&);
~vect2();
```

### Neden önemli?

Çünkü şu satırlar problemsiz çalışıyor:

```cpp
vect2 v2(1, 2);
const vect2 v3(v2);
vect2 v4 = v2;
```

Burada:

* 🔹 Default constructor → `vect2 v1;`
* 🔹 Parametreli constructor → `vect2 v2(1,2);`
* 🔹 Copy constructor → `vect2 v3(v2);`
* 🔹 Copy assignment → `vect2 v4 = v2;`

Bu **C++’ta sağlam sınıf yazmanın temelidir**.

---

## 3️⃣ [] operatörü – Dizi gibi davranmak

```cpp
v1[0]
v1[1] = 12;
```

Bunun için **iki versiyon** yazılmış:

```cpp
int operator[](int) const;
int& operator[](int);
```

### Neden iki tane?

* `const vect2` → **sadece okuma**
* normal `vect2` → **okuma + yazma**

Bu satırın çalışabilmesi için şart:

```cpp
v1[1] = 12;
```

💡 Bu kısım sana **const-correctness** kavramını öğretir.

---

## 4️⃣ << operatörü – Profesyonel çıktı

Bu:

```cpp
std::cout << v << std::endl;
```

Şuna dönüşüyor:

```cpp
{ x, y }
```

Operator overload:

```cpp
std::ostream& operator<<(std::ostream& out, const vect2& v)
```

### Öğrettiği şey:

* Sınıf dışı (non-member) operatör yazımı
* `std::ostream` kullanımı
* Zincirleme yazdırma (`<< << <<`)

Bu **C++’ta kalite göstergesidir**.

---

## 5️⃣ Matematiksel işlemler (asıl olay burada 💥)

### ➕ ➖ Vektör işlemleri

```cpp
v1 + v2
v1 - v2
v1 += v2
```

Burada iki yaklaşım var:

| Operatör   | Davranış                  |
| ---------- | ------------------------- |
| `+ - *`    | Yeni nesne döndürür       |
| `+= -= *=` | Mevcut nesneyi değiştirir |

Bu ayrım **çok kritik**.

---

## 6️⃣ Skaler çarpma (v * 2 ve 2 * v)

### Sağdan çarpma:

```cpp
vect2 operator*(int) const;
```

### Soldan çarpma:

```cpp
vect2 operator*(int, const vect2&);
```

Sayede:

```cpp
v2 = 3 * v2;
```

çalışabiliyor 🚀
Bu bölüm sana **neden bazı operatörlerin sınıf dışında yazıldığını** öğretir.

---

## 7️⃣ ++ ve -- operatörleri (Prefix vs Postfix)

```cpp
v4++
++v4
```

### Fark:

* **Prefix (`++v`)** → önce artırır, sonra döndürür
* **Postfix (`v++`)** → önce döndürür, sonra artırır

Kodda:

```cpp
vect2 operator++(int); // postfix
vect2& operator++();   // prefix
```

Bu bölüm:

* 🔹 Nesne kopyalama
* 🔹 Performans farkı
* 🔹 Gerçek C++ davranışı

konularını öğretir.

---

## 8️⃣ Unary minus ( -v )

```cpp
-v2
```

Her bileşeni ters çevirir:

```
{3, 5} → {-3, -5}
```

Bu:

```cpp
vect2 operator-() const;
```

Unary operatör kavramını öğretir.

---

## 9️⃣ Karşılaştırmalar (== ve !=)

```cpp
v1 == v3
v1 != v1
```

Burada:

* **Mantıksal doğruluk**
* **Bileşen bazlı karşılaştırma**
* `!=`’in `==` üzerinden yazılması (DRY prensibi)

öğretiliyor.

---

## 🔟 Bu egzersiz sana ne kazandırır?

Bu tek ödev şunları öğretir:

✅ Operator Overloading
✅ Const correctness
✅ Canonical Form
✅ Referans & kopya farkı
✅ Matematiksel modelleme
