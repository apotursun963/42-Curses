
#include "DiamondTrap.hpp"
#include "ClapTrap.hpp"

int main(void)
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
