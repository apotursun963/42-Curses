
#include "Dog.hpp"

Dog::Dog() : Animal() {
    this->setType("Dog");
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other) {
	std::cout << "Dog Copy constructor called" << std::endl;
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Dog::~Dog() {
    std::cout << "Dog Destructor called" << std::endl;
}

void Dog::makeSound(void) const{
    std::cout << "Hav Havvv" << std::endl;
}
