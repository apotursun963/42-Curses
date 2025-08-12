

#pragma once

#include <string>

class Weapon {
private:
    std::string type;
public:
    Weapon(std::string str);
    void setType(std::string ntype);    
    const std::string &getType();
};
