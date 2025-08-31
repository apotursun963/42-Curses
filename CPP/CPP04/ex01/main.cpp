

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main()
{
    {
        const Animal* meta1 = new Animal();
        const Animal* meta2 = meta1;
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        const Animal* Dog(j);
        std::cout << Dog->getType() << " " << std::endl;
        std::cout << i->getType() << " " << std::endl;
        i->makeSound();
        Dog->makeSound();
        meta1->makeSound();
        meta2->makeSound();
        delete meta1;
        delete i;
        delete Dog; 
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




/* ex01

Amaç:
1. Brain Adında bir sınıf yazmak, içinde 100 elemanlı bir bir "ideas" dizisi
2. Dog ve Cat Sınıflarına private olarak "Brain* <değişken ismi>"ekliycez.
3. Dog ve Cat Oluşturulurken (constructure) "new Brain()" ile heap'te dinamik olarak Brain oluşturacaktır.
4. Dog ve Cat Silinirken (Destructure) "delete" yapılacaktır. 

Test
- main içinde bir Animal* dizisi oluşturacaksın.
- Yarısı Dog, yarısı Cat olacak.
- Program bitiminde hepsini delete edeceksin → doğru destructor sırası çalışmalı

Kavramlar
- Deep/Shall Copies: bunun ne olduğnu öğren detaylıca çünkü testlerde leak çıkabiliyorumuş



*/
