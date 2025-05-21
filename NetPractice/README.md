# NetPractice

### IP Adresi (Internet Protocol)
Her cihazın ağda tanımlanabilmesi için bir IP adresi gerekir. IP adresleri, cihazların birbirini bulmasını ve veri göndermesini sağlar.
- **IPv4:** 32 bit, dört oktet (örn: 192.168.1.1)
- **IPv6:** 128 bit, daha fazla cihazı destekler

#### IP Adresinin Yapısı
- **Ağ Kısmı (Network Part):** Cihazın ait olduğu ağı belirtir.
- **Host Kısmı (Host Part):** Ağdaki cihazın kimliğini belirtir.

#### Subnet Maskesi
IP adresinin hangi kısmının ağ, hangi kısmının cihaz adresi olduğunu belirler.
- Örnek:  
  - IP: 192.168.1.10  
  - Subnet Maskesi: 255.255.255.0  
  - Ağ kısmı: 192.168.1  
  - Host kısmı: 10

#### Slash Notasyonu (/n)
IP adresinin kaç bitinin ağ kimliğine ayrıldığını belirtir.  
Örn: /24 → İlk 24 bit ağ adresi, kalan 8 bit host adresi.

#### Network ID
Bir ağın adresini temsil eder. Ağdaki tüm cihazlar için aynıdır ve cihazların aynı ağda olup olmadığını belirler.
- Hesaplama: IP adresi ve subnet maskesi bit düzeyinde AND işlemine tabi tutulur.

#### Private ve Public IP Adresleri
- **Private IP Adresleri:**
  - Sadece yerel ağlarda (ev, okul, ofis gibi) kullanılır.
  - İnternette doğrudan kullanılmaz, dışarıdan erişilemez.
  - Genellikle modem veya router, bu adresleri internete çıkarken tek bir public IP'ye çevirir (NAT işlemi).
  - Üç ana aralıkta bulunur:
    - 10.0.0.0 – 10.255.255.255
    - 172.16.0.0 – 172.31.255.255
    - 192.168.0.0 – 192.168.255.255
  - Örnek: 192.168.1.5, 10.0.0.12
  - Avantajı: Aynı private IP adresleri farklı ağlarda tekrar tekrar kullanılabilir.

- **Public IP Adresleri:**
  - İnternette doğrudan erişilebilen, benzersiz adreslerdir.
  - İnternet Servis Sağlayıcıları (ISP) tarafından atanır.
  - Her cihazın internette benzersiz bir public IP adresi olmalıdır.
  - Web siteleri, sunucular ve internete açık cihazlar bu adresleri kullanır.
  - Örnek: 8.8.8.8 (Google DNS), 185.60.216.35 (Facebook)

**Kısaca:**
- Private IP'ler sadece yerel ağda geçerlidir, internete çıkarken NAT ile public IP'ye çevrilir.
- Public IP'ler ise internette doğrudan görünür ve erişilebilirdir.

---

## 3. Ağda İletişim Kuralları
- Aynı ağda veya alt ağda (subnet) olan cihazlar doğrudan iletişim kurabilir.
- Farklı ağlarda olan cihazlar, iletişim için bir router (yönlendirici) veya gateway (ağ geçidi) kullanmak zorundadır.
- Yerel ağda iletişim, aynı ağ adresi (network address) paylaşıldığında gerçekleşir.

#### İletişim için Temel Kurallar
1. İki cihazın aynı ağda iletişim kurabilmesi için Ağ Adreslerinin aynı olması gerekir.  
   `Cihaz1(IP1 & MASK) == Cihaz2(IP2 & MASK)`
2. Aynı ağdaki cihazların IP adresleri farklı, ağ adresleri aynı olmalıdır.
3. Aynı ağda olan cihazların subnet maskeleri de aynı olmalıdır.

---

## 4. Ağ Cihazları ve Görevleri

| Cihaz      | Görev                                              | Çalıştığı Katman         |
| ---------- | -------------------------------------------------- | ------------------------ |
| **Switch** | Aynı LAN içindeki cihazları birbirine bağlar       | MAC Adresleriyle (2. Katman) |
| **Router** | Farklı ağları (LAN↔WAN) birbirine yönlendirir      | IP Adresleriyle (3. Katman)  |
| **Modem**  | ISP’ye bağlantı kurar, dijital/analog dönüşüm      | Fiziksel Katman           |
| **Hub**    | Gelen veriyi tüm portlara iletir (verimsiz)        | Fiziksel Katman           |
| **Bridge** | İki ağı birbirine bağlar, MAC tablosu ile filtreler| Veri Bağlantı Katmanı     |
| **Repeater** | Sinyali güçlendirir, menzili artırır             | Fiziksel Katman           |


#### Switch
- Aynı LAN’daki cihazları MAC adresleriyle birbirine bağlar.
- MAC adres tablosu sayesinde paketleri yalnızca hedef cihaza iletir.

