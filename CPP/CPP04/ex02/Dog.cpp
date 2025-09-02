
#include "Dog.hpp"

Dog::Dog() : AAnimal() {
    this->type = "Dog";
    this->DogBrain = new Brain();
    std::cout << "Dog Default constructor called" << std::endl;
}

Dog::Dog(const Dog &other) : AAnimal(other) {
	std::cout << "Dog Copy constructor called" << std::endl;
    this->DogBrain = new Brain(*other.DogBrain);
}

Dog &Dog::operator=(const Dog &other) {
	std::cout << "Dog Copy assignment operator called" << std::endl;
    if (this != &other) {
        delete this->DogBrain;
        this->DogBrain = new Brain(*other.DogBrain);
    }
    return (*this);
}

Dog::~Dog() {
    delete this->DogBrain;
    std::cout << "Dog Destructor called" << std::endl;
}

Brain *Dog::getDogBrain(void) {
    return (this->DogBrain);
}

void Dog::makeSound(void) const{
    std::cout << "Hav Havvv" << std::endl;
}
