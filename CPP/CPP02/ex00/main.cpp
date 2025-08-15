
#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed b(a);     // copy constructure: Yeni bir nesne doğar ve diğeriyle aynı veriye sahip olur.
    Fixed c;

    c = b;          // Kopya atama operatörü: Zaten var olan bir nesne başka bir nesneyle aynı veriyle güncellenir.
                    // ikisin farkı: Her ikisi de kopyalama yapar ama biri yeni nesne yaratır, diğeri var olan nesneyi günceller.
    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
}


/*
Fixed-point numbers (sabit noktalı sayılar)
---
Bu alıştırmada, C++’da sabit noktalı (fixed-point) bir sayı "tipini" temsil eden bir sınıf yazmanız isteniyor. 
Sabit noktalı sayılar, performans, doğruluk, aralık ve hassasiyet açısından güzel bir denge sunar ve grafik, 
ses veya bilimsel programlama gibi alanlarda oldukça kullanışlıdır. C++’da yerleşik olarak sabit noktalı 
sayı tipi bulunmadığı için, siz bu özelliği ekleyeceksiniz.


Ayrıca bu sınıf, C++’ta "Orthodox Canonical Form" denilen 4 temel kuralı içermelidir:
- Default constructor (varsayılan yapıcı)
- Copy constructor (kopya yapıcı)
- Copy assignment operator (kopya atama operatörü)
- Destructor (yıkıcı)
C++’ta olmayan bir "sayı türü" olan fixed-point number'ı kendi sınıfınla oluşturuyorsun.

*/

