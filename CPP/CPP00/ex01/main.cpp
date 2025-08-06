
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

# define GREEN "\033[32m"
# define RESET "\033[0m"

int main()
{
    PhoneBook pb;
    std::string cmd;
    pb.count = 0;       // Şu anda rehberde kaç kişi olduğunu tutar.
    pb.next = 0;        // Bir sonraki eklenecek kişinin hangi dizi indeksine yazılacağını gösterir.
    while (true)
	{
        std::cout << GREEN"PhoneBook> "RESET;
        std::getline(std::cin, cmd);
        if (std::cin.eof())
            return 0;
        if (cmd == "ADD")
		{
            Contact c;
            std::string f, l, n, p, s;
            std::cout << "First Name: ";   std::getline(std::cin, f);
            std::cout << "Last Name: ";    std::getline(std::cin, l);
            std::cout << "Nick Name: ";    std::getline(std::cin, n);
            std::cout << "Phone: ";        std::getline(std::cin, p);
            std::cout << "Secret: ";       std::getline(std::cin, s);
            if (f.empty() || l.empty() || n.empty() || p.empty() || s.empty())
			{
                std::cout << "No field can be empty!" << std::endl;
                continue;
            }
            c.set(f, l, n, p, s);
            pb.add(c);
            std::cout << "Contact added!" << std::endl;
        }
		else if (cmd == "SEARCH")
		{
            if (pb.count != 0)
            {
                pb.list();
                std::cout << "Index to show: ";
                std::string idxStr;
                std::getline(std::cin, idxStr);
                int idx = idxStr[0] - 48;
                if (!idxStr[1])     // eğer ikinci karakteri yoksa (ör: 7 5) değilse 
                    pb.show(idx);
            }
        }
        else if (cmd == "EXIT")
            break;
        else
            std::cout << "Unknown command" << std::endl;
    }
    return 0;
}


/*
ex01 (Phone Book (Telefon Rehberi))
----
Komut satırında çalışan, kullanıcıdan veri alıp saklayan ve 
gösterebilen bir "telefon rehberi uygulaması" yazacaksın.

İki Sınıf Oluşturacaksın
- PhoneBook: Rehberin kendisi. İçinde en fazla 8 kişi (Contact) saklayabilen bir dizi olacak.
- Contact: Bir kişinin bilgilerini tutan sınıf. (Ad, soyad, takma ad, telefon numarası, en karanlık sırrı)

Kurallar
- En fazla 8 kişi saklanabilir. 9. kişi eklenirse, en eski kişi silinir, yeni kişi üzerine eklenir.

Programın Çalışma Şekli
- Program başlarken rehber boş olacak ve kullanıcıdan şu üç komuttan birini girmesini bekleyecek:

1. ADD
- Kullanıcıdan sırayla yeni kişi bilgilerini (ad, soyad, takma ad, telefon, sır) isteyecek.
- Hiçbir alan boş bırakılamaz.
- Bilgiler girildikten sonra kişiyi rehbere ekleyecek.

2. SEARCH
- Kayıtlı kişileri tablo halinde gösterecek. Tablo 4 sütundan oluşacak: index, ad, soyad, takma ad.
- Her sütun 10 karakter genişliğinde olacak, aralarına | koyulacak, metinler sağa yaslanacak.
- Eğer bir bilgi 10 karakterden uzunsa, son karakteri nokta (.) olacak şekilde kısaltılacak.
- Kullanıcıdan bir index isteyecek. Geçerli bir index girilirse, o kişinin tüm bilgilerini satır satır gösterecek.

3. EXIT
- Programı sonlandıracak. (Kayıtlar kaybolacak.)

4. Diğer Komutlar
- Geçersiz komutlar görmezden gelinecek.

Ekstra Notlar
- Program sürekli komut bekleyecek, ta ki kullanıcı EXIT yazana kadar.

Kısaca:
Bir telefon rehberi uygulaması yazacaksın. 
8 kişilik sabit bir diziyle çalışacak, kullanıcıdan veri alacak, 
tablo halinde gösterecek ve komutlara göre davranacak. 
Sınıfları ve erişim belirleyicilerini doğru kullanman önemli.
*/


