

#include "Zombie.hpp"

// Dinamik olarak birden fazla Zombie nesnesi oluşturan fonksiyon.
Zombie* zombieHorde(int N, std::string name) {
    Zombie *zombieArr = new Zombie[N];
    for (int i = 0; i < N; i++)
        zombieArr[i].setname(name);
    return zombieArr;
}
