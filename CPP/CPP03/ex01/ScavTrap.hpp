


#pragma once

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap {  // ClapTrap sınıfından özellikleri/davranışları public olarak miras aldık.
public:
    ScavTrap();
    ScavTrap(std::string name);
    ScavTrap(const ScavTrap &other);
    ScavTrap &operator=(const ScavTrap &other);
    ~ScavTrap();

    void attack(const std::string& target);
    void guardGate();
};
