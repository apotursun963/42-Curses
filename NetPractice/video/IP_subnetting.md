# Subnet Mask (Alt Ağ Maskesi)
Alt Ağ Maskesi Sayesinde, IP adresinin hangi kısmının ağ, hangi kısmının cihaz (host) olduğunu öğrenebiliyoruz.


## Notes
Bir IP adresi ve subnet maskesi verildiğinde **Network adresi**, **Broadcast adresi**, **Kullanılabilir ilk adres** ve **Kullanılabilir son adres** bilgilerini kolayca hesaplayabiliriz.

- IP; 192.168.1.10/24   -->> subnet mask (/24)

1. Öncelikle IP adresinin Network ve Host kısmını Bul
- IP BİNARY   : 11000000 10101000 00000001 00001010 
- MASK BİNARY : 11111111 11111111 11111111 00000000     ->> subnet maskteki 1 olan kısım network'tur
                -------------------------- --------
                    Network                  Host
- 192.168.1.10  ->> 10 host'tur


2. Network Adresi Bulma (AND İşlemi yada host kısmını BİN olarak 0 yapmak)
- IP BİNARY   : 11000000 10101000 00000001 00001010 
- MASK BİNARY : 11111111 11111111 11111111 00000000
- Sonuç       : 11000000 10101000 00000001 00000000
- Ağ Adresi   : 192.168.1.0


3. Broadcast Adresi Bulma (IP ADRESİNİN HOST KISMINI BİN OLARAK 1 YAP SONRA AĞ ADRESİ HOST KISMI İLE TOPLA)
- Broadcast Adresi; 192.168.1.11111111
- Broadcast Adresi; 192.168.1.255


4. Network'ta kullanılabilir ilk ve son IP adreslerini belirleme
- Network'ta kullanılabilir ilk adres bulma: Network Adresinin HOST kısmının Bir fazlasıdır.
    - 192.168.1.1
- Network'ta kullanılabilir son adres bulma: Broadcast Adresinin HOST kısmının Bir eksiğidir.
    - 192.168.1.254
- Biz **Network Adresini** (192.168.1.0) ve **Broadcast Adresini** (192.168.1.255) Hostlar için kullanamıyoruz. Sadece (192.168.1.1 ve 192.168.1.254) Arası kullanabiliriz.




192.168.55.222 
255.255.255.224

192.168.55.192 -> network adresi
192 + 31 = 223
192.168.55.223 -> broadcast adresi

kullanılabilir IP aralığı (192.168.55.193 - 192.168.55.223)