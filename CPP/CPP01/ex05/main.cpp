
#include "Harl.hpp"

int main()
{
    Harl test;

    test.complain("DEBUG");
    test.complain("INFO");
    test.complain("WARNING");
    test.complain("ERROR");
}


/*
Bir sınıf (Harl) tanımlıyorsun.
Bu sınıfın içinde dört farklı seviye için (debug, info, warning, error) özel mesajlar yazan fonksiyonlar var.
Kullanıcıdan bir seviye ismi (ör: "DEBUG") alınıyor ve complain fonksiyonu çağrılıyor.
complain fonksiyonu, verilen seviyeye göre ilgili fonksiyonu çağırıyor. Bunu fonksiyon pointer dizisi ve string karşılaştırması ile yapıyor.


Fonksiyon İşaretçisi (pointer)
---
fonksiyon pointerı, bir fonksiyonun adresini tutan ve o fonksiyonu
çağırmanı sağlayan bir değişkendir. Yani, bir fonksiyonu sanki bir değişkenmiş gibi başka bir yere gönderebilir ve çağırabilirsi

void myFunction(); // Normal fonksiyon

void (*funcPtr)(); // Fonksiyon pointerı tanımı
funcPtr = &myFunction; // Adres atama (veya direkt myFunction)
funcPtr(); // Fonksiyon çağrılır

Fonksiyon pointerları, hangi fonksiyonun çağrılacağını dinamik olarak belirlemene olanak tanır. 
Özellikle çok sayıda benzer fonksiyonun olduğu durumlarda kodu sadeleştirir ve esnek hale getirir

*/