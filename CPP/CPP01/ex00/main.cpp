

#include "Zombie.hpp"

int main() {
    Zombie *Zombie1 = newZombie("atursun");
    Zombie1->announce();             
    randomChump("abdullah");            
    delete Zombie1;
    return 0;
}
