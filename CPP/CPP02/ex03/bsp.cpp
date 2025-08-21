

#include "Point.hpp"

// Üçgenin alanı hesaplama
/*
determinant yöntemi Formülü
Alan = | x₀*(y₁ - y₂) + x₁*(y₂ - y₀) + x₂*(y₀ - y₁) | / 2
- Üçgenin köşe noktalarının (x, y) koordinatları kullanılır.
Yani, Her köşenin x ve y koordinatları alınır.
- Formüldeki işlemler yapılır.
- Sonuç mutlak değer alınarak 2'ye bölünür.
- Alan her zaman pozitif olur

x₀*(y₁ - y₂): Bir köşe noktasının (a) x koordinatı ile diğer iki (b, c) köşe noktasının y koordinatları arasındaki farkın çarpımıdır.

- x0, x1, x2: Üçgenin köşe noktalarının x koordinatları
- y0, y1, y2: Üçgenin köşe noktalarının y koordinatları
- Her köşe için, kendi x’i ile diğer iki köşenin y’leri arasındaki fark çarpılır ve hepsi toplanır.
Sonuç:
Bu toplam, üçgenin yönlü alanını verir. Mutlak değer alınıp 2’ye bölünürse gerçek alan bulunur.
*/
float arTriangle(Point a, Point b, Point c) {
    float x0 = a.GetX().toFloat();
    float x1 = b.GetX().toFloat();
    float x2 = c.GetX().toFloat();

    float y0 = a.GetY().toFloat();
    float y1 = b.GetY().toFloat();
    float y2 = c.GetY().toFloat();

    return fabs((x0 * (y1 - y2) + x1 * (y2 - y0) + x2 * (y0 - y1)) / 2);
}

/*
Bir Nokta Üçgenin İçinde mi? Nasıl Kontrol Edilir?
Adımlar:

Üçgenin alanı hesaplanır.
Kontrol edilecek nokta ile üçgenin köşeleri kullanılarak 3 yeni üçgen oluşturulur.
Bu üçgenlerin alanları toplanır.
Eğer toplam alan, orijinal üçgenin alanına eşitse ve alanlar sıfır değilse, nokta üçgenin içindedir.
Kısaca:

Nokta üçgenin kenarında veya köşesinde ise içeride sayılmaz.
Alanlar toplamı eşitse ve sıfır değilse içeridedir.

ar1, ar2, ar3 değerleri, kontrol edilen nokta ile üçgenin köşeleri kullanılarak oluşturulan 3 küçük üçgenin alanlarıdır.

Eğer bu üç alanın toplamı, orijinal üçgenin (totalArea) alanına eşitse ve hiçbiri sıfır değilse, nokta üçgenin içindedir.
Amaç: Noktanın üçgenin içinde mi, dışında mı olduğunu kesin olarak anlamak.
*/
bool bsp(Point const a, Point const b, Point const c, Point const point) {
    float totalArea = arTriangle(a, b, c);
    float ar1 = arTriangle(a, b, point); 
    float ar2 = arTriangle(a, c, point); 
    float ar3 = arTriangle(c, b, point);

    // Kenar veya köşede ise false
    if (ar1 == 0 || ar2 == 0 || ar3 == 0)
        return (false);

    // Alanlar toplamı eşitse içeride
    return ((ar1 + ar2 + ar3) == totalArea);
}

/*
BSP
Binary Space Partitioning (BSP)
"Binary Space Partitioning" (BSP), grafikler ve çarpışma algılama gibi alanlarda kullanılan bir teknik. 
Bu projede, bir üçgenin içinde bir noktanın olup olmadığını kontrol etmek için kullanılıyor.
Amaç: verilen bir noktanın bir üçgenin içinde olup olmadığını belirleyen bir sistem geliştirmek.
3 şey yapacağız; Fixed Sınıfı / Point Sınıfı / BSP Fonksiyonu
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

