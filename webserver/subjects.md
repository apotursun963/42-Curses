
# subjcets - webserver

## Introduction (Giriş)
- Hiper Metin Aktarım Protokolü (HTTP), dağıtık, işbirliğine dayalı ve hipermedya bilgi sistemleri için kullanılan bir uygulama protokolüdür.
- HTTP, Dünya Çapında Ağ’ın (World Wide Web) veri iletişiminin temelini oluşturur. Hipermetin belgeleri, kullanıcının kolayca erişebileceği diğer kaynaklara bağlantılar (hiperlinkler) içerir. Örneğin, bir web tarayıcısında fareyle tıklayarak ya da ekrana dokunarak bu bağlantılara erişilebilir.
- HTTP, hipermetin işlevselliğini desteklemek ve World Wide Web’in büyümesini sağlamak amacıyla geliştirilmiştir.
- Bir web sunucusunun temel görevi, web sayfalarını depolamak, işlemek ve istemcilere iletmektir. İstemci–sunucu iletişimi Hiper Metin Aktarım Protokolü (HTTP) üzerinden gerçekleşir.
- Sunulan sayfalar çoğunlukla HTML belgeleridir. Bu belgeler, metin içeriğine ek olarak resimler, stil dosyaları (CSS) ve betikler (scriptler) içerebilir.
- Yüksek trafikli bir web sitesinde birden fazla web sunucusu kullanılabilir ve trafik birden fazla fiziksel makine arasında paylaştırılabilir.
- Bir kullanıcı aracısı (genellikle bir web tarayıcısı veya web tarayıcı botu), HTTP kullanarak belirli bir kaynağı talep ederek iletişimi başlatır. Sunucu ise bu kaynağın içeriğini gönderir ya da bunu yapamıyorsa bir hata mesajı döndürür. Kaynak genellikle sunucunun depolama alanında bulunan gerçek bir dosya ya da bir programın ürettiği sonuçtur. Ancak bu her zaman böyle olmak zorunda değildir; kaynak pek çok farklı şey olabilir.
- HTTP’nin temel işlevi içerik sunmak olsa da, istemcilerin veri göndermesine de olanak tanır. Bu özellik, dosya yüklemeyi de içeren web formu gönderimlerinde kullanılır.

## General rules
- Programınız hiçbir koşulda (bellek yetersizliği yaşansa bile) çökmemeli veya beklenmedik şekilde sonlanmamalıdır. Aksi takdirde, projeniz çalışmıyor kabul edilir ve notunuz 0 olur.
- Kaynak dosyalarınızı derleyen bir Makefile teslim etmelisiniz. Makefile gereksiz yeniden derleme (relinking) yapmamalıdır.
- Kodunuz C++98 standardına uygun olmalı ve `-std=c++98` bayrağı eklendiğinde de sorunsuz şekilde derlenmelidir.
- Mümkün olduğunca C++ özelliklerinden faydalanın (örneğin `<string.h>` yerine `<cstring>` kullanın).
  C fonksiyonlarını kullanabilirsiniz, ancak mümkünse C++ karşılıklarını tercih edin.
- Her türlü harici kütüphane ve Boost kütüphaneleri yasaktır.


## Mandatory part 
* Tanım: C++98 standardında bir **HTTP servisi** yazmak
* Programıın Çalışması için: ./webserv [configuration file]

