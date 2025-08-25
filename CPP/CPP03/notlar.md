

- vs code mouse wheel zoom true -> fare ile zoom in zoom out yapma
- auto save -> afterDaily

// okuldaki bilgisyara .bashrc ve .bash_profile dosyaları eklemeyi unutma 





-----------------------

---

````markdown
# Linux Terminal Güvenliği ve Yedekleme Rehberi

Bu rehberde, Linux terminalinde **tehlikeli komutlardan korunma**, **yedekleme** ve **shell konfigürasyonu** hakkında temel bilgiler yer almaktadır.

---

## 1. Çok Tehlikeli Komut: `rm -rf /*`

```bash
rm -rf /*
````

* Bu komut, **root dizinindeki tüm dosyaları siler** ve sistemi kullanılamaz hâle getirebilir.
* **Çok dikkatli olun!**

### 🔹 Yedekleme Yapmak

Ev dizinindeki dosyaları kaybetmemek için yedekleme yapılabilir:

```bash
cp -r . ~/yedek_klasoru
```

**Açıklama:**

* `cp -r` → Klasörü ve içindeki tüm dosyaları kopyalar.
* `.` → Şimdiki dizin (ev dizini).
* `~/yedek_klasoru` → Yedeklerin saklanacağı klasör (ismi istediğin gibi olabilir).

---

## 2. Belirli Komutların Çalışmasını Engellemek

### Yöntem 1: Alias Kullanımı

```bash
alias <komut>="mesaj"
```

* Örnek:

```bash
alias rm='echo "Bu komut devre dışı!"'
```

* **Kalıcı hale getirmek için:**

```bash
source ~/.bashrc
```

---

### Yöntem 2: Komutun Çalıştırılmasını Engellemek

```bash
sudo chmod 000 /bin/rm
```

* Bu, `rm` komutunun çalıştırılmasını tamamen engeller.

---

## 3. Shell Konfigürasyon Dosyaları

Her shell’in kendi konfigürasyon dosyaları vardır:

* **Bash:** `~/.bashrc`, `~/.bash_profile`
* **Zsh:** `~/.zshrc`, `~/.zprofile`

---

### 3.1 `.bashrc` Dosyası

* Genellikle `home/user` dizininde bulunur.
* Eğer yoksa oluşturulabilir ve kullanıcıya özel ayarlar eklenebilir:

```bash
touch ~/.bashrc
```

* `.bashrc` terminal açıldığında **nasıl davranacağını ve kullanıcıya özel ayarları** belirler.
* Örnek:

```bash
alias ls="Hayırdır kanka"
```

* Bu alias’ı kullanabilmek için önce dosyayı çalıştırmak gerekir:

```bash
source ~/.bashrc
```

---

### 3.2 `.bash_profile` Dosyası

* Terminal açılışında çalıştırılan dosyadır.
* Eğer `.bashrc` dosyasının **otomatik yüklenmesini istiyorsan**, `.bash_profile` içine ekle:

```bash
if [ -f ~/.bashrc ]; then
    . ~/.bashrc
fi
```

* Böylece her terminal açıldığında alias ve diğer ayarlar otomatik olarak aktif olur.

---

## 4. `source` Komutu

* `source` komutu, bir dosyanın içindeki komutları **mevcut terminal oturumunda çalıştırmak** için kullanılır.

```bash
source ~/.bashrc
```

* Bu komut sayesinde `.bashrc` veya başka bir script dosyası **anında aktif olur**, yeni terminal açmana gerek kalmaz.

---

### ⚠️ Özet

* `rm -rf /*` komutunu çalıştırma, önce mutlaka yedek al.
* Tehlikeli komutları `alias` veya `chmod` ile engelle.
* `.bashrc` ve `.bash_profile` dosyalarını doğru şekilde kullanarak terminal ayarlarını güvenli ve otomatik hâle getir.
* `source` komutunu kullanarak değişiklikleri hemen uygulayabilirsin.

```
