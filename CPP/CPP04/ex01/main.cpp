

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
        i->makeSound(); //will output the cat sound!
        j->makeSound();
        meta->makeSound();
        delete meta;
        delete i;
        delete j; 
    }

    
    // {
    //     std::cout << "<<<Wrong animal>>>\n";
    //     const WrongAnimal *animal = new WrongAnimal();
    //     std::cout << "WrongAnimal type: " << animal->getType() << std::endl;
    //     animal->makeSound();
    //     delete animal;
    // }
    // {
    //     std::cout << "<<<Wrong Cat>>>\n";
	// 	const WrongCat *cat = new WrongCat();
	// 	std::cout << "WrongCat type: " << cat->getType() << std::endl;  // type wronganimal veriyor
	// 	cat->makeSound();
	// 	delete cat;
	// }
    // {
    //     std::cout << "<<<Wrong cat by Wrong animal parent>>>\n";
	// 	const WrongAnimal *cat = new WrongCat();
	// 	std::cout << "WrongAnimal type: " << cat->getType() << std::endl;
	// 	cat->makeSound();
	// 	delete cat;
    // }
    return 0;
}




/* ex00
Polymorphism (Çok Biçimlilik), aynı arayüzün farklı davranışlar gösterebilmesi demektir.
Yani bir fonksiyonun veya nesnenin, kullanıldığı yere göre farklı şekilde çalışabilmesi.

Bu egzersizde ise, Parent (Animal) Bir sınıftan türeyen Classların (Dog, Cat) 
kendi makeSound() davranışlarını göstermeleri gerekiyor.
Ama eğer virtual keyword’ünü doğru kullanmazsan WrongAnimal & WrongCat örneğinde olduğu gibi yanlış davranışlar çıkacak.

Animal Sınıfındaki makeSound() Fonksiyonu virtual yaptığımız için bu sınıftan 
türeyen alt sınıflarda o fonksiyonu override edebiliyoruz. 
- virtual yoksa → fonksiyon çağrısı pointer’ın tipine göre yapılır (compile time).
- virtual varsa → fonksiyon çağrısı gerçek nesnenin tipine göre yapılır (runtime).
- Bu sayede Animal* a = new Cat(); dediğinde Cat::makeSound() çalışır.
- virtual olmazsa Animal::makeSound() çalışır (yanlış ses çıkar).
- Yani virtual, polymorphism’in gerçekleşmesini sağlar.

BİLGİ
- Virtual olan fonksiyonları delete ile direkt silemezsin
silebilmen için Parent destructure "virtual" olması gerekiıyormuş 


SORUN
- setType() funcs subjecte istemiyorlar
*/