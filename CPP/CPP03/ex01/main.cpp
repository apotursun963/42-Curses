
#include "ScavTrap.hpp"

int main(void)      // ekstra testlerde ekle
{
    ScavTrap Robot("ali");
    ScavTrap Ar("batur");
    ScavTrap LA;

    Ar = LA;

    std::cout << "Robot Name: " << Robot.GetName() << std::endl;
    std::cout << "Ar Name: " << Ar.GetName() << std::endl;

    Robot.attack("AR");
    std::cout << "robot energy: " << Robot.GetEnergyPoints() << std::endl;
    Ar.takeDamage(Robot.GetAtacckDamage());
    Ar.beRepaired(3);

    Robot.guardGate();

    return 0;
}



/* ex01

Kalıtım Burada balşıyıor 
Temelde ClapTrap Sınıfından miras (constructors, destructor) alan bir ScavTrap sınıfı yapmamız isteniliyro.
Ancak, constructors, destructor ve attack() fonksiyonu farklı mesajlar yazdıracak.

Testlerinde doğru kurucu/yıkıcı zincirlemenin (construction/destruction chaining) gösterilmesi 
gerektiğine dikkat et

Bir ScavTrap oluşturulduğunda, program önce bir ClapTrap inşa etmeye başlar.
Yıkım (destruction) ise ters sırada gerçekleşir. Neden?

ScavTrap, ClapTrap’in özelliklerini kullanacak (buna göre ClapTrap’i güncelle) ve şu değerlerle başlatılmalıdır:
- İsim: constructor’a parametre olarak verilecek.
- Can (Hit points): 100
- Enerji (Energy points): 50
- Saldırı gücü (Attack damage): 20

ScavTrap’in ayrıca kendine özgü özel bir yeteneği olacak:
- void guardGate();
Bu üye fonksiyonu, ScavTrap’in artık Kapı Bekçisi Modunda (Gate keeper mode) olduğunu belirten bir mesaj gösterecek.


Özetle, ClapTrap’ten miras alan ScavTrap sınıfı yapıyorsun. 
Varsayılan değerleri farklı (100 can, 50 enerji, 20 hasar) ve ayrıca guardGate() isminde ekstra bir yeteneği var.


*/