
# webserver
Bu projeyi yaptıktan sonra URL'in neden HTTP ile başladığını öğrenmiş olacaksın.
projenin bizden istediği şey, kendi HTTP servisini (sunucunu) yazmaktır.
HTTP servisini gerçek browser'da test edebileceksin.

## HTTP Nedir Benim Tanımım
HTTP (Hypertext Transfer Protocol – Hiper Metin Aktarım Protokolü), internet üzerinde istemci (client) ile sunucu (server) arasında veri alışverişini sağlayan bir iletişim protokolüdür.
Yani, HTTP, tarayıcın (Chrome, Firefox vb.) ile web sitelerinin sunucuları arasında konuşmayı sağlayan dil gibidir
Nasıl çalışır?
- Sen tarayıcıya bir adres yazarsın (örneğin: www.ornek.com)
- Tarayıcı, sunucuya HTTP isteği (request) gönderir
- Sunucu bu isteği alır
- İstenen veriyi (web sayfası, resim, video vb.) HTTP cevabı (response) olarak geri gönderir
- Tarayıcı da bunu sana gösterir

HTTP ne taşır?
- HTML sayfaları, Resimler, CSS dosyaları, JavaScript dosyaları, Form verileri (kullanıcı adı, şifre vb.), Dosya yükleme / indirme verileri

HTTP’nin önemli özellikleri:
- İstemci–sunucu mantığıyla çalışır
- Stateless’tir → Yani her istek bağımsızdır, önceki isteği hatırlamaz
- Hızlı ve basittir
- Web’in temelidir

HTTP VS HTTPS
- HTTP: Veriler açık şekilde gider
- HTTPS: Veriler şifrelenir (daha güvenli)

### Protocol
Protokol, bilgisayarlar/sistemler/servisler arasında iletişimin nasıl yapılacağını belirleyen kurallar bütünüdür. (“Kim, neyi, ne zaman, nasıl gönderir?” sorularının cevabıdır.)
Bir protokol şunları tanımlar:
- Veri nasıl gönderilecek?
- Hangi formatta olacak?
- Sırası ve hızı ne olacak?
- Hata olursa ne yapılacak?

Özetleyecek olursam, HTTP, web tarayıcılarının web siteleriyle nasıl iletişim kuracağını belirleyen kurallar bütünüdür.

## web server terms

