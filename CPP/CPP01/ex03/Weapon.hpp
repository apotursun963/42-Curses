

#pragma once

#include <string>

class Weapon {
private:
    std::string type;
public:
    Weapon(std::string str);
    std::string &getType();
    void setType(std::string ntype);
};

