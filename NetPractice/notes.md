
1. iki bilgisayarın birbirleriyle aynı ağda iletişim yapabilemsi için Her iki bilgisayarın **Ağ Adreslerinin** aynı olması gerekiyor.
Network Adresses: Cihaz1(IP1 & MASK) == Cihaz2(IP2 & MASK)

2. 127.0.0.1 ve genel olarak 127.0.0.0/8 bloğu, yalnızca o anki cihazın “kendi kendisiyle” (loopback) haberleşmesi için ayrılmıştır. Bu yüzden dışarı çıkıp başka bir makineyle asla fiziksel veya sanal ağ üzerinden paket alış-verişi yapamaz.

3. Aynı Ağ (Network) içindeki cihazlar aynı IP adreslerini taşırlar. ve her bir IP adresinin Host kimliği farklı olmalı.

4. Ayna Ağda olan cihazların aynı maskeleri olmak zorundadır.

4. Mac Adresi Nedir ve IP Farkı; MAC (Media Access Control) adresi, her ağ arayüz kartına (NIC) üretici tarafından atanan 48 bit uzunluğunda, genellikle hexadecimal (ör : 00:1A:2B:3C:4D:5E) formattaki donanım kimliğidir. Yerel ağ içinde Ethernet frame’lerinin hangi cihaza gideceğini belirlemek için kullanılır. Her aygıtın kendine özgü olduğundan, ağda cihazları eşsiz şekilde tanımlar. Farkı; MAC: Aynı yerel ağ (LAN) içindeki cihazları benzersiz tanımlar, Ethernet frame’lerini hedef NIC’e ulaştırır. IP: Farklı ağlar arasında paketlerin doğru hedef ağa ve cihaza yönlendirilmesini sağlar.

5. Switch ve Router Farkı
Switch = Aynı ağ içi cihazlar arasında MAC’e göre hızlı anahtarlama.
Router = Farklı ağlar arasında IP’e göre yönlendirme.


7. İki bilgisayarı bir kabloyla bağladığınız her seferinde aslında bir ağ (network) oluşturuyorsunuz. Kablodan geçen sinyal, mesafe arttıkça zayıflar (dekar). Aynı odadaki iki bilgisayar arasında bu zayıflama genellikle sorun yaratmaz; sinyal hâlâ karşı tarafa ulaşır. Ancak iki bilgisayar binanın karşı uçlarına veya farklı binalara uzanıyorsa, sinyal kabloyu tamamlayamadan zayıflayıp ulaşımdan kalkabilir. Bu durumda, bilgisayarlar birbirine veri gönderemez.


8. Repeater (Yineleyici/Sinyal güçlendirici): yönlendiriciden ya da kablosuz modemden gelen Wi-Fi sinyalini alır ve sinyalin daha uzak mesafelere kayıpsız şekilde iletilmesini sağlar.  Yani bir uca giren hangi sinyal varsa, aynen diğer uca çıkar. Böylece uzak mesafelere yayılan kablolu veya kablosuz bağlantıda sinyal güçlendirilmiş olur.

9. Hub (Çoğaltıcı): Hub, çoklu bir repeater’dır. İçine gelen her Ethernet çerçevesini (frame) tüm portlarına kopyalar ve gönderir. Örneğin iki bilgisayar aralarında paket alışverişi yaparken hub, bu paketi tüm çıkış portlarına aynı anda çoğaltır. Hub sayesinde ağdaki cihaz sayısını artırmak kolaylaşır; ama her port hepsini alır, bu da bant genişliğini düşürür ve çarpışma (collision) ihtimalini yükseltir.

10. Bridge (Köprü): Bridge, iki hub grubunu birbiriyle bağlayan, yalnızca iki porta sahip bir cihazdır. Gelen çerçeveyi okur, MAC tablosunda hedef cihazın hangi portta olduğunu öğrendiyse sadece o port üzerinden iletir. Böylece gereksiz trafiğin diğer hub grubuna yayılmasını engeller. Başka bir deyişle, iletişimi sadece “gerektiği kadar” dolaşan broadcast domain’ler arasında sınırlar.

3. Switch (Anahtar); Switch Hub ve Brdige'lerin birleşimi gibi düşünebilir. Bir switch, Aynı ağ (broadcast domain) içindeki cihazları birbirine bağlar. OSI modelinin 2. katmanında (Data Link Layer) çalışan, birden fazla Ethernet cihazını (bilgisayar, sunucu, IP kamera vs.) birbirine bağlayarak frame’leri (Ethernet çerçevelerini) hedef MAC adresine göre ileten bir ağ cihazıdır.
Yani, Switch, her portta gördüğü cihazın MAC adresini öğrenir ve gelen çerçeveyi (frame) hedef MAC’e göre yalnızca ilgili porta iletir. Eğer Switch olmasaydı, Doğrudan kabloyla iki cihaz arasında iletişim kurmak için crossover kablo kullanılırdı; bu şekilde en fazla iki cihaz bağlanabilir.

6. Router (Yönlendirici): Router, ağ katmanında (OSI 3. katman) çalışan ve farklı Ağlardaki cihazları (IP ağlarını) birbirine bağlayan cihazdır. Gelen paketin hedef IP’sine bakar, en uygun çıkış arayüzüne (portuna) yollar. Kısacası, router olmadan farklı subnet’teki iki cihaz doğrudan iletişim kuramaz.
    - gateway (varsayılan geçit): Her bilgisayarın ağ ayarlarında bir “Default Gateway” IP’si vardır. Bu IP, o bilgisayarın kendi alt ağı içindeki router arayüzünün adresidir. Bir host, hedef IP’si kendi ağının dışındaysa paketi doğrudan bu gateway’e yollar. Router (gateway) paketi alır, hedefe uygun olarak başka bir ağa veya internete yönlendirir.Kısacası, Gateway = “benim ağımın dışına çıkan tüm paketleri alacak router’ın IP’si.”         -> (yani kısacası gateway: Router'ın IP adresidir.)   (Bir cihaz (host) hedefi kendi alt ağı dışındaysa, paketi doğrudan gönderemez. o yüzden gateway kullanmamız gerekiyor)
    default route, “başka bir route tanımlı yoksa tüm trafiği bu adrese yolla” kuralı.
