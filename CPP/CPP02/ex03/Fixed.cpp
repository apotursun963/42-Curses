
#include "Fixed.hpp"

Fixed::Fixed(const int num_int) : fixed_point_value(num_int << fractional_bit) {
	// std::cout << "Int constructor called\n";
}

Fixed::Fixed(const float num_flo) : fixed_point_value(int(roundf(num_flo * (1 << fractional_bit)))) {
	// std::cout << "Float constructor called\n";
}

Fixed::Fixed() : fixed_point_value(0) {
  // std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) : fixed_point_value(other.fixed_point_value) {
  // std::cout << "Copy constructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &other) {
  // std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
        this->setRawBits(other.getRawBits());
    return *this;
}

Fixed::~Fixed() {
  // std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
  // std::cout << "getRawBits member function called" << std::endl;
  return (fixed_point_value);
}

void Fixed::setRawBits(const int raw) {
  fixed_point_value = raw;
}

int Fixed::toInt(void) const {
	return (int(fixed_point_value >> fractional_bit));	
}

float Fixed::toFloat(void) const {
	return (float(fixed_point_value) / (1 << fractional_bit));
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
	this->fixed_point_value += 1;
	return (*this);
}

Fixed Fixed::operator++(int) {
	Fixed duplicated(*this);
	operator++();
	return (duplicated);
}

Fixed &Fixed::operator--() {
	this->fixed_point_value -= 1;
	return (*this);
}

Fixed Fixed::operator--(int) {
	Fixed duplicated(*this);
	operator--();
	return (duplicated);
}

Fixed &Fixed::min(Fixed &Fixed1, Fixed &Fixed2) {
    if (Fixed1 < Fixed2)
        return (Fixed1);
    return (Fixed2);
}

const Fixed &Fixed::min(const Fixed &Fixed1, const Fixed &Fixed2) {
    if (Fixed1 < Fixed2)
        return (Fixed1);
    return (Fixed2);
}

Fixed &Fixed::max(Fixed &Fixed1, Fixed &Fixed2) {
	if (Fixed1 > Fixed2)
		return (Fixed1);
	return (Fixed2);
}

const Fixed &Fixed::max(const Fixed &Fixed1, const Fixed &Fixed2) {
	if (Fixed1 > Fixed2)
		return (Fixed1);
	return (Fixed2);
}

std::ostream &operator<<(std::ostream &out, const Fixed &right) {
	out << right.toFloat();
	return (out);
}
