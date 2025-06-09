
#include "Fixed.hpp"

int main() {
    Fixed a;
    Fixed b(a);
    Fixed c;

    c = b;

    std::cout << a.getRawBits() << std::endl;
    std::cout << b.getRawBits() << std::endl;
    std::cout << c.getRawBits() << std::endl;
}


/*
Fixed-point numbers (sabit noktalı sayılar)
---
Bu egzersizde senden, C++ dilinde "sabit noktalı sayı" (fixed-point number) temsil eden bir sınıf yazman isteniyor.
Ayrıca bu sınıf, C++’ta "Orthodox Canonical Form" denilen 4 temel kuralı içermelidir:
- Default constructor (varsayılan yapıcı)
- Copy constructor (kopya yapıcı)
- Copy assignment operator (kopya atama operatörü)
- Destructor (yıkıcı)
C++’ta olmayan bir sayı türü olan fixed-point number'ı kendi sınıfınla oluşturuyorsun.
*/
