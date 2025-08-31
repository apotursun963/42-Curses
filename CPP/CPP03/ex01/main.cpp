
#include "ScavTrap.hpp"

int main(void)
{
    ScavTrap Robot("ali");
    ScavTrap Ar("batur");
    ScavTrap LA;

    Ar = LA;

    std::cout << "Robot Name: " << Robot.GetName() << std::endl;
    std::cout << "Ar Name: " << Ar.GetName() << std::endl;

    Robot.attack(Ar.GetName());
    std::cout << Robot.GetName() << " Energy: " << Robot.GetEnergyPoints() << std::endl;
    Ar.takeDamage(Robot.GetAtacckDamage());
    Ar.beRepaired(3);

    Robot.guardGate();

    return 0;
}
