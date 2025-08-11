

#include "Zombie.hpp"
#include <iostream>

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setname(std::string& inname) {
    name = inname;
    std::cout << name << " created" << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " destroyed" << std::endl;
}
