
#include "FragTrap.hpp"

int main(void)      // ekstra testlerde ekle
{
    FragTrap Robot("ali");
    FragTrap Ar("hadi bakalım");
    FragTrap LA;

    Ar = LA;


    // ClapTrap Robot("İyi");
    // ClapTrap Target;

    // std::cout << "Robot Name: " << Robot.GetName() << std::endl;
    // std::cout << "Robot Hit Points: " << Robot.GetHitPoints() << std::endl;
    // std::cout << "Ar Name: " << Ar.GetName() << std::endl;

    // // Enerji bitene kadar saldırı 
    // for (int i=0; i < 11; i++)
    //     Robot.attack("Target");

    // // Can Puanı Sıfır Olunca Salıdır
    // Target.takeDamage(10);
    // Target.attack("Robot");

    
    Robot.attack("LA");
    std::cout << "robot energy: " << Robot.GetEnergyPoints() << std::endl;
    LA.takeDamage(Robot.GetAtacckDamage());
    LA.beRepaired(3);

    Robot.highFivesGuys();

    return 0;
}



/* ex01

Kalıtım Burada balşıyıor 
Temelde ClapTrap Sınıfından miras (constructors, destructor) alan bir ScavTrap sınıfı yapmamız isteniliyro.
Ancak, constructors, destructor ve attack() fonksiyonu farklı mesajlar yazdıracak.

Testlerinde doğru kurucu/yıkıcı zincirlemenin (construction/destruction chaining) gösterilmesi 
gerektiğine dikkat et

Bir ScavTrap oluşturulduğunda, program önce bir ClapTrap inşa etmeye başlar.
Yıkım (destruction) ise ters sırada gerçekleşir. Neden?

ScavTrap, ClapTrap’in özelliklerini kullanacak (buna göre ClapTrap’i güncelle) ve şu değerlerle başlatılmalıdır:
- İsim: constructor’a parametre olarak verilecek.
- Can (Hit points): 100
- Enerji (Energy points): 50
- Saldırı gücü (Attack damage): 20

ScavTrap’in ayrıca kendine özgü özel bir yeteneği olacak:
- void guardGate();
Bu üye fonksiyonu, ScavTrap’in artık Kapı Bekçisi Modunda (Gate keeper mode) olduğunu belirten bir mesaj gösterecek.


Özetle, ClapTrap’ten miras alan ScavTrap sınıfı yapıyorsun. 
Varsayılan değerleri farklı (100 can, 50 enerji, 20 hasar) ve ayrıca guardGate() isminde ekstra bir yeteneği var.



Kalıtım (inheritance) Nedir ?:
- Kalıtım, bir sınıfın başka bir sınıfın özelliklerini (değişkenler, fonksiyonlar) miras almasıdır.
- Böylece ortak özellikleri tekrar tekrar yazmak yerine kod tekrarını önler ve sınıflar arasında ilişki kurar
Özet: Bir sınıfın başka bir sınıftan türemesidir.

Kalıtım Türleri:
- public inheritance
    * Taban sınıfın public üyeleri → alt sınıfta da public olur.
    * class Alt : public Taban { ... };
- protected inheritance
    * Taban sınıfın public üyeleri → alt sınıfta protected olur. Daha kısıtlı bir erişim sağlar
    * class Alt : protected Taban { ... };
- private inheritance
    * Taban sınıfın public üyeleri → alt sınıfta private olur. Dışarıdan erişilemez.
    * class Alt : private Taban { ... };


Constructor ve Destructor Çalışma Sırası
Bir alt sınıf nesnesi oluşturulunca:
- Önce üst sınıfın constructor’u çalışır.
- Sonra alt sınıfın constructor’u çalışır.

Nesne silinince:
- Önce alt sınıfın destructor’u,
- Sonra üst sınıfın destructor’u çalışır.

*/