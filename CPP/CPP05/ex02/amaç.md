
Bu egzersizdeki amacımız Bir önceki Egzersizde olan "Form" sınıfını Soyut (AForm) hale getirip 
Bu soyut sınıftan 3 tane somut sınıf (Form Sınıfı) türemesi gerekiyor. Bu Formlar
imzalanması ve çalıştırılması için farklı yetki seviyeleri var. Eğer Bir Somut sınıf
İmzalanması ve Çalıştırılması için yetki seviyeleri geçerliyse imzalayabilir ve Çalıştırılabilir
(3 Somut Sınıfın Farklı 3 Çalıştırma özelliği var (ağaç oluştuyor, bazısı ekrana basıyor))






Sınıflar ve Görevleri
---
1. AForm (Soyut Sınıf)
Formun temel özelliklerini ve arayüzünü tanımlar.
İmzalanma durumu, imzalama ve çalıştırma için gereken grade’ler gibi özellikler içerir.
execute() fonksiyonu saf sanal (pure virtual) fonksiyondur, yani alt sınıflar bunu override etmek zorunda.

2. ShrubberyCreationForm
Bir dosyaya ASCII ağaç çizer.
İmzalamak için grade 145, çalıştırmak için grade 137 gerekir.

3. RobotomyRequestForm
Hedefi %50 ihtimalle robotize eder (random).
İmzalamak için grade 72, çalıştırmak için grade 45 gerekir.

4. PresidentialPardonForm
Hedefi Zaphod Beeblebrox tarafından affedildiğini yazar.
İmzalamak için grade 25, çalıştırmak için grade 5 gerekir.

5. Bureaucrat
İsmi ve grade’i (yetki seviyesi) vardır.
Formları imzalayabilir ve çalıştırabilir.
signForm() ve executeForm() fonksiyonları ile formlarla etkileşir.


Akış
---
- Formlar bir hedef (target) ile oluşturulur.
- Bureaucrat, yeterli grade’e sahipse formu imzalar.
- Form imzalandıktan sonra, yine yeterli grade’e sahip bir Bureaucrat formu çalıştırabilir.
- Her formun execute fonksiyonu kendi özel işini yapar (dosya yazma, random işlem, mesaj yazma).



Özetle
---

### 🔹 Exercise 02: Formları Gerçekten Çalıştırmak

* **Önceki form sistemini genişletiyorsun.**
* `Form` soyut sınıfa (`AForm`) dönüşüyor.
* Üç tane **somut form sınıfı** ekliyorsun:

  1. `ShrubberyCreationForm` → ASCII ağaç dosyası oluşturur.
  2. `RobotomyRequestForm` → %50 ihtimalle hedefi robotize eder.
  3. `PresidentialPardonForm` → hedefi affeder.
* Her formun **sign** ve **exec** için ayrı `grade` limitleri var.
* `execute(Bureaucrat const &executor) const` metodu ekleniyor:

  * Form **imzalı mı** kontrol edilir.
  * `executor`’ın grade’i yeterli mi kontrol edilir.
  * Değilse **exception fırlatılır**.
  * Yeterliyse formun kendi özel aksiyonu çalıştırılır.
* `Bureaucrat` sınıfına `executeForm(AForm const &form)` ekleniyor → bürokrat formu çalıştırmayı **dener** ve başarılı/başarısız olduğunu ekrana yazar.

👉 Yani **Exercise 02’nin amacı**:
Formların sadece kâğıt üzerinde kalmaması, gerçekten "iş yapar" hale gelmesi.