#### Router
- Farklı ağlar arasında IP tabanlı yönlendirme yapar.
- Farklı subnet’teki iki cihaz, router olmadan doğrudan iletişim kuramaz.

#### Modem
- ISP ile bağlantı kurar, dijital ve analog sinyaller arasında dönüşüm yapar.

#### Hub
- Gelen veriyi tüm portlara iletir, bant genişliğini böler, çarpışma ihtimalini artırır.

#### Bridge
- İki ağı birbirine bağlar, MAC tablosu ile gereksiz trafiği engeller.

#### Repeater
- Sinyali güçlendirir, menzili artırır.

---

## 5. Yerel ve Geniş Alan İletişimi

### Yerel Ağ (LAN) İletişimi
- Switch, tüm LAN cihazlarını tek bir omurga üzerinde toplar.
- Cihazlar MAC adresleriyle haberleşir.
- Switch, ARP ile MAC adresini öğrenir ve paketi doğrudan hedef MAC adresine gönderir.

### Geniş Alan (WAN) İletişimi
- Hedef IP LAN dışındaysa, paket varsayılan ağ geçidine (router) gönderilir.
- Router, paketi ISP’ye ve oradan internete yollar.

---

## 6. ARP (Address Resolution Protocol)
- LAN içinde IP→MAC eşleştirmesi yapar.
- ARP isteği: “IP 192.168.1.1’e sahip olan cihaz, lütfen MAC’ini ver!”
- ARP cevabı: “Benim MAC’im 00:1A:2B:3C:4D:5E” → ARP tablosuna kaydedilir.

---

## 7. MAC Adresi ve IP Adresi Farkı
- **MAC Adresi:** Her ağ arayüzüne üretici tarafından atanır, cihazı yerel ağda benzersiz tanımlar.
- **IP Adresi:** Ağlar arasında paketlerin doğru hedefe yönlendirilmesini sağlar.

---

## 8. OSI Modeli (Open Systems Interconnection)
Ağ iletişimini 7 katmana böler:
1. Fiziksel
2. Veri Bağlantı (MAC, Switch)
3. Ağ (IP, Router)
4. Taşıma
5. Oturum
6. Sunum
7. Uygulama

---

## 9. Ağda Adresleme ve Alt Ağlar

### Hiyerarşik Adresleme
IP adresleri büyük bloklar hâlinde alınır ve alt parçalara bölünür. Örneğin:
- 10.0.0.0 bloğu bir şirkete ayrılır.
- Şirketin farklı ofisleri ve departmanları alt bloklar kullanır.

### Subnetting (Alt Ağlara Bölme)
Bir ağ, daha küçük alt ağlara bölünebilir. Her alt ağın kendi ağ adresi ve kullanılabilir host aralığı vardır.

#### Subnet Maskesi ve Hesaplama
- Subnet maskesi, IP adresinin ağ ve host kısmını ayırır.
- Hesaplama: IP adresi ve subnet maskesi bit düzeyinde AND işlemine tabi tutulur.
- Örnek:
  - IP: 192.168.1.10 → 11000000.10101000.00000001.00001010
  - Mask: 255.255.255.0 → 11111111.11111111.11111111.00000000
  - Network ID: 192.168.1.0

---

## 10. Pratik Notlar ve İpuçları
- 127.0.0.0/8 bloğu yalnızca cihazın kendi kendisiyle (loopback) haberleşmesi içindir.
- İki bilgisayarı doğrudan kabloyla bağlamak da bir ağ oluşturur.
- IP adresinin son değerlerini seçerken, o alt ağın host bitlerinin verdiği kullanılabilir aralık içinde kalmak gerekir.
- Default Gateway, cihazın kendi ağı dışına çıkan tüm paketleri yönlendirdiği router’ın IP’sidir.
- Switch, aynı ağdaki cihazlar arasında MAC’e göre hızlı anahtarlama yapar.
- Router, farklı ağlar arasında IP’ye göre yönlendirme yapar.



2. Router'lar Hangi Ağa Bağlı olduklarını Öğrenirler. Yani, Bir yönlendirici (router), her bağlı olduğu ağ arayüzüne (fiziksel veya sanal) bir IP adresi ve alt ağ maskesi atar.

3. Gateway; her bir cihazın (host’un) kendi bulunduğu yerel ağın dışına çıkmak için kullandığı varsayılan çıkış noktasıdır. Yani bir paketin hedefi yerel ağın dışındaysa, o paketi önce gateway’e (router arayüzünün IP’sine) yollar; oradan devam ederek diğer ağlara ulaşır.

4. Router, Ağlar arası veri iletiminden sorumludur.

5. Ağ içi (aynı LAN) veri iletimini yönetir.

