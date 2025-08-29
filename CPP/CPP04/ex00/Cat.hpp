
#pragma once

#include "Animal.hpp"

class Cat : public Animal {
protected:
    std::string type;
public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    ~Cat();

    void    makeSound(void) const;

};