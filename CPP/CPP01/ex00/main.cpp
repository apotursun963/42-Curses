

#include "Zombie.hpp"

int main() {
    Zombie *Zombie1 = newZombie("atursun"); // Heap'te oluştur
    Zombie1->announce();                    // Kendini tanıt
    randomChump("abdullah");                // Stack'te oluştur ve tanıt
    delete Zombie1;                          // Heap'teki zombiyi manual olarak sil
    return 0;
}


/*
ex00 Açıklaması: Basit Zombie Sınıfı ve Bellek Yönetimi
----

İki Farklı Nesne Zombie Oluşturma Yöntemi:
- Heap’te (dinamik bellek): newZombie fonksiyonu ile.
- Stack’te (otomatik ömür): randomChump fonksiyonu ile.

new: Heap’te (dinamik bellek) nesne oluşturur. malloc gibi
delete: Heap’te oluşturulan nesneyi siler ve belleği geri verir. free gibi 

Stack: Otomatik ömürlü nesneler (ör: fonksiyon içinde direkt oluşturulan Zombie). Scope bitince otomatik silinir.
Heap: Dinamik ömürlü nesneler (ör: new ile oluşturulan Zombie). delete ile manuel silinmeli.
*/
