
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


/*
Main testleri kesinlikle arttır
*/
int main(void)
{
	// AForm 		form("iddianame", 74, 55); -> soyut sınıftan doğrudan nesne oluşturmazsın
	
   Bureaucrat	Odin("Odin", 5);
   // ShrubberyCreationForm aloo(Odin);
   // RobotomyRequestForm baloo(Odin);
   PresidentialPardonForm paloo(Odin);

	try {
		std::cout << Odin << std::endl;
      paloo.beSigned(Odin);
      paloo.execute(Odin);
   }
	catch (std::exception &e) {
		std::cout << "Exception: " << e.what() << std::endl;
	}
	std::cout << paloo << std::endl;
    return (0);
}


/* tester

int main(void)
{
    std::cout << "=== ShrubberyCreationForm Testleri ===" << std::endl;
    {
        Bureaucrat alice("Alice", 140);
        ShrubberyCreationForm shrub("garden");

        try {
            alice.signForm(shrub);
            alice.executeForm(shrub);
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << shrub << std::endl;
    }

    std::cout << "\n=== RobotomyRequestForm Testleri ===" << std::endl;
    {
        Bureaucrat bob("Bob", 45);
        RobotomyRequestForm robot("Bender");

        try {
            bob.signForm(robot);
            for (int i = 0; i < 4; ++i) { // Birkaç kez dene, random sonucu görmek için
                bob.executeForm(robot);
            }
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << robot << std::endl;
    }

    std::cout << "\n=== PresidentialPardonForm Testleri ===" << std::endl;
    {
        Bureaucrat odin("Odin", 5);
        PresidentialPardonForm pardon("Loki");

        try {
            odin.signForm(pardon);
            odin.executeForm(pardon);
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
        std::cout << pardon << std::endl;
    }

    std::cout << "\n=== Başarısız Durum Testleri ===" << std::endl;
    {
        Bureaucrat low("LowRank", 150);
        ShrubberyCreationForm shrub("failgarden");

        try {
            low.signForm(shrub); // Yetersiz grade
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        Bureaucrat mid("MidRank", 140);
        try {
            mid.executeForm(shrub); // İmzalanmamış formu çalıştırmaya çalışıyor
        } catch (std::exception &e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }
    }

    return 0;
}
*/





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

