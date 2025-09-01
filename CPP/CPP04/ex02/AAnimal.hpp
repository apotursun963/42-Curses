
#pragma once

#include <iostream>

class AAnimal {
protected:
    std::string type;

public:
    AAnimal();
    AAnimal(const AAnimal &other);
    AAnimal &operator=(const AAnimal &other);
    virtual ~AAnimal();  // virtual yapman gerekiyor yoksa delete yapmazsın

    virtual void    makeSound(void) const = 0;
    /* pure virtual:
    bir sınıfın tamamen soyut (abstract) hale getirilmesi için kullanılır. 
    Bir fonksiyonun pure virtual olarak tanımlanması, bu fonksiyonun sadece bir prototip olduğunu, 
    yani alt sınıflarda mutlaka implementasyon (uygulama) yapılması gerektiğini ifade eder.
    */

    std::string    getType(void) const;
};
