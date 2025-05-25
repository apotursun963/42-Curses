
#include <iostream>         // input-output için gerekli

using namespace std;

class Student {

private:
    string name;
    int age;
    int id;

public:
    void setname() {
        name = "abdullah";
    }
    void getname(string isim) {
       cout << "name: " << isim << endl;
    }
};

// void Student::showInfo() {
//     cout << "name: " << name << endl;
//     cout << "age: " << age << endl;
//     cout << "id: " << id << endl;
// }

int main()
{
    Student student1;

    student1.getname("tursunaldo");
    

    return 0;
}
























/*
Namespaces, classes, member functions, stdio streams,
initialization lists, static, const
*/




/*
ex01 (Phone Book (Telefon Rehberi))
----
Komut satırında çalışan, kullanıcıdan veri alıp saklayan ve 
gösterebilen bir telefon rehberi uygulaması yazacaksın.

İki Sınıf Oluşturacaksın
- PhoneBook: Rehberin kendisi. İçinde en fazla 8 kişi (Contact) saklayabilen bir dizi olacak.
- Contact: Bir kişinin bilgilerini tutan sınıf. (Ad, soyad, takma ad, telefon numarası, en karanlık sırrı)

Kurallar
- En fazla 8 kişi saklanabilir. 9. kişi eklenirse, en eski kişi silinir, yeni kişi eklenir.
- Dinamik bellek kullanmak yasak (yani new, malloc yok, sadece sabit boyutlu dizi).
- Her Contact nesnesi, Contact sınıfından; PhoneBook nesnesi de PhoneBook sınıfından oluşturulmalı.
- Sınıfları tasarlarken, sadece dışarıdan erişilmesi gerekenleri public yap, diğerlerini private tut.

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