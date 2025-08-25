

#pragma once

#include <iostream>


/*
Hit Points (HP) → Can/sağlık puanı.
    - Robotun ne kadar hasar alabileceğini gösterir.
    - 0 olursa robot “bitmiş” sayılır, artık hareket edemez.
Energy Points (EP) → Enerji puanı.
    - Robotun hareket edebilmesi için gereken yakıt/enerji gibi düşün.
    - Her saldırı veya onarım 1 enerji puanı harcar. Enerjisi biterse hiçbir şey yapamaz.
Attack Damage (AD) → Saldırı gücü.
    - Robot saldırdığında hedefin canından ne kadar düşeceğini gösterir.
    - Başlangıçta 0, ama farklı egzersizlerde artırılabiliyor.
*/

// clap trap normalde bir robottur (araştır)
class ClapTrap {
private:
    std::string name;   // constructor’a parametre olarak verilecek. (subjecte yazılı)
    int hitPoints;      // (başlangıç değeri: 10)
    int energyPoints;   // (başlangıç değeri: 10)
    int attackDamage;   // (başlangıç değeri: 0)
public:
    ClapTrap();
    ClapTrap(std::string name);
    ClapTrap(const ClapTrap &other);
    ClapTrap &operator=(const ClapTrap &other);
    ~ClapTrap();

    void attack(const std::string& target);     // hedefe saldır funcs
    void takeDamage(unsigned int amount);       // hedeften saldırı alma
    void beRepaired(unsigned int amount);       // kendini onarma

    // bunları kullanmıyıorsun ama yine araştır
    // getter ve setter fonksiynları yazılacak (private değişkenler değer atamak ve erişmek için)
    void            SetName(std::string name);
    void            SetHitPoints(int hitpoints);
    void            SetEnergyPoints(int energypoints);
    void            SetAttackDamage(int attackdamage);

    std::string     GetName();
    int             GetHitPoints();
    int             GetEnergyPoints();
    int             GetAtacckDamage();


};
