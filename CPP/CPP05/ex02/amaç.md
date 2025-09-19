

Amaç
Soyut bir form (AForm) ve ondan türeyen 3 farklı Somut sınıf form (ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm) ile bir Bureaucrat (memur) sınıfı var. Her formun imzalanması ve çalıştırılması için farklı yetki seviyeleri (grade) gerekiyor


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
