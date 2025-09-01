

#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "Brain.hpp"

int main() // leak var
{
    {
        Brain   brain1;;
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


/*
- Soyut sınıftan doğrudan nesne oluşturamazsın. AAnimal test;
- Soyut sınıftan türeyen ve tüm saf sanal fonksiyonları implement eden sınıflardan nesne oluşturabilirsin.
*/

/* ex01 (Abstract)
Amaç
AAnimal sınıfını soyut (abstract) bir sınıf yapmanız gerekiyor. Bu, AAnimal sınıfının doğrudan nesne oluşturulamayacağı anlamına gelir. 
Yani, AAnimal sınıfının bir örneği (instance) oluşturulamaz, ancak bu sınıftan türetilmiş alt sınıflardan (örneğin, Dog veya Cat) nesne oluşturulabilir.

- Soyut sınıf yapmak için AAnimal sınıfındaki bir veya daha fazla fonksiyonu saf sanal fonksiyon (pure virtual function) yapmalısınız. 
Bu, o fonksiyonların türetilmiş sınıflarda mutlaka implement edilmesi gerektiği anlamına gelir.
Örneğin: AAnimal sınıfına bir speak() fonksiyonu ekleyebilirsiniz ve bu fonksiyonu saf sanal yaparak, 
her AAnimal türünün kendi speak() fonksiyonunu implement etmesini sağlarsınız.


- Abstract Nedir ?
Bir soyut sınıf, doğrudan nesne oluşturulamayan bir sınıftır. Yani bu sınıf kendisi ile bir nesne oluşturulamaz, 
ancak bu sınıftan türetilen alt sınıflar kullanılarak nesneler oluşturulabilir.
Soyut sınıfların genellikle ortak bir temel sağlamak için kullanılır. 
Bir soyut sınıf, temel özellikleri ve fonksiyonları tanımlar, ancak bazı fonksiyonların alt sınıflar tarafından implement edilmesini zorunlu kılar.

Bir soyut fonksiyon ise, alt sınıflarda implement edilmesi gereken ve şu an bir vücut (yani fonksiyon gövdesi) içermeyen fonksiyondur. 
Bir soyut fonksiyon, bir sınıf içinde = 0 ile tanımlanır.

Soyut sınıflar ve fonksiyonlar, polimorfizm ve genişletilebilirlik sağlamada kullanılır. 
Örneğin, bir soyut sınıf AAnimal yaratabiliriz ve bu sınıf altında her hayvan türü (Dog, Cat) için özel davranışları implement edebiliriz.



- Polimerhism Nedir ?



*/
