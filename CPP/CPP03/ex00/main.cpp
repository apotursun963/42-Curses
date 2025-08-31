
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Robot("İyi");
    ClapTrap Target;

    std::cout << "Robot Name: " << Robot.GetName() << std::endl;
    std::cout << "Target Name: " << Target.GetName() << std::endl;

    for (int i=0; i < 11; i++)
        Robot.attack("Target");

    Target.takeDamage(10);
    Target.attack(Robot.GetName());

    Robot.attack(Target.GetName());
    Target.takeDamage(Robot.GetAtacckDamage());
    Target.beRepaired(3);
    std::cout << Target.GetName() << " HitPoints: " << Target.GetHitPoints() << std::endl;

    return 0;
}
