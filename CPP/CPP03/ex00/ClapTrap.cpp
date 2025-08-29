
#include "ClapTrap.hpp"

// burada : ile init etmekle fonksiyonun için init etmek arasındaki farkı öğren
/*
Init list → değişkenler doğrudan başlatılır, kopya oluşmaz, daha verimli, const/reference olanlar için zorunlu.
Fonksiyon gövdesi → önce default constructor çalışır, sonra atama yapılır.
burda tek constructure mainde eğer nesen oluşturup ismini vermişse onuda kontrol et ve ayrı bir constructure
*/ 
ClapTrap::ClapTrap() : name("Kötü"), hitPoints(10), energyPoints(10), attackDamage(0) {
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : hitPoints(10), energyPoints(10), attackDamage(0) {
    this->name = name;
    std::cout << "Constructor called" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hitPoints(other.hitPoints)
    , energyPoints(other.energyPoints), attackDamage(other.attackDamage) {
	std::cout << "Copy constructor called" << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other) {
	std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other) {
        this->name = other.name;
        this->hitPoints = other.hitPoints;
        this->energyPoints = other.energyPoints;
        this->attackDamage = other.attackDamage;
    }
    return (*this);
}

ClapTrap::~ClapTrap() {
    std::cout << "Destructor called" << std::endl;
}


void    ClapTrap::SetName(std::string name) {this->name = name;}
void    ClapTrap::SetHitPoints(int hitpoints) {this->hitPoints = hitpoints;}
void    ClapTrap::SetEnergyPoints(int energypoints) {this->energyPoints = energypoints;}
void    ClapTrap::SetAttackDamage(int attackdamage) {this->attackDamage = attackdamage;}

std::string ClapTrap::GetName(void) {return this->name;}
int ClapTrap::GetHitPoints(void) {return this->hitPoints;}
int ClapTrap::GetEnergyPoints(void) {return this->energyPoints;}
int ClapTrap::GetAtacckDamage(void) {return this->attackDamage;}


/*
Saldırı → ClapTrap saldırdığında, hedefin (target) can puanı (hit points) 
ClapTrap’in attackDamage değeri kadar azalıyor.
Her Saldırı işlemi 1 enerji puanı (energy point) harcıyor.
Eğer ClapTrap'in enerji puanı veya can puanı 0 ise saldıramaz (attack).
*/
void ClapTrap::attack(const std::string& target) {
    if (this->energyPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " does not have enough energy to attack :(" << std::endl;
        return ;
    }
    if (this->hitPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " is dead can't attack :(" << std::endl;
        return ;
    }
    this->energyPoints -= 1;
    std::cout << "ClapTrap " << this->name
              << " attacks " << target
              << ", causing " << this->attackDamage
              << " points of damage!" << std::endl;
}

/*
Attack yapan tarafından saldırıldığında hitpoints değeri amount kadar yani claptrap'in 
attackDamage değeri kadar azalır
*/
void ClapTrap::takeDamage(unsigned int amount) {
    if (this->hitPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " is already dead :(" << std::endl;
        return ;
    }
    this->hitPoints -= amount;
    std::cout << "ClapTrap " << this->name << " takes " << amount
              << " points of damage! (Remaining hit points: " 
              << this->hitPoints << ")" << std::endl;
}

/*
ClapTrap kendini onardığında, can puanı (hit points) belirtilen miktar (amount) kadar artıyor.
Her Onarma işlemi 1 enerji puanı harcatıyıor.
Eğer ClapTrap'in enerji puanı veya can puanı 0 ise kendini onaramaz.
*/
void ClapTrap::beRepaired(unsigned int amount) {
    if (this->energyPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " does not have enough energy to attack :(" << std::endl;
        return ;
    }
    if (this->hitPoints <= 0) {
        std::cout << "ClapTrap " << this->name << " is dead can't attack :(" << std::endl;
        return ;
    }
    this->hitPoints += amount;      // <<ÖNEMLİ!: can puanı 0 ise kendini onaramaz bunu kontrol et 2. if koşulu>>
    this->energyPoints -= 1;
    std::cout << "Claptrap " << this->name
              << " is repaired by " << amount
              << " points" << std::endl; 
}
