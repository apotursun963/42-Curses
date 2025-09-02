
#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{    
    {
        Brain   brain1;
        for (int i=0; i < 5; i++)
            std::cout << i + 1 << ". idea: " << brain1.getRandomIdea() << std::endl;
    }

    {
        const AAnimal *d = new Dog();
        const AAnimal *c = new Cat();
        d->makeSound();
        c->makeSound();
        std::cout << "Dog's Type: " << d->getType() << std::endl;
        std::cout << "Cat's Type: " << c->getType() << std::endl;
        delete d;
        delete c;
    }
    return 0;
}
