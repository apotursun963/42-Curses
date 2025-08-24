
#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string name) : ClapTrap() {
    this->SetName(name);
    this->SetHitPoints(100);
    this->SetEnergyPoints(50);
    this->SetAttackDamage(20);
    std::cout << "ScavTrap Constructor called" << std::endl;
}



ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(GetName()) {
    *this = other;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->SetName(other.GetName());
         = other.GetName();
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "Destructor called" << std::endl;
}

