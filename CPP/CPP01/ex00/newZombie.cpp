
#include "Zombie.hpp"

Zombie *newZombie(std::string name) {
    Zombie *Class = new Zombie(name);      // new'dan sonra gelen contructure dır.
    return Class;
}