- UYARI: Bu projeye başlamadan önce HTTP protokolünü tanımlayan RFC dokümanlarını okuyunuz ve
telnet ve NGINX kullanarak testler yapınız.
gerekli özellikleri geliştirmenize yardımcı olacaktır.
HTTP 1.0, bir referans noktası olarak önerilmektedir, ancak zorunlu değildir.

    * RFC (Request for Comments), RFC’ler; internetin ve ağ protokollerin nasıl çalıştığını tanımlayan kurallar ve standartlardır. yani, “Bu protokol böyle çalışır, kuralları bunlardır” diyen belgelerdir.
    projede RFC okumamızı istemelerinin sebebi, HTTP’nin: Request formatın, Response yapısın, Status code’lar ve  Header’ları Doğru ve standartlara uygun yazmanı isterler.
    (RFC dokümantasyon -> https://www.rfc-editor.org | https://www.rfc-editor.org/info/rfc1945)
    - nginx ve telnet ile test yapma süreci:
    👉 Telnet ile nginx web sunucusuna manuel bir HTTP isteği gönderdin ve gerçek bir HTTP cevabı aldın.
        * öncelikle nginx ve telnet indirdim. nginx başlattım ve *telnet localhost 80* ile nginx bağlandım
        bağlanma (telnet localhost 80)
            - Bilgisayarından 127.0.0.1 (localhost) adresindeki, 80 numaralı porta (HTTP’nin varsayılan portu), TCP bağlantısı kurdun
        sonrasında *GET / HTTP/1.0* isteğini attım
        istek anlamı -> “Bana ana sayfanın HTML içeriğini gönder.”
            - GET -> “Bana veri gönder”
            - / -> root'u (ana dizi) istiyorum
            - HTTP/1.0 -> “Bu isteği HTTP/1.0 kurallarına göre yapıyorum”
        nginx ise bir *HTTP response* döndürdü. HTTP CEVABININ YAPISI
        Bir HTTP response 3 ana bölümden oluşur: Status Line, Headers, Body
        1. satus line: HTTP/1.1 200 OK
            - HTTP/1.1 -> Server’ın cevapladığı protokol
            - 200 -> status code  (status code 200: “İstek başarılı, istediğin kaynağı sana gönderiyorum.” demek)
            - OK -> Status açıklaması
        2. Headers
            - Content-Type -> Gönderilen verinin türü
            - Content-Length -> Body kaç byte/uzunluk?
                content-lenght önemlidir, çünkü client'a şunu söyler, “Body kısmında tam olarak kaç byte veri geleceğini bil.” Client bu bilgi olmadan ne zaman duracağını bilemez.
                HTTP, TCP üzerinde çalışır ve TCP "mesaj şurada bitti" diye söylemez. o yüzden HTTP'nin body nerede bitiyor olması gerekir. işte orada (content-lenght) devreye giriyor
                kısacası, Content-Length, HTTP body’sinin nerede bittiğini client’a söyleyen hayati bilgidir. Yanlışsa, HTTP bozulur.
            - Connection -> İş bitince bağlantıyı kapat (close için)
        SÜREÇ:
        -----
        Client (telnet)
           |
           |  GET / HTTP/1.0
           |
        Server (nginx)
           |
           |  HTTP/1.1 200 OK
           |  Headers
           |  (boş satır)
           |  HTML Body
           |
           |  Connection close
    ÖZETLE, Tarayıcı olmadan, telnet ile HTTP protokolünü elle kullanarak nginx’in gerçekten HTTP isteğini anlayıp cevap verdiğini test etmiş oldun.
    Bu testte, HTTP’nin metin tabanlı olduğunu; Tarayıcının aslında sadece GET gönderen bir istemci olduğunu ve Web sunucusunun TCP + HTTP mantığını yaptık.


### Requirements (Gereksinimler)
- Programın, komut satırında argüman olarak verilen bir yapılandırma (configuration) dosyasını kullanması gerekir ya da bu dosya varsayılan (default) bir dizinde bulunmalıdır.
- Başka bir web sunucusunu execve ile çalıştıramazsın.
- Sunucun her zaman non-blocking (bloklamayan) çalışmalı ve gerektiğinde istemci bağlantı kopmalarını doğru şekilde yönetmelidir.
- Sunucu non-blocking olmalı ve istemciler ile sunucu arasındaki tüm I/O işlemleri için (listen dâhil) yalnızca tek bir poll() (veya eşdeğeri) kullanılmalıdır.
- poll() (veya eşdeğeri) aynı anda hem okuma (read) hem yazma (write) işlemlerini izlemelidir.
- poll() (veya eşdeğeri) kullanmadan asla read veya write işlemi yapmamalısın.
- Bir *read* veya *write* işleminden sonra sunucunun davranışını ayarlamak için errno değerini kontrol etmek kesinlikle yasaktır.
- Normal disk dosyaları için poll() (veya eşdeğeri) kullanmak zorunda değilsin; bunlarda yapılan read() ve write() işlemleri hazır olma (readiness) bildirimi gerektirmez.

- UYARI: Veri gelmesini bekleyebilen tüm I/O’lar (socket’ler, pipe/FIFO’lar vb.) non-blocking olmalı ve tek bir poll() (veya eşdeğeri) tarafından yönetilmelidir.
Hazır oldukları poll() ile doğrulanmadan, bu tanımlayıcılar (descriptor’lar) üzerinde read/recv veya write/send çağrısı yapmak, notunun 0 olmasına neden olur.
Normal disk dosyaları bu kuralın dışındadır.

- poll() veya eşdeğeri bir çağrı kullanırken, ona ait tüm makroları veya yardımcı fonksiyonları kullanabilirsin
(örneğin select() için FD_SET).
- Sunucuna yapılan bir istek asla süresiz şekilde takılı (hang) kalmamalıdır.
- Sunucun, seçeceğin standart web tarayıcılarıyla uyumlu olmalıdır.
- NGINX, header’ları ve yanıt davranışlarını karşılaştırmak için kullanılabilir
- (HTTP sürümleri arasındaki farklara dikkat et).
- HTTP response (yanıt) durum kodların doğru/uygun olmalıdır.
- Eğer özel bir hata sayfası sağlanmamışsa, sunucunun varsayılan (default) hata sayfaları olmalıdır.
- fork kullanımı, yalnızca CGI için serbesttir (PHP, Python vb.); bunun dışında kullanamazsın.
- Sunucun tamamen statik bir web sitesini servis edebilmelidir.
- İstemciler (clients) dosya yükleyebilmelidir.
- En azından GET, POST ve DELETE HTTP metotlarını desteklemen gerekir.
- Sunucunu stres testine tabi tutarak, her zaman erişilebilir (available) kaldığından emin olmalısın.
- Sunucun, farklı içerikler sunmak için birden fazla portu dinleyebilmelidir
(bkz. yapılandırma / configuration dosyasını gör).

- UYARI: HTTP RFC’nin yalnızca bir alt kümesini bilerek seçtik.
Bu bağlamda virtual host (sanal barındırma) özelliği kapsam dışı (out of scope) kabul edilmektedir.
Ancak istersen, bunu implement etmen serbesttir.


### Configuration file (Yapılandırma Dosyası)
*NGINX yapılandırma dosyasındaki server bölümünden ilham alabilirsiniz.*
Yapılandırma dosyasında şunları yapabiliyor olmalısınız:
- Sunucunuzun dinleyeceği tüm arayüz:port (interface:port) çiftlerini tanımlamak
(programınız tarafından sunulan birden fazla web sitesini tanımlamak).
- Varsayılan hata sayfalarını (error pages) ayarlamak.
- İstemci istek gövdeleri (request body) için izin verilen maksimum boyutu belirlemek.
- Bir web sitesi için, bir URL/rota üzerinde (burada Regex gerekmez) aşağıdaki kuralları veya yapılandırmaları belirtin:
    * Rota (route) için kabul edilen HTTP metotlarının listesi.
    * HTTP yönlendirmesi (redirections)
    * İstenen dosyanın bulunması gereken dizin (örneğin; eğer /kapouet URL'si kök olarak /tmp/www dizinine ayarlanmışsa, /kapouet/pouic/toto/pouet URL'si /tmp/www/pouic/toto/pouet yolunu arayacaktır).
    * Dizin dinlemeyi/listelemeyi (directory listing) etkinleştirme veya devre dışı bırakma.
    * İstenen kaynak bir dizin olduğunda sunulacak varsayılan dosya (default file).
    * İstemcilerden sunucuya dosya yüklemeye (upload) izin verilmesi ve depolama konumunun sağlanması.
    * Dosya uzantısına dayalı olarak CGI çalıştırılması (örneğin .php). İşte CGI'lar ile ilgili bazı özel notlar:
        - CGI'ın ne olduğunu merak ediyor musunuz? (https://en.wikipedia.org/wiki/Common_Gateway_Interface)
        - Web sunucusu-CGI iletişiminde yer alan ortam değişkenlerini (environment variables) dikkatlice inceleyin. İstemci tarafından sağlanan tam istek ve argümanlar CGI için erişilebilir olmalıdır.
        - Şunu unutmayın ki; "chunked" (parçalı) istekler için sunucunuzun bunları "un-chunk" etmesi (birleştirmesi) gerekir; CGI, gövdenin (body) sonu olarak EOF bekleyecektir.
        - Aynısı CGI çıktısı için de geçerlidir. Eğer CGI'dan bir content_length döndürülmezse, EOF döndürülen verinin sonunu işaret edecektir.
        - Göreli yol (relative path) dosya erişimi için CGI doğru dizinde çalıştırılmalıdır.
        - Sunucunuz en az bir CGI desteklemelidir (php-CGI, Python vb.).
- Değerlendirme sırasında her özelliğin çalıştığını test etmek ve göstermek için yapılandırma dosyaları ve varsayılan dosyalar sağlamalısınız. 
- Dosyanızda başka kurallar veya yapılandırma bilgileri de yer alabilir (örneğin; sanal sunucuları [virtual hosts] uygulamayı planlıyorsanız, bir web sitesi için sunucu adı).
Kısacası, son 2 madde şunu özetliyor, projeni kontrol edecek kişi (evaluator) geldiğinde, sunucunun tüm yeteneklerini (CGI, upload, yönlendirme vb.) hızlıca test edebilmesi için hazır bir config dosyası ve test dosyaları (örneğin test amaçlı bir index.html veya test.php) hazırlaman gerektiğini vurguluyor.



* TAVSİYE/İLHAM: Belirli bir davranış (sunucunun nasıl tepki vermesi gerektiği) hakkında sorunuz olursa, programınızın davranışını NGINX'inki ile karşılaştırabilirsiniz.
Küçük bir test aracı (tester) sağladık. Eğer tarayıcınızla ve testlerinizle her şey düzgün çalışıyorsa bu aracı kullanmanız zorunlu değildir; ancak hataları bulup düzeltmenize yardımcı olabilir.


* UYARI: 
    - Dayanıklılık (Resilience) anahtar noktadır. Sunucunuz her zaman çalışır durumda kalmalıdır.
    - Yalnızca tek bir programla test yapmayın. Testlerinizi, isterseniz C veya C++ ile, isterseniz de Python veya Golang gibi daha uygun bir dilde yazın.




