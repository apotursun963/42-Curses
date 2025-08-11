

#include "Zombie.hpp"

int main()
{
    Zombie *Zombie1 = zombieHorde(4, "atursun");
    Zombie1[0].announce();
    Zombie1[1].announce();
    Zombie1[2].announce();
    Zombie1[3].announce();
    delete[] Zombie1;
    return 0;
}






/*
Tek seferde N adet Zombie nesnesini dinamik olarak oluşturup hepsine
aynı adı ver, bu diziyi döndür, 
sonra her birinin announce() metodunu çağırarak 
doğru çalıştığını gör ve 
iş bitince delete[] ile bellek sızıntısı olmadan temizle.
*/
