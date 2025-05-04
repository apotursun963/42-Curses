
# Networking Nedir ?
Networking (Ağ), Host/cihaz (bilgisayar, sunucu, yazıcı, telefon) ve diğer cihazlar arasında veri alışverişini sağlayan bir sistemdir. yani cihazların birbirleriyle iletişim kurduğu bir yapıdır. Ne zaman iki cihaz bağlanırsa bir Ağ oluşmuş demektir. Network Öncesinde, Ağlar yokken bir bilgisayardan diğerine dosya taşımak için fiziksel medya (disket, USB bellek) kullanlırdı; şimdiyse ağlar bu işlemi otomatikleştirir. Genellikle Aynı yerdeki cihazlar (ev, ofis, sınıf) aynı ağa bağlanır. Bazen tek bir ağın alt bölümlere ayrılması gerekir. Buna subnet denir. ve internet ise, Birbirine bağlı milyonlarca ağın oluşturduğu devasa “ağlar ağı”.

## Networking Kavramları
1. Host (Cihaz/Ana Makine): Host, ağ üzerinde veri gönderen veya alan herhangi bir cihazdır. Yani, Ağ üzerinden trafik (Veri Aıkışı) gönderen veya alan her şey. Host'larıın birbirleriyle iletişim kurma mantığı **client - sever** mantığına dayanmaktadır.

2. IP Addreses (Internet Protocol): IP Adresi, Her bir Host'un Kimliğidir. Her cihazın ağ üzerinde tanımlanabilmesi için bir IP adresine ihtiyacı vardır. IP adresleri, cihazların birbirini bulmasını ve veri göndermesini sağlar.

- IP Adreslerinin Yapısı
    - Bir IP adresi gerçekte 32 bit’lik (1 veya 0’dan oluşan) bir sayıdır. Bu 32 bit, dörde bölünerek “oktet” adı verilen 8 bitlik gruplar hâlinde ondalık sayılara çevrilir. Her oktet 0 ile 255 arasında bir değerdir; bu yüzden IP adresleri “192.168.0.1” gibi dört ondalık sayıdan oluşur. Yani, İki tür IP adresi vardır: IPv4: 32 bit uzunluğunda, örneğin: 192.168.1.1. , IPv6: 128 bit uzunluğunda, daha fazla cihazı desteklemek için geliştirilmiştir.

- Ağ (Network) ve Host (Makine) Kısımları:
    - Adresin bir kısmı “ağ” (network), kalan kısmı “makine” (host) kimliğini taşır.
    - Bu ayrım alt ağ maskesi (subnet mask) veya prefix ile belirlenir.
    - Örnek maskeler:
        - 255.255.255.0 (slash>/24)
        - 255.255.255.128 (slash>/25)
        - 255.255.254.0 (slash>/23)
    - Slash Notasyonu (/n): Bir IP adresinin kaç bitinin ağ kimliğine ayrıldığını belirtir. Örneğin /24, “IP adresinin ilk 24 biti ağ adresi” demektir. Kalan 8 bit ise host (cihaz) adresi için kullanılır.


- Hiyerarşik Adresleme: Hiyerarşik Adresleme, IP adreslerinin büyük bir blok hâlinde alınarak ihtiyaç duyulan alt parçalara mantıksal olarak bölünmesi demektir. IP adresleri genellikle hiyerarşik şekilde tahsis edilir. Örneğin “10.0.0.0” bloğu APPLE Şirketi’ne ayrılmış olsun. Şirketin New York, Londra ve Tokyo ofisleri, sırasıyla “10.20.x.x”, “10.30.x.x” ve “10.40.x.x” bloklarını kullanır. New York ofisi içinde de satış, mühendislik ve pazarlama ekipleri “10.20.55.x”, “10.20.66.x”, “10.20.77.x” gibi alt bloklara ayrılabilir. Bu yapı, IP adresinin başındaki “prefiks” ile bir cihazın hangi ofiste veya ekipte olduğunu “ağın” mantıksal sınırları içinde göstermeyi sağlar. İşte “ağ” (network), aynı IP prefiksini paylaşan host’ların oluşturduğu mantıksal gruptur.

3. ping: İki cihaz arasındaki bağlantıyı test etmek için kullanılır. (ör: ping, bir hedef IP adresine ICMP Echo Request paketi (yani “orada mısın?” sinyali) gönderir ve hedef sağlıklıysa bir Echo Reply (“buradayım”) cevabı alır. Böylece hedefe ulaşım olup olmadığı, gecikme süresi gibi bilgiler elde edilir)
NetPractice’te ise **Check** işlemi aslında gerekli ping testlerini sizin için otomatik yapmaktadır.