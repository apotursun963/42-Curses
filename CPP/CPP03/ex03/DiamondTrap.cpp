
#include "DiamondTrap.hpp"
/*
DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
demek, DiamondTrap oluşturulurken FragTrap ve ScavTrap constructor’larını özellikle çağırmak demektir.
*/
DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap() {
    this->name = "tursun";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name)
    :  ClapTrap(name), FragTrap(name), ScavTrap(name) {
    this->name = name;
    ClapTrap::name = name + "_clap_name";
    this->hitPoints = 100;
    this->energyPoints = 50;
    this->attackDamage = 30;
    std::cout << "DiamondTrap Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(DiamondTrap const &other) : ClapTrap(other), FragTrap(other), ScavTrap(other) {
    *this = other;
    std::cout << "DiamondTrap Copy Constructor called" << std::endl;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other) {
	std::cout << "DiamondTrap Copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

std::string DiamondTrap::GetName(void) {
    return (this->name);
}

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void) {
    std::cout << "my name is: " << this->name << " and my grandfather name is: " << ClapTrap::name << std::endl;    // _clap_name diye vermiyor
}

int DiamondTrap::GetAttackDamage() {
    return this->attackDamage;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}
