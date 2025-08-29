

#pragma once

#include "Animal.hpp"

class Dog : public Animal {
protected:
    std::string type;
public:
    Dog();
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog();

    void    makeSound(void) const;
};
