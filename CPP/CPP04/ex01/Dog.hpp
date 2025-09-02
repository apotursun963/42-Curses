
#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {
private:
    Brain   *DogBrain;

public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog();

    void    makeSound(void) const;
    Brain   *getDogBrain(void);
};
