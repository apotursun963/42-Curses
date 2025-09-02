
#pragma once

#include <iostream>

class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal &other);
    AAnimal &operator=(const AAnimal &other);
    virtual ~AAnimal();

    virtual void    makeSound(void) const = 0;
    std::string    getType(void) const;
};
