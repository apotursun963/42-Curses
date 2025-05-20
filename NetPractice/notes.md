2. Router'lar Hangi Ağa Bağlı olduklarını Öğrenirler. Yani, Bir yönlendirici (router), her bağlı olduğu ağ arayüzüne (fiziksel veya sanal) bir IP adresi ve alt ağ maskesi atar.

3. Gateway; her bir cihazın (host’un) kendi bulunduğu yerel ağın dışına çıkmak için kullandığı varsayılan çıkış noktasıdır. Yani bir paketin hedefi yerel ağın dışındaysa, o paketi önce gateway’e (router arayüzünün IP’sine) yollar; oradan devam ederek diğer ağlara ulaşır.

4. Router, Ağlar arası veri iletiminden sorumludur.

5. Ağ içi (aynı LAN) veri iletimini yönetir.

6. Access Point (Erişim Noktası), kablosuz (Wi-Fi) cihazların kablolu ağa (LAN) bağlanmasını sağlayan ara birimdir.


## CIDR Nedir?
CIDR (Classless Inter-Domain Routing), IP adresinin yanında /28, /24 gibi yazılır ve subnet mask’ın kaç bitinin ağ adresi olduğunu belirtir. 
143.32.17.122/28 Bu demektir ki ilk 28 bit ağ adresidir, geriye kalan 4 bit ise hostlar içindir.



63.252.193.0/0 → /0 tüm IP adreslerini kapsar. Yani bu default route (varsayılan yön) anlamına gelir.

63.252.193.0/24 -> 163.172.250.12 -> bu durumda artık sadece belirli bir IP bloğu için yönlendirme yapılır.

/24, IP adresinin ilk 24 biti ağ adresidir anlamına gelir. Geriye kalan 8 bit, host (cihaz) adresi olarak kullanılır. 2^8: 256 farklı değer.

Bu da demek oluyor ki, 63.252.193.x formatında:
- x, 0 ile 255 arasında olabilir.
- Yani 0, 1, 2, ..., 254, 255 olmak üzere 256 farklı IP adresi vardır.


22.138.18.253
22.138.18.255

254 ila 2


----


Sen 115.198.14.0/28 bloğunu aldın:
IP aralığı: 115.198.14.0 – 115.198.14.15

    Bu blokta:
        Ağ adresi: 115.198.14.0
        Broadcast: 115.198.14.15
        Kullanılabilir IP'ler: 115.198.14.1 – 115.198.14.14

Bu blok sana tahsis edildiyse, senin dışında kimse bu bloktaki IP’leri kullanmamalı.
