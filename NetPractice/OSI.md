## 🧱 Katman 1 – **Fiziksel Katman (Physical Layer)**

### 🧩 Görevi Nedir?

* Verileri oluşturan **bitleri (1 ve 0)** bir cihazdan diğerine **fiziksel olarak** taşımakla sorumludur.

### 📦 Kapsadığı Unsurlar

Herhangi bir verinin bir bilgisayardan başka bir cihaza gitmesi için fiziksel bir yol gerekir. Bu yollar, Katman 1 kapsamındadır.

### 🔌 Örnek Teknolojiler

* **Ethernet kablosu** – Ofis veya evdeki ağ bağlantısı için yaygın
* **Fiber optik kablo** – Çok hızlı veri iletimi sağlar
* **Koaksiyel kablo** – Eski TV sistemleri ve bazı ağlarda
* **Wi-Fi (kablosuz sinyaller)** – Kablo olmasa da 1 ve 0’ları taşır

> ❗ Not: "Fiziksel" terimi sadece kablolu sistemleri değil, kablosuz sistemleri de içerir. Önemli olan bitlerin taşınmasıdır.

### 📡 Katman 1 Cihazları

#### 🔁 Repeater (Tekrarlayıcı)

* Gelen sinyali **güçlendirerek** iletir.
* Örn: 100 metrelik bir kabloda sinyal zayıflarsa, repeater sinyali yeniler.

#### 🔀 Hub (Çok portlu repeater)

* Gelen veriyi **tüm portlara** kopyalar.
* Basit ama verimsiz bir cihazdır.

---

## 📶 Katman 2 – **Veri Bağlantı Katmanı (Data Link Layer)**

### 🎯 Görevi Nedir?

* Veriyi bir cihazdan **bir sonraki cihaza** (örneğin PC → Switch) iletir.
* Bu iletimi sağlamak için **MAC adreslerini** kullanır.

> Katman 2, fiziksel ortam üzerinden geçen veriyi **okur** ve **doğru hedefe** ulaşmasını sağlar.

### 🛠️ Donanım Bileşenleri

#### 📎 NIC (Network Interface Card)

* Türkçesi: Ağ kartı
* Hem kablolu (Ethernet) hem de kablosuz (Wi-Fi) olabilir
* Verinin fiziksel olarak gönderildiği/yollandığı yerdir
* Her bir NIC kartı, kendine ait **benzersiz bir MAC adresi** taşır

### 🧭 MAC Adresi Nedir?

* **48 bit** uzunluğundadır, 12 adet **hex** karakterle yazılır.
* MAC adresi, cihaza üretici tarafından verilir ve genellikle değişmez.

#### 🔢 Gösterim Şekilleri:

* Windows: `A1-B2-C3-D4-E5-F6`
* Linux: `A1:B2:C3:D4:E5:F6`
* Cisco: `A1B2.C3D4.E5F6`

> ❗ MAC adresi, **yerel ağ içindeki** veri yönlendirmesi için kullanılır.

### 🔌 Katman 2 Cihazları: **Switch**

* Switch, birden fazla cihazı birbirine bağlar.
* Gelen verinin MAC adresine bakarak **sadece hedefe** yollar.
* Hub’dan farklı olarak **verimli** çalışır.

#### 🔄 Örnek:

Bir PC, yazıcıya veri göndermek istediğinde:

* Switch, yazıcının MAC adresini bilir.
* Veri sadece yazıcının portuna gönderilir, diğer cihazlara değil.

---

## 🌐 Katman 3 – **Ağ Katmanı (Network Layer)**

### 🎯 Görevi Nedir?

> **Uçtan uca** (end-to-end) iletişim sağlar.

Verinin A noktasından B noktasına ulaşması için gereken **yönlendirmeyi (routing)** yapar.
Bu iş için **IP adreslerini** kullanır.

### 🌍 IP Adresi Nedir?

* Cihazlara atanmış, ağlar arası yönlendirme için kullanılan adreslerdir.
* **32 bitlik (IPv4)** ya da **128 bitlik (IPv6)** olabilir.
* Örnek IPv4: `192.168.1.10`

### 🧭 Katman 3 Cihazları: **Router (Yönlendirici)**

* Farklı ağlar arasında veri yönlendiren cihazdır.
* Paketlerin hangi ağdan geçeceğini IP adreslerine göre belirler.

#### Örnek:

Bir evdeki bilgisayar `192.168.1.10` adresine sahipse ve bir web sitesine (`142.250.190.78`) erişmek istiyorsa:

* Veriyi ilk olarak evdeki **router** alır,
* Daha sonra internetteki diğer router’lar üzerinden hedef IP’ye yollar.

---

## 🔄 Katman 2 ve 3 Nasıl Birlikte Çalışır?

1. Katman 3, pakete **IP adresi bilgisi** ekler.
2. Katman 2, pakete **MAC adresi bilgisi** ekler.
3. Her router geçişinde (hop):

   * MAC adresleri değişir (yeni hop’a göre)
   * IP adresi **değişmeden** kalır

---

## 🔗 Neden Hem MAC Hem de IP Adresi Var?

| MAC Adresi                        | IP Adresi                            |
| --------------------------------- | ------------------------------------ |
| Fiziksel adres (değişmez)         | Mantıksal adres (değişebilir)        |
| Aynı ağ içi iletişimde kullanılır | Ağlar arası yönlendirmede kullanılır |
| Katman 2                          | Katman 3                             |

> Her biri farklı amaçlara hizmet eder: Biri **yerel yönlendirme**, diğeri **global yönlendirme** içindir.

---

## 🧩 ARP (Address Resolution Protocol)

* IP adresini **MAC adresine çevirir.**
* Örnek:

  * Cihaz `192.168.1.20` adresine veri göndermek istiyor.
  * IP adresinin hangi MAC adresine ait olduğunu bilmiyor.
  * Ağda “Bu IP’ye sahip olan kim?” diye ARP isteği yollar.
  * Cevap alındığında MAC adresi öğrenilir ve veri gönderilir.

---

## 🧠 Genel Özet Tablosu

| Katman   | Görevi                       | Adresleme  | Örnek Cihazlar            |
| -------- | ---------------------------- | ---------- | ------------------------- |
| Katman 1 | Bit iletimi (1 ve 0)         | Yok        | Kablo, Repeater, Hub      |
| Katman 2 | Cihazdan cihaza veri iletimi | MAC adresi | NIC, Switch               |
| Katman 3 | Uçtan uca veri iletimi       | IP adresi  | Router, Host (bilgisayar) |
