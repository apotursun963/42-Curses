
#include "Animal.hpp"

Animal::Animal() {
    this->type = "Animal";
    std::cout << "Animal Default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {
	std::cout << "Animal Copy constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other) {
	std::cout << "Animal Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Animal::~Animal() {
    std::cout << "Animal Destructor called" << std::endl;
}

void    Animal::setType(std::string t) {
    this->type = t;
}

std::string Animal::getType() const{
    return (this->type);
}

void Animal::makeSound(void) const {
    std::cout << "Animal Sound" << std::endl;
}
