**🧠 Network-101 Özeti**

Aşağıda, temel ağ kavramları ve cihazlarının nasıl çalıştığını sade ve görsel bir yaklaşımla özetledim.

---

## 1. Temel Ağ Cihazları

| Cihaz      | Görev                                              | Çalıştığı Katman         |
| ---------- | -------------------------------------------------- | ------------------------ |
| **Switch** | Aynı LAN içindeki cihazları birbirine bağlar       | MAC Adresleriyle         |
| **Router** | Farklı ağları (LAN↔WAN) birbirine yönlendirir      | IP Adresleriyle          |
| **Modem**  | İnternet Servis Sağlayıcısına (ISP) bağlantı kurar | Dijital ↔ Analog Dönüşüm |

---

## 2. Yerel İletişim (LAN)

* **Switch**, tüm LAN cihazlarını tek bir omurga (backbone) üzerinde toplar.
* Cihazlar **MAC adresleri** üzerinden haberleşir.
* Switch, kendi **MAC adres tablosu** sayesinde paketleri yalnızca hedef cihaza iletir.

> **Örnek:** Bilgisayarınız aynı LAN’daki bir başka PC’ye dosya yollamak istediğinde;
>
> 1. Hedef IP’nin subnet içinde olup olmadığını kontrol eder.
> 2. ARP ile MAC adresini öğrenir.
> 3. Paketi doğrudan ilgili MAC adresine gönderir.

---

## 3. İnternet İletişimi (WAN)

1. Hedef IP LAN dışındaysa, paket **varsayılan ağ geçidine (default gateway)**, yani **router’a** gönderilir.
2. Router yönlendirme tablosuna bakarak paketi ISP’ye yollar.
3. ISP paketi internette doğru adrese ulaştırır.

---

## 4. ARP (Address Resolution Protocol)

* LAN içinde IP→MAC eşleştirmesi yapmak için kullanılır.
* **ARP İsteği:** “IP 192.168.1.1’e sahip olan cihaz, lütfen MAC’ini ver!”
* **ARP Cevabı:** “Benim MAC’im 00:1A:2B:3C:4D:5E” → Bu bilgi ARP tablosuna kaydedilir.

---

## 5. Yönlendirici (Router)

* **Ağlar arası köprü** görevi görür (LAN↔WAN).
* **Ana işlevleri:**

  1. Paket yönlendirme (routing)
  2. NAT (özel IP’leri genel IP’ye çevirme)
  3. DHCP (LAN içi otomatik IP dağıtımı)
  4. (Opsiyonel) Güvenlik duvarı (firewall)

---

## 6. Genel Bakış Diyagramı

```
[ Sizin Cihazınız ]
        ↓  (MAC)
     [ Switch ]
        ↓  (IP)
     [ Router ] ← DHCP, NAT, Firewall
        ↓  (IP)
      [ ISP ] ← İnternet
```

---

### Sonuç

* **Switch’ler**, MAC adreslerini kullanarak **LAN** içinde veri iletir.
* **Router’lar**, IP tabanlı **ağlar arası** iletişim, NAT, DHCP ve firewall işlevlerini üstlenir.
* **ARP**, yerel ağda IP’ye karşılık gelen MAC adresini bulmak için vazgeçilmezdir.

Bu temel bilgiler, modern ağların nasıl yapılandığını ve cihazların hangi görevleri üstlendiğini anlamanıza yardımcı olur.
