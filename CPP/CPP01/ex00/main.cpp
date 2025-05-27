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

/* notes

İki farklı şekilde zombi nesnesi yaratıyorsun:
- Heap’te (dinamik bellek): newZombie fonksiyonu ile.
- Stack’te (otomatik ömür): randomChump fonksiyonu ile.

Constructor: Nesne oluşturulurken çağrılır, zombinin ismini ayarlar.
Destructor: Nesne yok edilirken çağrılır, genellikle kaynakları serbest bırakmak için kullanılır.

new: Heap’te (dinamik bellek) nesne oluşturur. malloc gibi
delete: Heap’te oluşturulan nesneyi siler ve belleği geri verir. free gibi 


*/