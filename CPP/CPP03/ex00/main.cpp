
#include "ClapTrap.hpp"

int main(void)      // ekstra testlerde ekle
{
    ClapTrap Robot("İyi");
    ClapTrap Target;

    std::cout << "Robot Name: " << Robot.GetName() << std::endl;
    std::cout << "Target Name: " << Target.GetName() << std::endl;

    // Enerji bitene kadar saldırı 
    for (int i=0; i < 11; i++)
        Robot.attack("Target");

    // Can Puanı Sıfır Olunca Salıdır
    Target.takeDamage(10);
    Target.attack("Robot");

    
    Robot.attack("Target");
    Target.takeDamage(Robot.GetAtacckDamage());
    Target.beRepaired(3);

    return 0;
}



/* CPP03
Proje Amacı:
Bizden bir robot sınıfı (ClapTrap) yazmamız isteniliyor. 
ve bu robotun canı, enerjisi, kendini onarma ve saldırı davranışları (funcs) olsun ve her hareketini ekrana yazsın.


- Saldırı → ClapTrap saldırdığında, hedefin (target) can puanı (hit points) ClapTrap’in attackDamage değeri kadar azalıyor.
- Onarma → ClapTrap kendini onardığında, can puanı (hit points) belirtilen miktar (amount) kadar artıyor.
- Enerji kullanımı → Her saldırı veya onarma işlemi 1 enerji puanı (energy point) harcıyor.
- Sınırlama → ClapTrap’in can puanı 0 veya enerji puanı 0 ise hiçbir şey yapamaz (saldıramaz, onaramaz).

Bu alıştırmalarda ClapTrap nesneleri birbirleriyle savaşmayacak. 
Yani parametrelerde başka bir ClapTrap nesnesi kullanılmayacak; sadece ekrana yazdırma gibi simülasyon yapılacak.

*/
