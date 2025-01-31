Minitalk
--------

_Amacı_:
Bu proje, UNIX sinyallerini kullanarak bir istemci (client) ve sunucu (server) arasında veri alışverişini gerçekleştiren bir program geliştirmeyi amaçlar.

Nasıl Çalışır:
Server: Öncelikle başlatılır ve PID’sini ekrana yazdırır.
Client: **PID** ve bir string parametresi alır. String’i server’a gönderir.
Server: Gelen string’i hızlıca ekrana yazdırır.
İletişim yalnızca `SIGUSR1` ve `SIGUSR2` sinyalleri ile sağlanır.
