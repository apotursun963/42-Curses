

#pragma once

#include <string>

class Zombie {
private:
    std::string name;
public:
    void announce(void);

    Zombie(std::string &inname);    // constructure
    ~Zombie();                      // destructure
};

Zombie* newZombie(std::string name);    // Bu fonksiyon, heap’te (yani new ile) bir zombie oluşturacak ve pointer olarak geri döndürecek.
void randomChump(std::string name);     // Bu fonksiyon, stack’te (yani direk değişken olarak) bir zombie oluşturacak, adını verecek ve hemen announce() fonksiyonunu çağıracak.
