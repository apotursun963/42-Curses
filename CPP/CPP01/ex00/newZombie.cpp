
#include "Zombie.hpp"

Zombie *newZombie(std::string name) {
    Zombie *Class = new Zombie(name);
    return Class;
}
