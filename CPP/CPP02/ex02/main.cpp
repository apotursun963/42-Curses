
#include "Fixed.hpp"

int main(void) {
    Fixed a;
    Fixed const b(Fixed(5.05f) * Fixed(2));

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << Fixed::max(a, b) << std::endl;

    // örnek operator > kullanmak (bunları sil pushlarken)
    std::cout << "--TEST--\n";
    Fixed f(5.7f);
    Fixed r(1.5f);

    f = 2 * 10;
    r++;
    std::cout << f << "\n";
    std::cout << r << "\n";
    if (f > r)
        std::cout << "f > r\n";
    else
        std::cout << "r > f\n";

    Fixed const h(7);
    Fixed const l(8);

    // h = 89;     değişken const olduğu için değer atamazsın
    std::cout << Fixed::min(h, l) << "\n";
    
    return 0;
}


/*
Bu egzersizde senden istenen şey, Fixed sınıfını genişletip C++’ta operator overloading yaparak, 
fixed-point sayıların karşılaştırma, aritmetik ve artırma/azaltma işlemlerini destekleyen bir sınıf haline getirmek.
*/
