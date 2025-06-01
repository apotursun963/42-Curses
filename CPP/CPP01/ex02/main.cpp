/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 14:43:27 by atursun           #+#    #+#             */
/*   Updated: 2025/05/27 14:43:27 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string>
#include <iostream>

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;      // str'nin adresini tutuan pointer
    std::string &stringREF = str;       // str'nin referansı (takma adı)

    // print addresses  
    std::cout << &str << std::endl;         // str'nin bellekteki adresi
    std::cout << stringPTR << std::endl;   // stringPTR'nin tuttuğu adres (str'nin adresi)
    std::cout << &stringREF << std::endl;  // stringREF'in adresi (str'nin adresi ile aynı)
    
    // print values
    std::cout << str << std::endl;           // str'nin değeri
    std::cout << *stringPTR << std::endl;   // stringPTR'nin gösterdiği değeri yazdır
    std::cout << stringREF << std::endl;    // stringREF'in değeri (str ile aynı)

    return 0;
}


/*

Pointer (İşaretçi)
Bir değişkenin bellekteki adresini tutar.
Değerini değiştirebilir, farklı adresleri gösterebilir.
Null (boş) olabilir.
Gösterdiği değere * ile erişilir, adresine & ile erişilir.

Referans
Bir değişken için başka bir isim (takma ad) oluşturur.
Tanımlandıktan sonra başka bir değişkeni gösteremez.
Null olamaz, mutlaka bir değişkene bağlıdır.
Kullanımı pointer’a göre daha güvenlidir ve daha kolaydır.

Pointer: Adres tutar, değiştirilebilir, null olabilir.
Referans: Takma ad, değiştirilemez, null olamaz.
*/