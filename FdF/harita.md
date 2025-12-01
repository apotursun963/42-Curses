

Bu cümlenin anlamı FDF’in **temel koordinat mantığını** özetler. Aşağıdaki şekilde açıklanır:

---

# ✔️ **Her sayı bir uzay noktasını temsil eder:**

## 1) **Horizontal position → Abscissa (x koordinatı)**

* Yani satır içindeki sütunun indeksi **x** değeridir.
* Örnek: 5. sütundaki sayı → x = 4

## 2) **Vertical position → Ordinate (y koordinatı)**

* Satır numarası **y** değeridir.
* Örnek: 3. satır → y = 2

## 3) **Value → Altitude (z koordinatı)**

* Sayının kendisi **yükseklik (z)** değeridir.
* Z = tepe, vadi, dağ anlamını taşır.

---

# ✔️ Kısaca:

**(sütun, satır, yükseklik) → (x, y, z)**

`.fdf` satırı şöyle ise:

```
0 3 5 -2
```

Bu satırdaki noktalar şunlara dönüşür:

| Sütun | x | y | z  |
| ----- | - | - | -- |
| 0     | 0 | 0 | 0  |
| 3     | 1 | 0 | 3  |
| 5     | 2 | 0 | 5  |
| -2    | 3 | 0 | -2 |

Böylece her sayı uzayda bir nokta olarak temsil edilir.

---

İstersen bunun bir çizim şemasını da hazırlayabilirim.
