

#include "Zombie.hpp"

int main()
{
    Zombie *Zombie1 = zombieHorde(4, "atursun");
    Zombie1[0].announce();
    Zombie1[1].announce();
    Zombie1[2].announce();
    Zombie1[3].announce();
    delete[] Zombie1;
    return 0;
}
