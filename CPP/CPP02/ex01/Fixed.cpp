

#include "Fixed.hpp"

Fixed::Fixed() : fixed_point_value(0) { 
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed &Fixed::operator=(const Fixed &other) {
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)                 
		this->setRawBits(other.getRawBits());
	return *this;
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const {
	// std::cout << "getRawBits member function called" << std::endl;
	return (fixed_point_value);
}

void Fixed::setRawBits(const int raw) {
	fixed_point_value = raw;
}


Fixed::Fixed(const int num_int) : fixed_point_value(num_int << fractional_bit) {	
	std::cout << "Int constructor called\n";
}

int Fixed::toInt(void) const {
	return (int(fixed_point_value >> fractional_bit));		
}

Fixed::Fixed(const float num_flo) : fixed_point_value(int(roundf(num_flo * (1 << fractional_bit)))) {
	std::cout << "Float constructor called\n";
}

float Fixed::toFloat(void) const {
	return (float(fixed_point_value) / (1 << fractional_bit));
}

std::ostream &operator<<(std::ostream &out, const Fixed &right) {
	out << right.toFloat();
	return (out);
}

