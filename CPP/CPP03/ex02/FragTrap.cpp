
#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    this->SetName("tursun");
    this->SetHitPoints(100);
    this->SetEnergyPoints(100);
    this->SetAttackDamage(30);
    std::cout << "FragTrap Default Constructor called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    this->SetName(name);
    this->SetHitPoints(100);
    this->SetEnergyPoints(100);
    this->SetAttackDamage(30);
    std::cout << "FragTrap Constructor called" << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other) {
    *this = other;
    std::cout << "FragTrap Copy Constructor called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &other) {
	std::cout << "FragTrap Copy assignment operator called" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);     // burada Fragtrap değilde ClaptTrap diye mesaj verecek onu çöz
    return (*this);
}

FragTrap::~FragTrap() {
    std::cout << "FragTrap Destructor called" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout << GetName() << " Do You Want high five" << std::endl;
}

