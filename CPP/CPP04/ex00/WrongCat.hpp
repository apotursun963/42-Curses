


# pragma once
#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
protected:
    std::string type;

public:
    WrongCat();
    WrongCat(const WrongCat &other);
    WrongCat &operator=(const WrongCat &other);
    ~WrongCat();


    void    makeSound(void) const;
};

