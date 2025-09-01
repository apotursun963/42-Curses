
#include "Cat.hpp"

Cat::Cat() : AAnimal() {
    this->type = "Cat";
    this->CatBrain = new Brain();
    std::cout << "Cat Default constructor called" << std::endl;
}

Cat::Cat(const Cat &other) : AAnimal(other) {
    delete this->CatBrain;
	std::cout << "Cat Copy constructor called" << std::endl;
    this->CatBrain = new Brain(*other.CatBrain);
}

Cat &Cat::operator=(const Cat &other) {
	std::cout << "Cat Copy assignment operator called" << std::endl;
    if (this != &other) {
        delete this->CatBrain;
        this->CatBrain = new Brain(*other.CatBrain);
    }
    return (*this);
}

Cat::~Cat() {
    delete this->CatBrain;
    std::cout << "Cat Destructor called" << std::endl;
}

Brain *Cat::getCatBrain(void) {
    return (this->CatBrain);
}

void Cat::makeSound(void) const {
    std::cout << "Meowwwww" << std::endl;
}
