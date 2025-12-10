
# inception
Projenin Bizden istediği; Docker üzerinden bir Wordpress sitesi kurmanız isteniyor. Bununla birlikte Nginx ve MariaDB servislerini kullanmanız gerekiyor.


## Docker Nedir ?
Docker; Uygulamalar oluşturmanı, test etmeni ve depolamanı sağlayan bir yazılım platformudur.
container (kapsayıcı) denilen izole ortamlar içinde uygulamları çalıştırmamızı sağlar. (vm ile farkı nedir)
Bu containerlar, uygulamanın tüm bağımlılıklarıyla birlikte (kütüphaneler, ayarlar, araçlar, işletim sistemi bileşenleri vs.) paketlenmesini sağlar.
Böylece uygulama, nerede çalışırsa çalışsın aynı şekilde davranır.
Docker, “Bilgisayarımda çalışıyor ama sunucuda/başka bir bilgisayarda çalışmıyor!” sorununu ortadan kaldırır.
Temel Amaç
- Yazılımı, çalışması için gerekli her şeyle birlikte tek bir pakette toplamak.
- Her ortamda (geliştirme, test, üretim) aynı şekilde çalışmasını sağlamak.
- Kurulum, yapılandırma ve bağımlılık sorunlarını ortadan kaldırmak.



-Deploy(Dağıtmak) -> Uygulamayı yayına almak/Uygulamayı çalışır hale getirmek/Sunucuya/cihaza yükleyip çalıştırmak
    - örnek olarak bir web sitesi yaptım ve sunucuya yüklediğimde deploy etmiş oluyorum.

-Port -> Portlar, temel olarak veri akışını doğru hedeflere yönlendirmek için kullanılan sanal veya fiziksel bağlantı noktalarıdır. yani, bilgisayarda veya bir ağ üzerinde verilerin geçiş yaptığı kapı gibidir.
Port, gelen verinin hangi program veya servise gideceğini belirler.
sabit port numaraları: 80 -> Web siteleri (HTTP) | 443 -> Güvenli web siteleri (HTTPS) | 22 -> SSH bağlantısı
Toplam 65.536 adet port vardır.
Her servis/uygulama kendi portunu dinler.
Bir bilgisayarda çalışan her uygulama (servis) belirli bir port numarasını sürekli kontrol eder.
Bu port üzerinden gelen veriyi bekler.
Buna port dinlemek (listening on port) denir.
kısacası, Her servis kendi portunu dinler → Her uygulama kendisine ayrılmış port numarasını sürekli kontrol eder ve bu porttan gelen bağlantıları kabul eder.

-Boot -> bir bilgisayarın veya cihazın açılırken işletim sistemini yükleme ve çalıştırma sürecine verilen isimdir. Yani cihazın “açılıp çalışır hale gelme” mekanizmasıdır.

-isolation -> Bir uygulamanın/servisin/sürecin diğerlerinden tamamen ayrılmış, kendi başına çalışan bir ortamda çalışması anlamına gelir. Diğer uygulamalar onunla çakışamaz, karışamaz, bozmaz.

-demo (gösterim) -> Demo, bir ürünün, uygulamanın, oyunun veya yazılımın deneme sürümü, tanıtım amaçlı kısa versiyonu veya örnek gösterimi demektir. Ürünün nasıl çalıştığını göstermek için hazırlanmış örnek sürümdür.
özellikleri göstermek, müşteriyi ikna etmek sunum veya tanıtım yapmak için kullanılır.

-monitoring(izleme) -> Bir sistemin, uygulamanın veya sunucunun performansını, sağlığını ve hatalarını sürekli olarak takip etme ve ölçme işlemidir. (monitoring örnekleri; GRAFANA, Prometheus)
monitoring şunları izleyebilir; CPU kullanımı, RAM tüketimi, Disk doluluk, Ağ trafiği

-Servis -> bir uygulamanın veya sistemin belirli bir işlevi yerine getiren bağımsız parçasına denir.
Yani bir yazılımın içinde tek bir görevi yapan küçük bir birimdir.
Bir web uygulaması vardır; fronted ve backend ayrı servistir ikisinin farklı amaçları vardır.

-Component(Bileşen) -> Bir uygulamanın küçük, bağımsız, tekrar kullanılabilir parçasıdır.
Component, belirli bir görevi yerine getiren, kendi içinde çalışan, bağımsız bir modüldür.
Bir uygulama, birçok component’in birleşmesiyle oluşur.



## Docker Nedir ?
Eskiden, insanlar bir uygulamayı deploy ettiğinde local'de çalıştığını ama sunucunda veya 
başka bilgisayarlarda çalışmadığını fark etmişsindir.
bunun nedeni deploy ettiğin uygulama senin bilgisayarındaki bağımlılıklara bağlı olmasıdır.
senin bilgisayarında; 
doğru sürüm Node/Python, gerekli kütüphaneler, doğru ortam değişkenleri (env), doğru path ayarları, port sorunu
bunlar zaten bilgisayarında yüklü olduğu için uygulama çalışır.

