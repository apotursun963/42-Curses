
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{   
    {
        Brain   brain1;;
        for (int i=0; i < 5; i++)
            std::cout << i + 1 << ". idea: " << brain1.getRandomIdea() << std::endl;
    }
    
    {
        const Animal *d = new Dog();
        const Animal *c = new Cat();
        d->makeSound();
        c->makeSound();
        std::cout << "Dog's Type: " << d->getType() << std::endl;
        std::cout << "Cat's Type: " << c->getType() << std::endl;
        delete d;
        delete c;
    }
    
    {
        std::cout << "\n<<<Copy types>>>\n";
    
        Cat *i = new Cat();
        Cat *cat2 = new Cat(*i);
        std::cout << "address of cat2's Brain: " << cat2->getCatBrain() << std::endl;
        std::cout << "address of i's Brain:    " << i->getCatBrain() << std::endl;
        delete cat2;
        delete i;

        Dog* j = new Dog();
        Dog* dog2 = new Dog();
        *dog2 = *j;
        std::cout << "address of dog2's Brain: " << dog2->getDogBrain() << std::endl;
        std::cout << "address of j's Brain:    " << j->getDogBrain() << std::endl;
        delete dog2;
        delete j;
    }
    {   
        int size = 8;
        Animal *animals[size];

        for (int i=0; i < size / 2; i++)
            animals[i] = new Dog();
        for (int i = size / 2; i < size; i++)
            animals[i] = new Cat();
        std::cout << "<<<SOUNDS>>>" << std::endl;
        for (int i=0; i < size; i++)
            animals[i]->makeSound();
        std::cout << "<<<CLEAN>>>" << std::endl;
        for (int i=0; i < size; i++)
            delete animals[i];
    }
    return 0;
}
