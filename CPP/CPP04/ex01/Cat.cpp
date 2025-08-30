
#include "Cat.hpp"

Cat::Cat() : Animal() {
    this->type = "Cat";
    this->CatBrain = new Brain();
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other) {
	std::cout << "Cat Copy constructor called" << std::endl;
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other)
        this->type = other.type;
    return (*this);
}

Cat::~Cat() {
    delete this->CatBrain;
    std::cout << "Cat Destructor called" << std::endl;
}

void Cat::makeSound(void) const {
    std::cout << "Meowwwww" << std::endl;
}
