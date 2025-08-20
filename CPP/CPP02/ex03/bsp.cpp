

#include "Point.hpp"

bool bsp(Point const a, Point const b, Point const c, Point const point)
{


}

/*
BSP
Binary Space Partitioning (BSP)
"Binary Space Partitioning" (BSP), grafikler ve çarpışma algılama gibi alanlarda kullanılan bir teknik. 
Bu projede, bir üçgenin içinde bir noktanın olup olmadığını kontrol etmek için kullanılıyor.
Amaç: verilen bir noktanın bir üçgenin içinde olup olmadığını belirleyen bir sistem geliştirmek.
3 şey yapacağız; Fixed Sınıfı / Point Sınıfı / BSP Sınıfı
- Fixed Sınıf
Önceki alıştırmada yazdığın Fixed-point sayı sınıfı artık hazır. Bu projede onu kullanmaya devam edeceksin
- Point Sınıf
Bu sınıf orthodox canonical form olmalı, Yeni bir 2D nokta sınıfı istiyor:

- a, b, c: Üçgenin köşeleri (vertices)
- point: Kontrol edilecek Nokta
- Returns: Eğer nokta üçgenin içinde ise → True
Eğer nokta üçgenin dışında, köşesinde ya da kenarında ise → False


Üçgenin Alan Formülü
---
Koordinatlar ile Alan (Determinant Yöntemi)
Üçgenin köşeleri koordinat düzleminde (x, y) ile verilmişse:
Koordinat Formülü
1. Her bir köşenin (a, b, c) x ve y koordinatları alınır
2. Formül
    - Her köşe, diğer iki köşe ile olan dikey farklarla çarpılıyor.
    - Bu çarpımların toplamı, üçgenin yönlü alanını veriyor (pozitif veya negatif olabilir).
    - Son olarak 2’ye bölünüp mutlak değer (fabs) alınarak gerçek alan elde ediliyor. çünkü alan her zaman pozitif olmalı.

*/
