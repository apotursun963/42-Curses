
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    {
        const Animal* meta = new Animal();
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        std::cout << j->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete i;
        delete j;
    }

    {
        std::cout << "\n<<<Wrong animal>>>\n";
        const WrongAnimal *animal = new WrongAnimal();
        std::cout << "WrongAnimal type: " << animal->getType() << std::endl;
        animal->makeSound();
        delete animal;
    }

    {
        std::cout << "\n<<<Wrong Cat>>>\n";
		const WrongCat *cat = new WrongCat();
		std::cout << "WrongCat type: " << cat->getType() << std::endl;
		cat->makeSound();
		delete cat;
	}

    {
        std::cout << "\n<<<Wrong cat by Wrong animal parent>>>\n";
		const WrongAnimal *cat = new WrongCat();
		std::cout << "WrongAnimal type: " << cat->getType() << std::endl;
		cat->makeSound();
		delete cat;
    }
    return 0;
}
