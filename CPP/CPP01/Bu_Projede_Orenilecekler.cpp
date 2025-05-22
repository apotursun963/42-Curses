
/* namespaces (isim alanları)
Aynı isimde fonksiyonlar veya değişkenler farklı yerlerde kullanabiliriz.
*/

#include <iostream>

namespace my_print {
    void print() {          // funcs
        std::cout << "Benim Print'im" << std::endl;
    }
    int value = 7;         // Değişken
}

namespace your_print {
    void print() {          // funcs
        std::cout << "Senin Print'in" << std::endl;
    }
    int value = 10;         // Değişken
}

int main()
{
    my_print::print();
    your_print::print();

    std::cout << "my_print::Value: " << my_print::value << std::endl;
    std::cout << "your_print::Value: " << your_print::value << std::endl;

    return 0;
}


// --------------------------------

/* 
Class (Sınıf)
---
Class, Gerçek hayattaki bir nesneyi temsil eder.
Class, aynı özelliklere ve davranışlara sahip nesnelerin bir araya getirilmesini sağlayan bir yapıdır.
Örnek:
Bir araba düşün:
- Özellikleri: Marka, Renk, Hız
- Davranışları: Çalışır, Hızlanır, Fren yapar
Bu özellikleri ve davranışları bir araya getiren şey, class olur.


Member funcs
---
Sınıf içinde tanımlanan bir fonksiyonudur. Sadece o sınıftan oluşturulan nesnelerle birlikte çalışır.
Bu fonksiyona “üye fonksiyon” denir çünkü sınıfın üyesidir.


public ve private farkı
---
- public: Herkes erişebilir, Sınıfın dışından da kullanılabilir.
- Sadece sınıfın içinden erişilebilir, Dışarıdan direkt olarak erişmeye çalışırsan hata alırsın.
*/

#include <iostream>

class Car {
public:
    std::string brand;      // Özellik (Property)
    int hiz;                // Özellik (Property)

    void execute() {        // Member (üye) funcs 
        std::cout << brand << " Çalıştı.\n";
    }
};

int main() {
    Car benim_car;      // Nesne oluşturduk
    benim_car.brand = "BMW";
    benim_car.execute();
}


// ---------------

/* :: kullanımı
C++’de :: scope resolution operator yani alan çözümleme operatörüdür. 
Belirli bir isim veya elemanın hangi alanda (namespace, class vs.) olduğunu belirtmek için kullanılır.
*/

// 1. Namespace Üyesine Erişim
// 2. Sınıf Dışında Üye Fonksiyon Tanımlama
// 3. Global Değişkene Erişim   
