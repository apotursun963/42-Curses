

#pragma once

#include <iostream>

// clap trap normalde bir robottur (araştır)
class ClapTrap {
private:
    std::string name;   // constructor’a parametre olarak verilecek.
    int hitPoints;      // (can puanı) ClapTrap'in health kontrol ediyor (başlangıç değeri: 10)
    int energyPoints;   // (başlangıç değeri: 10)
    int attackDamage;   // (başlangıç değeri: 0)
public:

    ClapTrap();
    ClapTrap(std::string);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap();

    void attack(const std::string& target);     // hedefe saldır funcs
    void takeDamage(unsigned int amount);       // hedeften saldırı alma
    void beRepaired(unsigned int amount);       // kendini onarma

    // bunları kullanmıyıorsun ama yine araştır
    // getter ve setter fonksiynları yazılacak (private değişkenler değer atamak ve erişmek için)
    // void    SetHitPoints();
    // void    SetEnergyPoints();
    // void    SetAttackDamage();
    std::string     GetName();
    int             GetHitPoints();
    int             GetEnergyPoints();
    int             GetAtacckDamage();


};
