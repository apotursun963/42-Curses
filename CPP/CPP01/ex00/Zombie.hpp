

#pragma once

#include <string>

class Zombie {
private:
    std::string name;
public:
    void announce(void);

    Zombie(std::string &inname);    
    ~Zombie();               
};

Zombie* newZombie(std::string name);    
void randomChump(std::string name);     
