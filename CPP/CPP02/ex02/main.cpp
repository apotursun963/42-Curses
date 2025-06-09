
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
    return 0;
}


/*
Bu egzersizde bizden istediği, Fixed sınıfına bu operatörleri “yeniden tanımlayarak” (overload ederek) 
sabit nokta sayılar (Fixed nesneleri) üzerinde şu işlemlerin yapılabilmesini sağlamak:
C++’ta bu operatörleri kendi sınıfınızın ihtiyaçlarına göre yeniden tanımlayıp “Fixed tipleri için geçerli” hâle getirmek demektir.
*/

