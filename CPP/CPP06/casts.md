
# Program çalışma zamanları öğren (run/compile)

# Casts (Tür/Tip Dönüşümü)

Cast, bir veri türündeki ifadeyi başka bir veri türüne dönüştürme işlemidir.



C++'ta iki ana tür cast yöntemi vardır: C-stili cast ve C++'ın kendi operatörleriyle yapılan cast'ler.

---

### 1. **C-Style Cast (Klasik C tarzı dönüşüm)**

```cpp
int i = 10;
double d = (double)i;  // i'yi double'a dönüştürür
```

* Eski C dilinden gelen bir yöntem.
* Herhangi bir tipteki dönüşümü yapabilir.
* Güvenlik açısından zayıftır, hataları kolay gizleyebilir.

---

### 2. **static_cast**

```cpp
int i = 10;
double d = static_cast<double>(i);
```

* Derleyici tarafından kontrol edilen, güvenli bir dönüşüm sağlar.
* Temel tipler arası dönüşümlerde ve türetilmiş sınıflar arasında (eğer mantıklıysa) kullanılır.
* Örneğin, `int` → `double` gibi.
* **Runtime** kontrolü yapmaz, sadece derleme zamanında kontrol eder.

---

### 3. **dynamic_cast**

```cpp
class Base { virtual void func() {} };
class Derived : public Base {};

Base* b = new Derived;
Derived* d = dynamic_cast<Derived*>(b);
```

* Polimorfik (yani içinde sanal fonksiyon olan) sınıflarda kullanılır.
* Pointer veya referans tipleri arasında güvenli dönüşüm sağlar.
* Eğer dönüşüm başarısızsa, pointer için `nullptr`, referans için ise `bad_cast` istisnası döner.
* Çalışma zamanı türü (RTTI) bilgisi kullanır.

---

### 4. **const_cast**

```cpp
const int i = 10;
int& j = const_cast<int&>(i);
```

* `const` veya `volatile` niteliklerini kaldırmak için kullanılır.
* Çok dikkatli kullanılmalı, çünkü `const` olmayan bir nesneye yazmaya çalışmak undefined behavior yaratabilir.

---

### 5. **reinterpret_cast**

```cpp
int* p = new int(10);
char* c = reinterpret_cast<char*>(p);
```

* En düşük seviyeli dönüşüm türüdür.
* Pointer türleri arasında veya veri tiplerini tamamen farklı olarak yorumlamak için kullanılır.
* Çok tehlikeli olabilir, çünkü derleyici tarafından hiç kontrol edilmez.
* Genellikle donanım programlama veya düşük seviyeli kodlarda kullanılır.

---

### Özet Tablosu

| Cast Türü        | Kullanım Alanı                                   | Güvenlik | Runtime Kontrol |
| ---------------- | ------------------------------------------------ | -------- | --------------- |
| C-Style Cast     | Her tür dönüşüm                                  | Düşük    | Hayır           |
| static_cast      | Tipler arası güvenli dönüşüm                     | Orta     | Hayır           |
| dynamic_cast     | Polimorfik sınıflarda güvenli pointer dönüşümü   | Yüksek   | Evet            |
| const_cast       | const/volatile kaldırma                          | Orta     | Hayır           |
| reinterpret_cast | Düşük seviye pointer/datanın farklı yorumlanması | Düşük    | Hayır           |

