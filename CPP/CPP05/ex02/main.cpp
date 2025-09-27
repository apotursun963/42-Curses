
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
Buradaki target, formun işleyeceği hedefi ifade ediyor.
Yani formun hangi nesne veya kişi üzerinde işlem yapacağını belirten parametre
*/

int main(void)
{
    std::cout << "<<<ShrubberyCreationForm Tests>>>" << std::endl;
    {
        try {
            Bureaucrat	Huseyn("Huseyn", 136);            // sign = 145, exec = 137
            ShrubberyCreationForm aloo("palantir");

            aloo.beSigned(Huseyn);
            aloo.execute(Huseyn);
    
            std::cout << aloo << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "<<<RobotomyRequestForm Tests>>>" << std::endl;
    {
        try {
            Bureaucrat	Sodin("Huseyn", 44);      // sign = 72, exec = 45
            RobotomyRequestForm baloo("spider");

            baloo.beSigned(Sodin);
            baloo.execute(Sodin);

            std::cout << baloo << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    std::cout << "<<<PresidentialPardonForm Tests>>>" << std::endl;
    {
        try {
            Bureaucrat	Adin("Huseyn", 3);            // sign 25, exec 5
            PresidentialPardonForm daloo("tursun");
    
            daloo.beSigned(Adin);
            daloo.execute(Adin);

            std::cout << daloo << std::endl;
        }
        catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }
    return (0);
}



/* EX02

* Önceden yazdığın `Form` sınıfını artık **soyut sınıf** (`abstract class`) yapıp adını `AForm` olarak değiştireceksin.
* `Form`un (yani artık `AForm`un) **özel (private) attribute’ları** korunacak.
* `AForm` sınıfından türeyen **3 tane somut (concrete) form** ekleyeceksin:

  1. **ShrubberyCreationForm**
     * Gereken grade: `sign = 145`, `exec = 137`
     * Yapacağı iş: `<target>_shrubbery` isminde bir dosya açıp içine ASCII ağaçları yazacak.

  2. **RobotomyRequestForm**
     * Gereken grade: `sign = 72`, `exec = 45`
     * Yapacağı iş: %50 ihtimalle "robotomize successful", %50 ihtimalle "robotomize failed" mesajı basacak. (öncesinde drilling noise gibi bir mesaj da verecek).
  
  3. **PresidentialPardonForm**
     * Gereken grade: `sign = 25`, `exec = 5`
     * Yapacağı iş: `<target> has been pardoned by Zaphod Beeblebrox` yazacak.
- Bu 3'ü Hepsinin constructor’ı yalnızca bir parametre alacak → bu parametre de target olacak.
	- Yani target, o formun üzerinde işlem yaptığı kişi, yer ya da dosya ismidir.

Her form sadece bir parametre (`target`) alacak.

---

## Yeni fonksiyonlar

1. **AForm::execute(Bureaucrat const & executor) const**

   * Soyut sınıfta tanımlanacak.
   * Form imzalanmış mı? (`isSigned == true`)
   * `executor`’ın grade’i yeterli mi?
   * Değilse uygun exception fırlatılacak.
   * Eğer uygunsa, türetilmiş sınıfta tanımlanan `executeAction()` gibi bir fonksiyon çağrılacak.

2. **Bureaucrat::executeForm(AForm const & form) const**

   * Bu fonksiyon formu çalıştırmayı deneyecek.
   * Başarılıysa: `<bureaucrat> executed <form>` mesajı basacak.
   * Başarısızsa: hata mesajı basacak (exception yakalayıp).

## Yasaklar

* **Forbidden functions: None** → yani standart kütüphaneleri kullanabilirsin.
* `system()` veya başka kısayollar yasak değil ama genelde kullanılması tavsiye edilmiyor.

---

## Kısaca Subject’in İstediği

* `Form` → `AForm` soyut sınıfa çevrilecek.
* 3 yeni form sınıfı yazılacak (dosya açma, random işlem, basit print).
* `execute()` mantığı hem `AForm` hem de alt sınıflarda doğru şekilde çalışacak.
* `Bureaucrat` sınıfına `executeForm()` eklenecek.

---


Soyut ve Somut sınıflar
- Soyut sınıf saf sanal fonksiyon içerir ve ondan doğrudan nesne oluşturulamaz.
- Somut sınıf, soyut sınıftan türeyip eksik fonksiyonları tamamlayan sınıftır.
- Somut sınıflarda tüm fonksiyonlar implement edilmiştir, bu yüzden nesne oluşturulabilir.
- Örneğin AForm soyut sınıf olacak, çünkü execute() saf sanal fonksiyon içerir.
- ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm ise somut sınıflardır, çünkü execute() fonksiyonlarını kendileri yazarlar.

*/
