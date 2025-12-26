# MariaDB Nedir ?

MariaDB, **açık kaynaklı, güçlü ve güvenilir bir ilişkisel veritabanı yönetim sistemi (RDBMS)**’dir. Temel amacı; verileri **düzenli, hızlı ve güvenli** bir şekilde saklamak, sorgulamak ve yönetmektir. Özellikle web uygulamalarında ve sunucu tarafında çok yaygın olarak kullanılır.

---

## 📌 MariaDB’nin Ortaya Çıkışı

MariaDB, **MySQL’in geliştiricileri tarafından** oluşturulmuştur.

* MySQL, Oracle tarafından satın alındıktan sonra
* Açık kaynak ruhunun korunması için
* MySQL’in birebir uyumlu (compatible) bir **fork**’u olarak MariaDB geliştirildi

👉 Yani:
**MySQL bilen biri, MariaDB’yi de rahatlıkla kullanabilir.**

---

## 🧠 MariaDB Ne İşe Yarar?

MariaDB, verileri **tablo tabanlı** olarak saklar ve **SQL (Structured Query Language)** ile yönetir.

Örnek kullanım alanları:

* Kullanıcı bilgileri (email, şifre, profil)
* Blog yazıları ve yorumlar
* Siparişler, ürünler, stok bilgileri
* Loglar ve sistem verileri

---

## 🏗️ MariaDB Nasıl Çalışır?

1. Uygulama (Web, Mobil, API) MariaDB’ye sorgu gönderir
2. MariaDB bu sorguyu işler
3. Veriyi okur / yazar / günceller
4. Sonucu uygulamaya geri döndürür

📌 Örnek:

```sql
SELECT * FROM users WHERE email = 'test@mail.com';
```

---

## ⚙️ MariaDB’nin Temel Özellikleri

### 🔹 Açık Kaynak

* Tamamen **free & open-source**
* Geliştirici topluluğu tarafından aktif şekilde geliştiriliyor

### 🔹 MySQL ile Uyumlu

* Aynı komutlar
* Aynı yapı
* Mevcut MySQL projeleri sorunsuz taşınabilir

### 🔹 Yüksek Performans

* MySQL’e göre bazı senaryolarda **daha hızlı**
* Gelişmiş index ve storage engine desteği

### 🔹 Güvenli

* Yetkilendirme (user & role)
* Şifreleme
* SSL/TLS desteği

### 🔹 Ölçeklenebilir

* Küçük projelerden büyük sistemlere kadar kullanılabilir
* Replikasyon ve cluster desteği var

---

## 🧩 MariaDB vs MySQL (Kısa Karşılaştırma)

| Özellik    | MariaDB           | MySQL              |
| ---------- | ----------------- | ------------------ |
| Lisans     | Tam açık kaynak   | Oracle kontrolünde |
| Performans | Genelde daha iyi  | İyi                |
| Topluluk   | Çok aktif         | Daha kurumsal      |
| Uyumluluk  | %100 MySQL uyumlu | —                  |

---

## 🚀 Nerelerde Kullanılır?

* **WordPress**, **Drupal**, **Joomla**
* **Backend API** projeleri
* **Docker & Kubernetes** ortamları
* **DevOps** projeleri
* **NGINX + PHP + MariaDB** (LEMP stack)

---

## 🐳 Docker ile MariaDB (Mini Örnek)

```yaml
services:
  mariadb:
    image: mariadb:10.11
    environment:
      MYSQL_ROOT_PASSWORD: rootpass
      MYSQL_DATABASE: mydb
```

---

## 🎯 Özet

Kısaca:

> **MariaDB, MySQL’in daha özgür, güçlü ve topluluk odaklı versiyonudur.**
