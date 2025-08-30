
#pragma once

#include <iostream>

class Animal {
protected:      // protected : Sadece Sınıf içerisinden ve Alt sınıflar tarafından erişilebilen değerlerdir.
    std::string type;

public:
    Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
    virtual ~Animal();  // virtual yapman gerekiyor yoksa delete yapmazsın

    virtual void    makeSound(void) const;    // virtual olmalı, böylece alt sınıflarda override edilebilir 

    std::string    getType(void) const;
};
