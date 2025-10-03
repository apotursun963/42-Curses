

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <cstdlib>  // rand()
#include <iostream> 
#include <ctime> 

/* Görevi
- A, B veya C sınıflarından bir nesne yaratıp Base* olarak döndüyor.
*/
Base    *generate(void) {

    Base    *pointer;
    srand(time(NULL));           // her seferinde yeni numara döndüyor
    int     random = rand() % 3;        // rand() 0 ile rand_max arası sayı üretir.

    if (random == 0) {
        pointer = new A;
        std::cout << "A Object Created" << std::endl;
    }
    if (random == 1) {
        pointer = new B;
        std::cout << "B Object Created" << std::endl;
    }
    if (random == 2) {
        pointer = new C;
        std::cout << "C Object Created" << std::endl;
    }
    return (pointer);
}

/*
- Bu fonksiyon, kendisine gelen Base işaretçisinin gerçekte hangi türe ait olduğunu bulur.
örnke, p bir A nesnesini işaret ediyorsa, "A" yazdırır.
Kısacası, Pointer üzerinden nesnenin gerçek tipini yazdırıyor

Açıklamak
- p işaretçisi sırasıyla A*, B*, C*’ye dönüştürülmeye çalışılıyor.
- Başarılı olan dönüşüm nullptr değil, o zaman tip ekrana yazdırılıyor.
- Örneğin p aslında bir B nesnesini işaret ediyorsa:
    - B* (başarılı)
*/
void    identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "Type: A" << std::endl;
    if (dynamic_cast<B*>(p))
        std::cout << "Type: B" << std::endl;
    if (dynamic_cast<C*>(p))
        std::cout << "Type: C" << std::endl;
}

/*
Bu fonksiyon, pointer kullanmadan referans üzerinden nesnenin türünü bulmalı.
Kısacası, Referans üzerinden nesnenin gerçek tipini yazdırıyor, pointer yasak
*/
void    identify(Base& p) {

    try {
        A &a = dynamic_cast<A&>(p);
        (void)a;
        std::cout << "Type: A" << std::endl;
    }
    catch (std::exception &e) {}
    try {
        B &b = dynamic_cast<B&>(p);
        (void)b;
        std::cout << "Type: B" << std::endl;
    }
    catch (std::exception &e) {}
    try {
        C &c = dynamic_cast<C&>(p);
        (void)c;
        std::cout << "Type: C" << std::endl;
    }
    catch (std::exception &e) {}
}



int main(void)
{
    Base    *inst = generate();
    
    identify(inst);
    identify(*inst);
    return 0;
}
