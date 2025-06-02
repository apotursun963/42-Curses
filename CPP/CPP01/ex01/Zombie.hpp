
#pragma once

#include <string>

class Zombie {
private:
    std::string name;
public:
    void announce(void);
    void setname(std::string &inname);
    
    ~Zombie();
};

Zombie* zombieHorde(int N, std::string name);
