
#include "ClapTrap.hpp"

int main(void)      // ekstra testlerde ekle
{
    ClapTrap Robot("İyi");
    ClapTrap Target;

    std::cout << "Robot Name: " << Robot.GetName() << std::endl;
    std::cout << "Target Name: " << Target.GetName() << std::endl;

    // Enerji bitene kadar saldırı 
    // for (int i=0; i < 11; i++)
    //     Robot.attack("Target");

    // Can Puanı Sıfır Olunca Salıdır
    // Target.takeDamage(10);
    // Target.attack("Robot");

    Robot.attack("Target");
    Target.takeDamage(Robot.GetAtacckDamage());
    Target.beRepaired(3);
    std::cout << "Targt HitPoints: " << Target.GetHitPoints() << std::endl;

    return 0;
}



/* CPP03
Proje Amacı:
Bizden bir robot sınıfı (ClapTrap) yazmamız isteniliyor. 
ve bu robotun canı, enerjisi, kendini onarma ve saldırı davranışları (funcs) olsun ve her hareketini ekrana yazsın.


Bu alıştırmalarda ClapTrap nesneleri birbirleriyle savaşmayacak.
Yani parametrelerde başka bir ClapTrap nesnesi kullanılmayacak; sadece ekrana yazdırma gibi simülasyon yapılacak.
*/
