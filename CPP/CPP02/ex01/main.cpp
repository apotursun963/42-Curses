
#include "Fixed.hpp"

int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );

    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}

/*
Bir önceki egzersizde yaptığın Fixed sınıfını daha kullanışlı hale getireceksin. 
Şu anda sınıf sadece 0.0 değerini tutabiliyor, bunu değiştireceksin.

Yapman gerekenler:

1. Yeni yapıcılar (constructor) ekle:
- int parametre alan bir constructor → Bu int değeri fixed-point formata çevir.
- float parametre alan bir constructor → Bu float değeri fixed-point formata çevir. 
    (Her iki durumda da fractional bits değeri 8 olacak, tıpkı exercise 00’da olduğu gibi.)

2. Yeni üye fonksiyonlar ekle:
- float toFloat(void) const; → Fixed-point değeri float olarak döndür.
- int toInt(void) const; → Fixed-point değeri int olarak döndür.

Operator overload ekle:
- << (insertion operator) overload’u → std::cout << fixedPointObj; şeklinde kullanıldığında sayının 
float karşılığını ekrana yazdırmalı.

*/

/*
bu egzersizdeki amacımız << operatöünü "overload" etmek

Bu egzersizde, Fixed sınıfına (class)
tam sayı (int) ve ondalıklı sayı (float) değerleriyle çalışabilecek yeni özellikler ekleyeceksin.




Overload (Aşırlı Yükleme):
bir fonksiyonu veya operatörü yeniden tanımlamak
*/