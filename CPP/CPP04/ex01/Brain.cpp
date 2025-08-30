
#include "Brain.hpp"

Brain::Brain() { 
    std::cout << "Brain Default constructor called" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain Copy constructor called" << std::endl;
    int size_of_arr = sizeof(ideas[0]) / sizeof(ideas);
    for (int i=0; i < size_of_arr; i++)
        this->ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other) {
	std::cout << "Brain Copy assignment operator called" << std::endl;
    if (this != &other) {
        int size_of_arr = sizeof(ideas[0]) / sizeof(ideas);
        for (int i=0; i < size_of_arr; i++)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

Brain::~Brain() {
    std::cout << "Brain Destructor called" << std::endl;
}

