
#pragma once

#include <iostream>

class ClapTrap {
protected:
    std::string name;
    int hitPoints;
    int energyPoints; 
    int attackDamage; 

public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap();

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);       
    void beRepaired(unsigned int amount);

    void            SetName(std::string name);
    void            SetHitPoints(int hitpoints);
    void            SetEnergyPoints(int energypoints);
    void            SetAttackDamage(int attackdamage);

    std::string     GetName();
    int             GetHitPoints();
    int             GetEnergyPoints();
    int             GetAtacckDamage();
};
