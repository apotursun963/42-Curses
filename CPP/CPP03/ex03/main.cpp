
#include "DiamondTrap.hpp"

int main(void)      // ekstra testlerde ekle
{

    DiamondTrap LA("Aloo");
    DiamondTrap RA;


    std::cout << "LA Name: " << LA.GetName() << std::endl;
    // std::cout << "Robot Hit Points: " << Robot.GetHitPoints() << std::endl;
    std::cout << "RA Name: " << RA.GetName() << std::endl;

    // // Enerji bitene kadar saldırı 
    // for (int i=0; i < 11; i++)
    //     Robot.attack("Target");

    // // Can Puanı Sıfır Olunca Salıdır
    // Target.takeDamage(10);
    // Target.attack("Robot");

    
    LA.attack("RA");
    std::cout << "LA energy: " << LA.GetEnergyPoints() << std::endl;
    RA.takeDamage(LA.GetAtacckDamage());
    RA.beRepaired(3);

    LA.whoAmI();

    return 0;
}



/* ex03

Virtual Kullanımı: 
C++'da virtual inheritance (sanal kalıtım), bir temel sınıfın 
birden fazla kez miras alınmasını önlemek için kullanılır.



*/