
#include "DiamondTrap.hpp"
/*
DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap()
demek, DiamondTrap oluşturulurken FragTrap ve ScavTrap constructor’larını özellikle çağırmak demektir.
*/
DiamondTrap::DiamondTrap() : FragTrap(), ScavTrap() {
    this->SetName("tursun");
    this->SetHitPoints(FragTrap::GetHitPoints());
    this->SetEnergyPoints(ScavTrap::GetEnergyPoints());
    this->SetAttackDamage(FragTrap::GetAtacckDamage());
    std::cout << "DiamondTrap Default Constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) 
    : ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name), name(name) {
    this->SetHitPoints(FragTrap::GetHitPoints());
    this->SetEnergyPoints(ScavTrap::GetEnergyPoints());
    this->SetAttackDamage(FragTrap::GetAtacckDamage());
    std::cout << "DiamondTrap Constructor called" << std::endl;
}

// burada 3 tane farklı sınıftan çağırıyoson ama temlde hepsi ClapTrap'e gönderiyor sadece 1 sini yazmayı dene
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

DiamondTrap::~DiamondTrap() {
    std::cout << "DiamondTrap Destructor called" << std::endl;
}

void DiamondTrap::whoAmI(void) {
    std::cout << "my name is: " << this->name << std::endl;
}

void DiamondTrap::attack(const std::string& target) {
    ScavTrap::attack(target);
}
