/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:18:21 by atursun           #+#    #+#             */
/*   Updated: 2025/05/27 14:18:21 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main() {
    Zombie *Zombie1 = newZombie("atursun"); // Heap'te oluştur
    Zombie1->announce();                    // Kendini tanıt
    randomChump("abdullah");                // Stack'te oluştur ve tanıt
    delete Zombie1;                          // Heap'teki zombiyi sil
    return 0;
}


/*
ex00 Açıklaması: Basit Zombie Sınıfı ve Bellek Yönetimi
----

İki farklı şekilde zombi nesnesi yaratıyorsun:
- Heap’te (dinamik bellek): newZombie fonksiyonu ile.
- Stack’te (otomatik ömür): randomChump fonksiyonu ile.

new: Heap’te (dinamik bellek) nesne oluşturur. malloc gibi
delete: Heap’te oluşturulan nesneyi siler ve belleği geri verir. free gibi 

- Zombie.hpp: Zombie sınıfının tanımı (prototipi) burada.
- Zombie.cpp: Zombie sınıfının fonksiyonlarının (constructor, destructor, announce) gövdeleri burada.
- newZombie.cpp: Heap'te (dinamik bellek) yeni bir Zombie oluşturan fonksiyon.
- randomChump.cpp: Stack'te (otomatik ömür) bir Zombie oluşturan ve hemen announce eden fonksiyon.
- main.cpp: Programın başlangıç noktası, fonksiyonların nasıl çalıştığını gösteriyor.


Constructor (Yapıcı Fonksiyon)
- Sınıftan bir nesne oluşturulduğunda otomatik olarak çağrılır.
- Zombie sınıfında, genellikle zombinin adını ayarlamak için kullanılır.

Destructor (Yıkıcı Fonksiyon)
- Nesne ömrü bittiğinde (stack’te scope dışına çıkınca veya heap’te delete ile silinince) otomatik çağrılır.
- Genellikle kaynakları serbest bırakmak veya bilgi vermek için kullanılır.

Stack: Otomatik ömürlü nesneler (ör: fonksiyon içinde direkt oluşturulan Zombie). Scope bitince otomatik silinir.
Heap: Dinamik ömürlü nesneler (ör: new ile oluşturulan Zombie). delete ile manuel silinmeli.
*/