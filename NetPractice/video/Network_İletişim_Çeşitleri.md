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



## IP adresleri blokları

## Subnetting Amacı: Verilen bir IP adresinin hangi ağ bloğuna ait olduğunu bulmak.

- Kullanılabilir IP aralığını hesapla
144.221.164.254
255.255.192.0/18
---
Ağ adresi : 144.221.128.0   ->> başlangıç adres: **144.221.128.1**
Broadcast : 144.221.191.255 ->> Bitiş Adres: **144.221.191.254**













ağ: 77.16.114.112
Br: 77.16.114.127
113 ile 126
