
#pragma once

#include <iostream>

class Animal {
protected:      // protected : 
    std::string type;

public:
    Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    ~Animal();

    virtual void    makeSound(void) const;    // virtual olmalı, böylece alt sınıflarda override edilebilir 

    void           setType(std::string t);
    std::string    getType(void) const;
};
