
#include "FragTrap.hpp"
#include "ScavTrap.hpp"

/*
FragTrap ve ScavTrap içinde ClapTrap Miras alındığı için
DiamondTrap te veri çakışması olabililyor o yüzden 
Her iki sınıfta ClapTrap'i Virtual Almamız gerekiyor.,
Virtual kullanmak, Sınıfın sadece bir kez miras alınmasını ve belirsizliklerin önlenmesini sağlar.
*/
class DiamondTrap : public FragTrap, public ScavTrap {  // iki sınıftan miras aldık
private:
    std::string name;
public:
    DiamondTrap();
    DiamondTrap(std::string name);
    DiamondTrap(const DiamondTrap &other);
    DiamondTrap &operator=(const DiamondTrap &other);
    ~DiamondTrap();

    void attack(const std::string& target);     // ScavTrap'ten miras almalı

    std::string     GetName();
    int             GetAttackDamage();

    
    void whoAmI();
};
