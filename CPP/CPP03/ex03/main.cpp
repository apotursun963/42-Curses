
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

int main(void)      // ekstra testlerde ekle
{
    DiamondTrap LA("Aloo");
    DiamondTrap RA;

    std::cout << "LA Name: " << LA.GetName() << std::endl;
    std::cout << "RA Name: " << RA.GetName() << std::endl;

    LA.attack(RA.GetName());
    std::cout << "LA energy: " << LA.GetEnergyPoints() << std::endl;

    RA.takeDamage(LA.GetAttackDamage());
    RA.beRepaired(3);

    LA.whoAmI();

    return 0;
}

/*
Hatalar

*/



/* ex03
Virtual Kullanımı: 
C++'da virtual inheritance (sanal kalıtım), bir temel sınıfın 
birden fazla kez miras alınmasını önlemek için kullanılır.
*/