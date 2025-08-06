
#pragma once

#include <string>
#include <iostream>
#include "Weapon.hpp"

class HumanA {
private:
    std::string name;
    Weapon &weapon;     // referans olduğu için mutlaka silahlı olmalı çünkü her zaman bir nesneye bağlıdırlar
public:
    HumanA(std::string name, Weapon &weapon);
    void attack();
};
