
#pragma once

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {
private:
    Brain *CatBrain;

public:
    Cat();
    Cat(const Cat &other);
    Cat &operator=(const Cat &other);
    ~Cat();

    void    makeSound(void) const;
    Brain   *getCatBrain(void);

};
