

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // const Animal* meta = new Animal();
    // const Animal* j = new Dog();
    // const Animal* i = new Cat();
    // std::cout << j->getType() << " " << std::endl;
    // std::cout << i->getType() << " " << std::endl;
    // i->makeSound(); //will output the cat sound!
    // j->makeSound();
    // meta->makeSound();

    // wrong animal  tests
    {
        const WrongAnimal *animal = new WrongAnimal();
        std::cout << "WrongAnimal type: " << animal->getType() << std::endl;
        animal->makeSound();
        delete animal;
    }

    {
		const WrongCat *cat = new WrongCat();
		std::cout << "WrongCat type: " << cat->getType() << std::endl;  // type wronganimal veriyor
		cat->makeSound();
		delete cat;
	}
    {   // wrong cat by wrong animal parent
        std::cout << "-- WrongCat by WrongAnimal parent class" << std::endl;
		const WrongAnimal *cat = new WrongCat();
		std::cout << "WrongAnimal type: " << cat->getType() << std::endl;
		cat->makeSound();
		delete cat;
    }
    return 0;
}


// int main(void)
// {
//     Animal *Animal1 = new Animal();     // Animal tipinde pointer, ve heap üzerinde Animal nesnesi oluştuyor.
//     Animal *i = new Dog();              // Animal tipinde pointer, ve heap üzerinde Dog nesnesi oluştuyor.
//     Animal *j = new Cat();              // Animal tipinde pointer, ve heap üzerinde Cat nesnesi oluştuyor.

//     /*
//     Pointer üst sınıf tipinde ama nesne alt sınıf tipinde olabilir.
//     Virtual fonksiyon ile çalışma zamanı bağlaması sağlanır.

//     - Polymorphism = "Aynı arayüz → farklı davranış"
//     - Compile-time → Overloading, operator overloading
//     - Run-time → virtual fonksiyonlar ve kalıtım
//     */
//     Animal1->makeSound();
//     i->makeSound();
//     j->makeSound();



//     return 0;
// }



/* ex00
Polymorphism (Çok Biçimlilik), aynı arayüzün farklı davranışlar gösterebilmesi demektir.
Yani bir fonksiyonun veya nesnenin, kullanıldığı yere göre farklı şekilde çalışabilmesi.


- Virtual fonksiyon → pointer/reference ile çağrıldığında gerçek nesne türüne göre çalışır (run-time polymorphism).
- Virtual değilse → pointer/reference tipine göre çalışır (compile-time binding).
- Alt sınıfta virtual yazmaya gerek yok, ama override yazmak iyi pratiktir (derleyici kontrol eder).
*/