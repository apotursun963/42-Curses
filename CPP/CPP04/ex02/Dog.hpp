
#pragma once

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal {
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
