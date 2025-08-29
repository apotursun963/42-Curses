

# pragma once
#include <iostream>

// Amaç: virtual olmadan ne olur göster
// WrongCat → WrongAnimal’ın makeSound() fonksiyonunu çağırır, override etmez
class WrongAnimal {
protected:              // protected → alt sınıf erişebilir
    std::string type;

public:
    WrongAnimal();
    WrongAnimal(const WrongAnimal &other);
    WrongAnimal &operator=(const WrongAnimal &other);
    ~WrongAnimal();

    void    makeSound(void) const;

    std::string     getType(void) const;
};
