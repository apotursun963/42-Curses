
Bu egzersizde senden istenen şey aslında şudur: **`Intern` adında yeni bir sınıf yazman**. Bu sınıf, daha önceki egzersizlerde oluşturduğun `AForm` türevlerini (örneğin: `ShrubberyCreationForm`, `RobotomyRequestForm`, `PresidentialPardonForm`) **dinamik olarak oluşturabilmeli**.

### Detaylı olarak istenenler:

1. **`Intern` sınıfı** oluşturacaksın (`Intern.hpp`, `Intern.cpp`).

   * İsmi, derecesi vs. yok → yani sınıfın kendisi basit olacak.
   * Tek önemli fonksiyonu var: `makeForm()`.

2. **`makeForm()` fonksiyonu**:

   * Parametreleri:

     * `std::string formName` → formun adı (örneğin `"robotomy request"`).
     * `std::string target` → formun hedefi (örneğin `"Bender"`).
   * Dönüş tipi: `AForm*` (yeni oluşturulmuş form nesnesi).
   * Çalışma mantığı:

     * `formName` tanınan bir form ise:

       * Yeni bir form nesnesi oluşturulacak (`new`) ve pointer olarak geri dönecek.
       * Ekrana şu tarz bir çıktı verecek:
         `"Intern creates <form>"`
     * `formName` tanınmıyorsa:

       * Ekrana hata mesajı basacak.
       * `NULL` veya uygun bir şey dönecek.

3. **Kısıt**:

   * Çok uzun `if / else if / else` zinciri yazamazsın. Yani:

     ```cpp
     if (formName == "shrubbery creation") ...
     else if (formName == "robotomy request") ...
     else if ...
     ```

     **yasak**.
   * Bunun yerine **daha düzenli ve okunabilir bir çözüm** yazmalısın.
     Genelde şu yöntem kullanılır:

     * Bir string dizisi (form isimleri).
     * Bir fonksiyon pointer dizisi (veya lambda fonksiyonlar).
     * Döngü ile kontrol.

4. **Test**:

   * Aşağıdaki örnek çalışmalı:

     ```cpp
     Intern someRandomIntern;
     AForm* rrf;
     rrf = someRandomIntern.makeForm("robotomy request", "Bender");
     ```

     Çıktı:

     ```
     Intern creates robotomy request
     ```

---

### Özet:

Bu egzersizde senden beklenen:

* `Intern` sınıfını yazman,
* `makeForm()` fonksiyonu ile gelen string’e göre doğru `AForm` türevinden nesne oluşturman,
* Bunu **if-else yığınına boğmadan** yapman.
