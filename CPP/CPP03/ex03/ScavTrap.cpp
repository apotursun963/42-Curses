
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->SetName("tursun");
    this->SetHitPoints(100);
    this->SetEnergyPoints(50);
    this->SetAttackDamage(20);
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->SetName(name);
    this->SetHitPoints(100);
    this->SetEnergyPoints(50);
    this->SetAttackDamage(20);
    std::cout << "ScavTrap Constructor called" << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
    *this = other;
    std::cout << "ScavTrap Copy Constructor called" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	std::cout << "ScavTrap Copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

ScavTrap::~ScavTrap() {
    std::cout << "ScavTrap Destructor called" << std::endl;
}


void ScavTrap::attack(const std::string& target) {
    if (GetEnergyPoints() <= 0) {
        std::cout << "ScavTrap " << GetName() << " does not have enough energy to attack :(" << std::endl;
        return ;
    }
    if (GetHitPoints() <= 0) {
        std::cout << "ScavTrap " << GetName()<< " is dead can't attack :(" << std::endl;
        return ;
    }
    SetEnergyPoints(GetEnergyPoints() - 1);
    std::cout << "ScavTrap " << GetName()
              << " attacks " << target
              << ", causing " << GetAtacckDamage()
              << " points of damage!" << std::endl;
}


void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << GetName() << " is now in Gate keeper mode" << std::endl;
}
