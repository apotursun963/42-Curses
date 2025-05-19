Detaylıca Öğrenilecek Konular
1. TCP/IP Adresi
2. OSI modellerini 
3. Subnetting ve Subnet Maskeleri
4. IP Adresleme Mekanizması


A bilgisayarı, B’nin IP adresini biliyordur fakat MAC adresini bilmiyordur. Bu nedenle A, B’nin MAC adresini öğrenmek için ARP (Address Resolution Protocol) isteği gönderir. Bu istek, bir broadcast şeklindedir ve ağdaki tüm cihazlara ulaşır. IP adresi eşleşen cihaz yani B, kendi MAC adresini A’ya unicast olarak gönderir. A, bu MAC adresini kendi ARP tablosuna kaydeder.
Daha sonra A, veriyi göndermek üzere bir çerçeve oluşturur. Bu çerçeve, B’nin MAC adresini hedef olarak içerir. Veri çerçevesi switch’e gönderilir. Switch, çerçevedeki hedef MAC adresine bakarak veriyi doğru porta iletir. Sonuç olarak B, gelen çerçeveyi alır ve veriyi işler.


https://github.com/menasy/NetPractice?tab=readme-ov-file






# alıştırmalar

43.61.41.126
255.255.255.128/25
Ağ: 43.61.41.0
Br: 43.61.41.127
1 ila 126