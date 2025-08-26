
#include "FragTrap.hpp"

int main(void)      // ekstra testlerde ekle
{
    FragTrap Robot("ali");
    FragTrap Ar("hadi bakalım");
    FragTrap LA;

    Ar = LA;


    // ClapTrap Robot("İyi");
    // ClapTrap Target;

    // std::cout << "Robot Name: " << Robot.GetName() << std::endl;
    // std::cout << "Robot Hit Points: " << Robot.GetHitPoints() << std::endl;
    // std::cout << "Ar Name: " << Ar.GetName() << std::endl;

    // // Enerji bitene kadar saldırı 
    // for (int i=0; i < 11; i++)
    //     Robot.attack("Target");

    // // Can Puanı Sıfır Olunca Salıdır
    // Target.takeDamage(10);
    // Target.attack("Robot");

    
    Robot.attack("LA");
    std::cout << "robot energy: " << Robot.GetEnergyPoints() << std::endl;
    LA.takeDamage(Robot.GetAtacckDamage());
    LA.beRepaired(3);

    Robot.highFivesGuys();

    return 0;
}



/* 



*/