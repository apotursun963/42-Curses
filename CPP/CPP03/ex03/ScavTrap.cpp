
#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    this->name = "tursun";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
    std::cout << "ScavTrap Default Constructor called" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
    this->name = name;
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 20;
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
    if (this->energyPoints <= 0) {
        std::cout << "ScavTrap " << this->name << " does not have enough energy to attack :(" << std::endl;
        return ;
    }
    if (this->hitPoints <= 0) {
        std::cout << "ScavTrap " << this->name << " is dead can't attack :(" << std::endl;
        return ;
    }
    this->energyPoints -= 1;
    std::cout << "ScavTrap " << this->name     // Aloo_clap_name diye çıktı veriyor normalde nasıl vermesi gerekiyor öğren
              << " attacks " << target
              << ", causing " << this->attackDamage
              << " points of damage!" << std::endl;
}

void ScavTrap::guardGate() {
    std::cout << "ScavTrap " << this->name << " is now guarding the gate" << std::endl;
}
