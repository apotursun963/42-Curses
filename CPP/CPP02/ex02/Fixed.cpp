
// Yorumları silecekmisin yoksa kalacakmı iyice öğren
#include "Fixed.hpp"

Fixed::Fixed(const int num_int)   // Bu tam sayıyı, sabit noktalı (fixed-point) formata çevirsin.
    : value(num_int * int(1 << fractionalBits) + (num_int >= 0 ? 0.5 : -0.5)) {
  // std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num_flo)   // Bu ondalıklı sayıyı sabit noktalı formata çevirsin.
    : value(num_flo * float(1 << fractionalBits) + (num_flo >= 0 ? 0.5 : -0.5)) {
  // std::cout << "Float constructor called\n";
}


Fixed::Fixed() : value(0) { 
  // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : value(other.value) {
  // std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
  // std::cout << "Copy assignment operator called" << std::endl;
  if (this == &other)   // Eğer bu iki nesne aynıysa, kendini kendine atamaya çalışıyorsun demektir. (a = a)
    return *this;
  this->setRawBits(other.getRawBits());   // Değeri kopyala
  return *this;
}

Fixed::~Fixed() {
  // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called" << std::endl;
  return (value);
}

void Fixed::setRawBits(const int raw) {
  value = raw;
}

int Fixed::toInt(void) const {
  return (int(value) / int(1 << fractionalBits));
}

float Fixed::toFloat(void) const {
  return (float(value) / float(1 << fractionalBits));
}


bool Fixed::operator>(const Fixed &other) const {
  return this->toFloat() > other.toFloat();
}

bool Fixed::operator<(const Fixed &other) const {
  return this->toFloat() < other.toFloat();
}

bool Fixed::operator>=(const Fixed &other) const {
  return this->toFloat() >= other.toFloat();
}

bool Fixed::operator<=(const Fixed &other) const {
  return this->toFloat() <= other.toFloat();
}

bool Fixed::operator==(const Fixed &other) const {
  return this->toFloat() == other.toFloat();
}

bool Fixed::operator!=(const Fixed &other) const {
  return this->toFloat() != other.toFloat();
}

Fixed Fixed::operator+(const Fixed &other) const {
  return this->toFloat() + other.toFloat();
}

Fixed Fixed::operator-(const Fixed &other) const {
  return this->toFloat() - other.toFloat();
}

Fixed Fixed::operator*(const Fixed &other) const {
  return this->toFloat() * other.toFloat();
}

Fixed Fixed::operator/(const Fixed &other) const {
  return this->toFloat() / other.toFloat();
}

Fixed &Fixed::operator++() {
  this->value += 1;
  return *this;
}

Fixed Fixed::operator++(int) {
  Fixed duplicated(*this);
  operator++();
  return duplicated;
}

Fixed &Fixed::operator--() {
  this->value -= 1;
  return *this;
}

Fixed Fixed::operator--(int) {
  Fixed duplicated(*this);
  operator--();
  return duplicated;
}

Fixed &Fixed::min(Fixed &Fixed1, Fixed &Fixed2) {
  return (Fixed1 < Fixed2 ? Fixed1 : Fixed2);
}

const Fixed &Fixed::min(const Fixed &Fixed1, const Fixed &Fixed2) {
  return (Fixed1 < Fixed2 ? Fixed1 : Fixed2);
}

Fixed &Fixed::max(Fixed &Fixed1, Fixed &Fixed2) {
  return (Fixed1 > Fixed2 ? Fixed1 : Fixed2);
}

const Fixed &Fixed::max(const Fixed &Fixed1, const Fixed &Fixed2) {
  return (Fixed1 > Fixed2 ? Fixed1 : Fixed2);
}


// Bu bir operatör overload fonksiyonudur.
std::ostream &operator<<(std::ostream &out, const Fixed &right) {
  out << right.toFloat();
  return (out);
}
