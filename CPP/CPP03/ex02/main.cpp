
#include "FragTrap.hpp"

int main(void)
{
    FragTrap Robot("memo");
    FragTrap Rakip("ahmet");

    Robot.attack("ahmet");
    std::cout << Robot.GetName() << " Energy: " << Robot.GetEnergyPoints() << std::endl;

    Rakip.takeDamage(Robot.GetAtacckDamage());
    std::cout << Rakip.GetName() << " hitPoints: " << Rakip.GetHitPoints() << std::endl;

    Rakip.beRepaired(3);
    std::cout << Rakip.GetName() << " hit points after repair: " << Rakip.GetHitPoints() << std::endl;

    Robot.highFivesGuys();

    return 0;
}
