

#include "Zombie.hpp"

// Dinamik olarak birden fazla Zombie nesnesi tek seferde oluşturan fonksiyon.
Zombie* zombieHorde(int N, std::string name) {
    Zombie *zombieArr = new Zombie[N];      // 4 adet Zombie nesnesi oluşturur.
    for (int i = 0; i < N; i++)
        zombieArr[i].setname(name);
    return zombieArr;
}
