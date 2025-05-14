# Ağ (Networking) Temelleri ve Cihazlar
---

## 1. Networking Nedir?
Networking, cihazlar arasında veri alışverişini sağlayan sistemdir. Eskiden dosya taşımak için fiziksel medya kullanılırken, günümüzde ağlar bu işlemi otomatikleştirir. Ağlar, genellikle aynı yerdeki cihazları birleştirir ve büyük ağlar alt ağlara (subnet) bölünebilir. İnternet ise, birbirine bağlı milyonlarca ağdan oluşan devasa bir “ağlar ağı”dır.

---

## 2. Temel Ağ Kavramları

### Host (Cihaz/Ana Makine)
Ağ üzerinde veri gönderen veya alan herhangi bir cihazdır. Host’lar genellikle client-server mantığıyla iletişim kurar.

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
- NAT, DHCP, firewall gibi ek işlevler üstlenebilir.
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

---

## 11. Sonuç
- Switch’ler, MAC adreslerini kullanarak LAN içinde veri iletir.
- Router’lar, IP tabanlı ağlar arası iletişim, NAT, DHCP ve firewall işlevlerini üstlenir.
- ARP, yerel ağda IP’ye karşılık gelen MAC adresini bulmak için kullanılır.
- Ağda iletişim için cihazların aynı ağ adresine ve uygun subnet maskesine sahip olması gerekir.
