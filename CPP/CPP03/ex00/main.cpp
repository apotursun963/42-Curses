
#include "ClapTrap.hpp"

int main(void)
{
    ClapTrap Hitler("İyi");
    ClapTrap Stalin;

    Hitler.GetName();
    Stalin.GetName();

    return 0;
}



/* CPP03

- Saldırı → ClapTrap saldırdığında, hedefin (target) can puanı (hit points) ClapTrap’in attackDamage değeri kadar azalıyor.1
- Onarma → ClapTrap kendini onardığında, can puanı (hit points) belirtilen miktar (amount) kadar artıyor.
- Enerji kullanımı → Her saldırı veya onarma işlemi 1 enerji puanı (energy point) harcıyor.
- Sınırlama → ClapTrap’in can puanı 0 veya enerji puanı 0 ise hiçbir şey yapamaz (saldıramaz, onaramaz).
- Etkileşim yok → Bu alıştırmalarda ClapTrap nesneleri birbirleriyle savaşmayacak. 
Yani parametrelerde başka bir ClapTrap nesnesi kullanılmayacak; sadece ekrana yazdırma gibi simülasyon yapılacak.


Bu üye fonksiyonların hepsinde, olan biteni açıklayan bir mesaj yazdırmanız gerekiyor.
Örneğin, attack() fonksiyonu şöyle bir şey gösterebilir (tabii ki açılı köşeli parantezler olmadan):
- ClapTrap <isim> <hedef>’e saldırıyor, <hasar> puan hasar veriyor!

Constructor’lar ve destructor da bir mesaj yazdırmalı, böylece kodunuzu değerlendiren kişiler hangi fonksiyonların çağrıldığını kolayca görebilsin.
Kendi testlerinizi uygulayıp gönderin, böylece kodunuzun beklendiği gibi çalıştığından emin olabilirsiniz.


*/