

# CPP02/Ad-hoc polymorphism
Ad-hoc polymorphism, aynı isimli fonksiyonların farklı parametre türlerine göre farklı davranış göstermesidir.
function overloading (fonksiyon aşırı yükleme) ve operator overloading (operatör aşırı yükleme) ile karşımıza çıkar.
- Function Overloading: Aynı isimli fonksiyonun, farklı parametre türleri veya sayılarıyla tanımlanmasıdır.
- Operator Overloading: C++’taki +, -, == gibi operatörlerin farklı veri tipleri veya sınıflar için yeniden tanımlanmasıdır. Böylece, o operatörü kendi nesnelerin üzerinde istediğin gibi kullanabilirsin.
Özellikleri:
- Aynı isimli fonksiyonlar, farklı parametre tipleriyle tanımlanabilir.
- Hangi fonksiyonun çağrılacağı, çağrı anında parametre tiplerine göre belirlenir.
- Türler arasında otomatik bir dönüştürme veya ortak bir arayüz gerekmez.

funcs overloading
---
int add(int a, int b) {
    return a + b;
}

double add(double a, double b) {
    return a + b;
}


operator overloading
---
class Complex {
    // ...
};

Complex operator+(const Complex& a, const Complex& b) {
    // ...
}



# CPP03/Inheritance (Kalıtım)
Kalıtım: Inheritance, bir sınıfın başka bir sınıfın özelliklerini devralmasıdır. Kod tekrarını önler, hiyerarşi kurar.
Amaç: Kod tekrarını azaltmak, ortak özellikleri üst sınıfta tanımlayıp alt sınıflarda tekrar kullanmak.
Kalıtım Türleri
- public inheritance → Base’in public üyeleri derived’de public olur, protected üyeler protected kalır.
- protected inheritance → Base’in public ve protected üyeleri derived’de protected olur.
- private inheritance → Base’in public ve protected üyeleri derived’de private olur.


Kalıtım Kuralları:  PYTHON İÇİN
-Ebeveyn sınıftan miras alınan özellikler ve metodlar, çocuk sınıfta da kullanılabilir.
-Çocuk sınıf, ebeveyn sınıftan miras alınan özellikleri ve metodları değiştirebilir.
-Çocuk sınıf, ebeveyn sınıftan miras alınan özellikler ve metodları ek özellikler ve metodlarla genişletebilir.

