

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");
		HumanA bob("Bob", club);
		bob.attack();
		club.setType("some other type of club");
		bob.attack();
	}
	{
		Weapon club = Weapon("crude spiked club");
		HumanB jim("Jim");
		jim.setWeapon(club);
		jim.attack();
		club.setType("some other type of club");
		jim.attack();
	}
	return 0;
}

/*
Weapon Sınıfı
---
- Amaç: Bir silahın tipini (ör: "crude spiked club") tutar.
- Özellik: std::string type
- Fonksiyonlar:
	- getType(): Silahın tipini referans olarak döndürür.
	- setType(std::string): Silahın tipini değiştirir.
- Kapsülleme: type değişkeni private, dışarıdan erişim sadece fonksiyonlarla mümkün.


HumanA Sınıfı
---
Bir insanı ve onun silahını temsil eder. Silahı "referans" olarak alır.
Kurucu Fonksiyon: HumanA(std::string name, Weapon &weapon)
- HumanA nesnesi oluşturulurken silahı mutlaka verilmelidir, Silahsız HumanA olamaz.
attack() Fonksiyonu: Kişinin ismi ve silahının tipiyle saldırı mesajı basar.
Önemli: Silah referans olduğu için, silahın tipi değişirse HumanA bunu anında görür.


HumanB Sınıfı
---
Bir insanı ve onun silahını temsil eder. Silahı pointer olarak tutar.
Kurucu Fonksiyon: HumanB(std::string name)
- HumanB nesnesi başta silahsız olabilir.
setWeapon(Weapon &weapon): Sonradan silah atanabilir.
attack() Fonksiyonu: Silahı varsa saldırı mesajı basar.
Önemli: Silah pointer olduğu için, HumanB başta silahsız olabilir ve istediği zaman silahı değiştirilebilir.

*/