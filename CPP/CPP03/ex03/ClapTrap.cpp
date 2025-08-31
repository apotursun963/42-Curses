
#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : name("Kötü"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "ClapTrap Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : hitPoints(10), energyPoints(10), attackDamage(0) {
    this->name = name;
    std::cout << "ClapTrap Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints)
    , energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	std::cout << "ClapTrap Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "ClapTrap Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap Destructor called" << std::endl;
}


void    ClapTrap::SetName(std::string name) {this->name = name;}
void    ClapTrap::SetHitPoints(int hitpoints) {this->hitPoints = hitpoints;}
void    ClapTrap::SetEnergyPoints(int energypoints) {this->energyPoints = energypoints;}
void    ClapTrap::SetAttackDamage(int attackdamage) {this->attackDamage = attackdamage;}

std::string ClapTrap::GetName(void) {return this->name;}
int ClapTrap::GetHitPoints(void) {return this->hitPoints;}
int ClapTrap::GetEnergyPoints(void) {return this->energyPoints;}
int ClapTrap::GetAtacckDamage(void) {return this->attackDamage;}


void ClapTrap::attack(const std::string& target) {
    if (this->energyPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " does not have enough energy to attack :(" << std::endl;
        return ;
    }
    if (this->hitPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " is dead can't attack :(" << std::endl;
        return ;
    }
    this->energyPoints -= 1;
    std::cout << "ClapTrap " << this->name
              << " attacks " << target
              << ", causing " << this->attackDamage
              << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " is already dead :(" << std::endl;
        return ;
    }
    std::cout << amount << std::endl;
    this->hitPoints -= amount;
    std::cout << "ClapTrap " << this->name << " takes " << amount
              << " points of damage! (Remaining hit points: " 
              << this->hitPoints << ")" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " does not have enough energy to attack :(" << std::endl;
        return ;
    }
    if (this->hitPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " is dead can't attack :(" << std::endl;
        return ;
    }
    this->hitPoints += amount;
    this->energyPoints -= 1;
    std::cout << "Claptrap " << this->name
              << " is repaired by " << amount
              << " points" << std::endl; 
}