Ama başka bir bilgisayarda bunlar yoktur, bu yüzden uygulama çalışmaz:
eksik kütüphane, farklı Node/Python/Java sürümü, yanlış PATH ve ENV

Yani, kısacası "benim PC’de çalışıyor ama başkasında çalışmıyor" sorunu ortaya çıkıyordu.

işte bu sorunu çözmek için yani Uygulamayı başka bir bilgisayarda da çalışacak şekle getirmek için
en uygun çözüm "uygulamayı Docker’la paketlemek" yani "Docker" kullanmak.

Docker'ın şöyle avantajı var; başka pc farklı işletim sistemine sahip olabilir
veya kütüphaneler yüklü olmayabilir kısacası, hiçbir bağımlılık olmayabilir
Fark etmez
Docker kullandığımızda kendi pc'mde yazdığım uygulama her yerde aynı şekilde çalışır.
Çünkü "Docker bütün bağımlılıkları yanına koyarak paketler"

Özetle, deploy ettiğin bir uygulamayı herkes her yerden çalıştırabilmesini istiyorsan
Docker ile kendi bilgisayarındaki bağımlılıkları paketlemen gerekiyor.

### Docker Kavramları
1. Image: Bir uygulamanın çalışması için gerekli her şeyin paketlenmiş hali
    - kod, kütüphane, bağımlılık..
2. Container: Image’in çalışan hali. Image = program | Container = çalışan program
    - Her container izole bir ortamdır. kendi dosya sistemi, portları, process’leri, paketleri vardır.
3. Dockerfile: Image’i nasıl oluşturacağını tanımladığın talimat dosyası.
    - Bu dosya sayesinde image’ı otomatik oluşturursun.
4. Registry: Image’ların saklandığı depo. (docker hub, github, AWS, gitlab)
    - Sen image’ı push edersin, başkaları pull eder.
5. Volume: Container içindeki verinin kalıcı tutulduğu depolama.
    - Container silinse bile volume’daki veri durur.
    - örnek veriler: veritabanı dosyaları, log dosyaları, kullanıcı yüklemeleri
6. Network: Container’ların birbirleriyle haberleşmesini sağlayan sanal ağ.
7. Port Mapping: Container iç ve dış portların eşleştirilmesi.
    - localhost:8080 → container:3000
8. Docker Compose: Birden fazla container’ı tek bir YAML (.yml) dosyasıyla yönetmeni sağlar.
    - backend, frontend, database hepsini tek bir komutla çalıştırırsın
9. Containerization: Containerization, bir uygulamanın çalışması için gereken her şeyle birlikte (kod, kütüphaneler, bağımlılıklar, config’ler) tek bir paket haline getirilip izole bir ortamda çalıştırılmasıdır.
Virtual machine gibi ağır değildir. Saniyeler içinde başlar.
VM (Sanal Makine) gibi kendi işletim sistemini taşımaz, sadece uygulamayı çalıştırmak için gerekli minimum ortamı taşır.
    - Bu sayede uygulama: Her bilgisayarda, Her işletim sisteminde, Aynı şekilde Sorunsuz çalışır.


# Örnek Senaryo
bir web uygulaması var ve bu uygulamanın altında farklı servisler var ve bu 
servisler farklı kütüphaneler ve bağımlılıklar kullandığında "çakışma" olabilir.
Yani, Servisler aynı makinede çalışıyorsa çakışma çok kolay olur.
örnek senaryolar
- Bir servis Python 3.8 ister, diğeri Python 3.11, aynı bilgisayarda aynı anda kullanmak zordur.
- İki servis aynı portu dinlemek ister (mesela ikisi de 3000).
- Bir servis PostgreSQL 14, diğeri PostgreSQL 16 ister — sürüm karmaşası çıkar.
Bu nedenle servisler arasında bağımlılık çakışması çok yaygın bir problemdir.

Bunun çözümü ise, Containerization'dır.
Her servisi kendi kutusuna koymak.
yani bir servis var ve servisin kullandığı kütüphaneleri, bağımlılıkları ayrı
ve izole bir şekilde diğer servislerden ayrı olacak şekilde paketlemek/koymak.
Böylece servisler birbirlerine asla karışmaz.
Peki Containerization bunu nasıl yapıyor.
- Her servis için ayrı bir Dockerfile yazılır
- Her Dockerfile kendi ortamını yaratır.

Örnek Çakışma durumu:
- Backend → Node 16
- Frontend → Node 20
Normalde aynı bilgisayarda sorun olur.
Ama Docker sayesinde:
Her ikisi de kendi Node sürümü ile çalışır.
Birbirlerini hiç görmezler → çakışma 0.

Özetle Containerization ile;
- Servisler birbirinden tamamen izole olur.
- Her servis farklı diller, farklı kütüphaneler, farklı sürümler kullanabilir.
- Port çakışmaları engellenir.
- Bağımlılık çakışmaları engellenir.
- Servisler bağımsız geliştirilir ve deploy edilir.

Her servis kendi container’ında → çakışma tamamen ortadan kalkar.


Docker, containerlar ve işletim sistemi arasında olan bağlantıları kurar.
Container -> Docker <- OS


## Virtualization ve Containerization farkını güzel bir şekilde öğren
