# Cihazların birbirleriyle doğrudan iletişim kurabilmesi için aynı ağda veya aynı alt ağda (subnet) olmaları gerekir. Eğer cihazlar farklı ağlarda veya alt ağlarda bulunuyorsa, iletişim kurabilmeleri için bir router (yönlendirici) veya başka bir ağ geçidi (gateway) gereklidir. Yerel ağda iletişim, aynı ağ adresi (network address) paylaşıldığında, doğrudan gerçekleşir.


- IP Adresi: Cihazın ağdaki adresi. İki kısımdan oluşur:
    - Ağ Kısmı (Network Part): Cihazın hangi ağa ait olduğunu belirtir.
    - Host Kısmı (Host Part): Ağdaki cihazın kimliğini belirtir.

Örnek: 192.168.1.10
    - Ağ kısmı: 192.168.1
    - Host kısmı: 10


- Subnet Maskesi: Subnet maskesi, IP adresinin hangi kısmının ağ adresi (network) ve hangi kısmının cihaz adresi (host) olduğunu belirler. Örneğin:
    - IP: 192.168.1.10
    - Subnet Maskesi: 255.255.255.0 (binary: 11111111.11111111.11111111.00000000)
    
    - Ağ Kısmı (Network Part): Subnet maskesindeki 1 olan bitler ağ kısmını temsil eder.
    - Host Kısmı (Host Part): Subnet maskesindeki 0 olan bitler host kısmını temsil eder.

Bu durumda:
    - İlk 24 bit ağ kısmını temsil eder (192.168.1).
    - Son 8 bit cihaz kısmını temsil eder (10).

Ağ ve host kısmı, subnet maskesine bağlı olarak belirlenir.

- Network ID: Network ID, bir ağın adresini temsil eder. Bu adres, ağdaki tüm cihazlar için aynıdır ve cihazların aynı ağda olup olmadığını belirlemek için kullanılır.

Örnek:
    - IP: 192.168.1.10
    - Subnet Maskesi: 255.255.255.0
    - Network ID: 192.168.1.0

Network ID Nasıl Hesaplanır?
    - Network ID'yi hesaplamak için IP adresi ve subnet maskesi bit düzeyinde AND işlemi ile birleştirilir.

    1. IP adresini ve subnet maskesini binary formatına çevirin.
        - IP: 192.168.1.10 → 11000000.10101000.00000001.00001010
        - Subnet Maskesi: 255.255.255.0 → 11111111.11111111.11111111.00000000
    2. Bit düzeyinde AND işlemi yapın:
        - 11000000.10101000.00000001.00001010 (IP)
    AND
        - 11111111.11111111.11111111.00000000 (Subnet Maskesi)
        =
        - 11000000.10101000.00000001.00000000 (Network ID)
    3. Binary sonucu tekrar ondalık formata çevirin:
        - 11000000.10101000.00000001.00000000 → 192.168.1.0

Sonuç: Network ID = 192.168.1.0

255.255.255.252 == /30

- Hesaplama: IP adresi ve subnet maskesi arasında bit düzeyinde AND işlemi yapılır.


127.0.0.1 ve genel olarak 127.0.0.0/8 bloğu, yalnızca o anki cihazın “kendi kendisiyle” (loopback) haberleşmesi için ayrılmıştır. Bu yüzden dışarı çıkıp başka bir makineyle asla fiziksel veya sanal ağ üzerinden paket alış-verişi yapamaz.

# Level 1
1. IP Adresses
2. Subnet Mask

# Level 2
1. 



127.0.0.0/30	-> C'nin Ağ Adresi
127.0.0.4/30	-> D'nin Ağ Adresi
Bu iki Ağ adresi farklı olduğu için birbirleriyle iletişim kuramazlar
O yüzden D'nin host kısmını 2 yaptığımda ve IP AND MASK sonrası 127.0.0.0 oldu ve
C ve D nin Ağ adresleri eşti olmuş oldu ve sonunda iletişim kurabilirler.





IP adreslerinde bit sayısı (1) ardışık değilde kaç tane varsa o o kadar var demektir.
MASK ise 1 bit sayısı ardışık olması gerekiyor



IP adresinin Son değerleri “istediğiniz gibi” seçmek için temel kural — o alt ağın host bit’lerinin verdiği kullanılabilir aralık içinde kalmaktır.


















11000000 10101000 00110111 00000001 > 192.168.55.1
11111111 11111111 11111111 11100000 > 255.255.255.224

11000000 10101000 00110111 00000000 > 192.168.55.0
A'nın Ağ Adresi: 192.168.55.0/10




11000000 10101000 00110111 11011110 > 192.168.55.222
11111111 11111111 11111111 00000000 > 255.255.255.224

11000000 10101000 00110111 00000000 > 192.168.55.0
B'nın Ağ Adresi: 192.168.55.0



A'nın Ağ Adresi: 192.168.55.0
B'nın Ağ Adresi: 192.168.55.222
Sonuç, bu iki cihazın Ağ adresi aynı değil o yüzden aynı olması için 























