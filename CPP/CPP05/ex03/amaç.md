
### 🔹 Exercise 03: Stajyer (Intern) ile Form Üretmek

* **Yeni sınıf:** `Intern`
* Stajyerin tek yeteneği: `makeForm(std::string formName, std::string target)`

  * `formName` → hangi form oluşturulacak (`robotomy request`, `presidential pardon`, `shrubbery creation`).
  * `target` → formun hedefi.
  * Geriye bir `AForm*` döner.
* Eğer form adı geçerliyse:

  * Form yaratılır.
  * `"Intern creates <form>"` mesajı basılır.
* Eğer form adı yanlışsa:
  * `"Error: form does not exist"` gibi bir hata mesajı basılır.
* Burada önemli nokta: **if-else yığını yazmak yasak**. Daha şık bir çözüm bekleniyor (örneğin bir tablo/map kullanmak).

👉 Yani **Exercise 03’ün amacı**:
Form yaratma işini **otomatikleştirmek ve soyutlamak** → bürokratlar tek tek `new` ile uğraşmasın, intern onlar için form üretsin.

---

### 🔑 Özet Fark

* **Exercise 02** → Formların "çalıştırılabilir" hale gelmesi (execution + action).
* **Exercise 03** → Formların **dinamik olarak yaratılması** (`Intern` sınıfı ile).
