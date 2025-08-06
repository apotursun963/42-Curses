

#include "Fixed.hpp"

// Bu tam sayıyı, sabit noktalı (fixed-point) formata çeviriyor.
/*
num_int << fraction ifadesi, sayı değerini 8 bit sola kaydırır. 
Böylece sabit noktalı gösterime uygun şekilde saklanır.
*/
Fixed::Fixed(const int num_int) : fixed_point_value(num_int << fraction) {
  std::cout << "Int constructor called\n";
}

// Bu ondalıklı sayıyı sabit noktalı formata çeviriyor.
/*
num_flo * (1 << fraction) ile ondalık sayı 8 bit sola kaydırılır (yani 256 ile çarpılır). 
Sonra roundf fonksiyonu ile en yakın tam sayıya yuvarlanır ve tam sayı olarak saklanır.
*/
Fixed::Fixed(const float num_flo) : fixed_point_value(static_cast<int>(roundf(num_flo * (1 << fraction)))) {
  std::cout << "Float constructor called\n";
}

Fixed::Fixed() : fixed_point_value(0) { 
  std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
  std::cout << "Copy constructor called" << std::endl;
  *this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
  std::cout << "Copy assignment operator called" << std::endl;
  if (this == &other)   // Eğer bu iki nesne aynıysa, kendini kendine atamaya çalışıyorsun demektir. (a = a)
    return *this;
  this->setRawBits(other.getRawBits());   // Değeri kopyala
  return *this;
}

Fixed::~Fixed() {
  std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
  std::cout << "getRawBits member function called" << std::endl;
  return (fixed_point_value);
}

void Fixed::setRawBits(const int raw) {
  fixed_point_value = raw;
}


int Fixed::toInt(void) const {
  return (int(fixed_point_value) / int(1 << fraction));
}

float Fixed::toFloat(void) const {
  return (float(fixed_point_value) / float(1 << fraction));
}

// Bu bir operatör overload fonksiyonudur. << operatöürünü overload ediyor
/*
const Fixed &right:
Bu, ekrana yazdırmak istediğin sabit noktalı (fixed-point) sayı nesnesidir.
Fonksiyon, bu nesnenin sabit noktalı değeriyle ilgilenir.

right.toFloat():
Fixed nesnesinin float (ondalıklı sayı) temsilini elde eder.
out << ...:
Bu float değeri, çıktı akışına (örneğin ekrana veya dosyaya) yazılır.
return (out);:
Fonksiyonun sonunda, değiştirilmiş çıktı akışı geri döndürülür. Böylece zincirleme yazma işlemleri (std::cout << a << b << c;) yapılabilir.

kısacası, Fonksiyonun içinde, Fixed nesnesi float’a çevrilir ve akışa (out) yazılır.
*/
std::ostream &operator<<(std::ostream &out, const Fixed &right) {
  out << right.toFloat();
  return (out);
}

