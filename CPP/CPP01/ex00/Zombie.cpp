
#include "Zombie.hpp"
#include <iostream>

void Zombie::announce(void) {
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::Zombie(std::string& inname) : name(inname) {
    std::cout << inname << " created" << std::endl;
}

Zombie::~Zombie() {
    std::cout << name << " destroyed" << std::endl;
}