6. Access Point (Erişim Noktası), kablosuz (Wi-Fi) cihazların kablolu ağa (LAN) bağlanmasını sağlayan ara birimdir.


# Network iletişim çeşitleri (unicasat - broadcast - multicast)

## Unicast (Tekil Gönderim)
Bir cihazın başka bir cihaz ile birebir iletişim kurmasıdır. Verinin bir kaynaktan yalnızca bir hedefe gönderilmesidir. Yani, iki host arasında bir iletişim kurmak. Kullanılan en yaygın iletişim türüdür.

## Broadcast (Yayın Gönderimi)
Bir cihazın aynı ağadaki tüm cihazlara iletişim kurmasıdır. Verinin bir kaynaktan ağdaki tüm cihazlara gönderilmesidir. Kullanım amacı ise, Ağdaki tüm cihazlara aynı anda mesaj göndermek gerektiğinde.
- Broadcast adresi (Yayın Adresi) Nedir ?
    - bir ağdaki tüm cihazlara aynı anda mesaj göndermek için kullanılan özel bir IP adresidir. IPv4’te broadcast adresi, ağın en son IP adresidir. Yani bu adrese gönderilen bir mesaj, bu ağda yer alan tüm cihazlara ulaşır. Broadcast adresinin kullanım amacı ise, Cihaz Keşfi (Yeni bağlanan bir cihaz, ağdaki diğer cihazları tanımak veya kendini tanıtmak için broadcast mesajı gönderir.) 
    MAC Adresi Öğrenme – ARP (Bir cihaz, başka bir cihazın MAC adresini bilmediğinde ağdaki herkese sorar “192.168.1.5 kim? MAC adresin nedir?”)

## Multicast (Çok Noktaya Gönderim)
Verinin bir kaynaktan, ilgili alıcı grubuna gönderilmesidir. Herkes değil, sadece veri göndremek istenen olanlar veriyi alır.

Özetle
---
- Unicast: Birebir iletişim (kişisel mesaj gibi).
- Broadcast: Herkese mesaj (duyuru yapmak gibi).
- Multicast: Sadece ilgilenenlere mesaj (toplantı daveti gibi).


## Subnetting Amacı: Verilen bir IP adresinin hangi ağ bloğuna ait olduğunu bulmak.

- Kullanılabilir IP aralığını hesapla
144.221.164.254
255.255.192.0/18
---
Ağ adresi : 144.221.128.0   ->> başlangıç adres: **144.221.128.1**
Broadcast : 144.221.191.255 ->> Bitiş Adres: **144.221.191.254**


# Subnet Mask (Alt Ağ Maskesi)
Alt Ağ Maskesi Sayesinde, IP adresinin hangi kısmının ağ, hangi kısmının cihaz (host) olduğunu öğrenebiliyoruz.

## Notes

Bir IP adresi ve subnet maskesi verildiğinde **Network adresi**, **Broadcast adresi**, **Kullanılabilir ilk adres** ve **Kullanılabilir son adres** bilgilerini kolayca hesaplayabiliriz.

Örnek:
- IP: `192.168.1.10/24` (subnet mask: `/24`)

---

### 1. IP Adresinin Network ve Host Kısmını Bulma

- **IP Binary:** `11000000 10101000 00000001 00001010`
- **Mask Binary:** `11111111 11111111 11111111 00000000`  
  (Subnet maskteki 1 olan kısım network'tur)
- **Network:** İlk 24 bit (`11000000 10101000 00000001`)
- **Host:** Son 8 bit (`00001010`)
- `192.168.1.10` adresinde, `10` host kısmıdır.

---

### 2. Network Adresi Bulma

Network adresini bulmak için IP adresi ile subnet maskesi arasında **AND** işlemi yapılır veya host kısmı binary olarak sıfırlanır.

- **IP Binary:** `11000000 10101000 00000001 00001010`
- **Mask Binary:** `11111111 11111111 11111111 00000000`
- **Sonuç:** `11000000 10101000 00000001 00000000`
- **Ağ Adresi:** `192.168.1.0`

---

### 3. Broadcast Adresi Bulma

Broadcast adresi, IP adresinin host kısmı binary olarak 1 yapılır.

- **Broadcast Adresi Binary:** `192.168.1.11111111`
- **Broadcast Adresi:** `192.168.1.255`

---

### 4. Kullanılabilir İlk ve Son IP Adreslerini Belirleme

- **Kullanılabilir ilk adres:** Network adresinin host kısmının bir fazlası  
  - `192.168.1.1`
- **Kullanılabilir son adres:** Broadcast adresinin host kısmının bir eksiği  
  - `192.168.1.254`

> **Not:** Network adresi (`192.168.1.0`) ve Broadcast adresi (`192.168.1.255`) hostlar için kullanılamaz. Sadece `192.168.1.1` ile `192.168.1.254` arasındaki adresler kullanılabilir.

---
