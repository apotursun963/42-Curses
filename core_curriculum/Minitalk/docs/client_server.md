
# Client Ve Server İlişkisi Nedir ?
-----------------------------------
`Client` ve `Server` ilişkisi temelde client'in yolladığı istekler (**request**) ve sunucunun bu isteklere karşı verdiği yanıtlardan (**response**) oluşur.

## Client (İstemci):
Client, bir sistemde sunucuyla iletişim kurarak veri talep eden ve bu veriyi işleyip kullanıcıya sunan bir yapıdır. Kullanıcı tarafından gerçekleştirilen işlemleri sunucuya ileterek  iletişim sağlar ve sunucudan aldığı yanıtları kullanıcıya anlamlı bir şekilde iletir. yani kullanıcı ve server arasında **köprü** görevi görür.

### Client'in temel görevleri
- **Sunucuya istek gönderme (request)**:
    - Client, kullanıcıdan aldığı bilgiyi/görevi Server'a istek olarak gönderir. Bu istek genellikle HTTP(S) gibi bir protokol üzerinden gerçekleşir.

- **Sunucu yanıtını alma ve işleme (response)**:
    - Client, Server'dan gelen yanıtı alır ve bu yanıtı kullanıcı için anlamlı bir şekilde işler. ve kullanıcıya gösterir. örneğin, bir web tarayıcısı, sunucudan aldığı HTML ve CSS dosyalarını işler ve ekrana bir web sayfası olarak yansıtır.


## Server (Sunucu):
Server, istemcilerden gelen talebleri kabul eden, bu istekleri işleyen ve gerekli yanıtları dönen bir yazılımdır.

### Server'ın temel görevleri
- **İstemcilerden istek alma (request)**:
    - Server, istemciden gelen istekleri bir ağ protokolü (örneğin, HTTP, FTP, SMTP) üzerinden alır. Örneğin: Bir kullanıcı bir web tarayıcısında bir URL'yi tıkladığında, tarayıcı bu URL'yi içeren bir istek gönderir ve server bu isteği alır.

- **İstekleri işleme**:
    - Server, gelen isteği analiz ederek uygun işlemleri gerçekleştirir. Örneğin: Eğer bir web sayfası talep ediliyorsa, server gerekli HTML, CSS ve JavaScript dosyalarını hazırlar.

- **İstemciye Yanıt göndreme (response)**:
    - Server, işlenen isteğin sonucunu istemciye yanıt olarak gönderir. Örnek yanıtlar: HTML, JSON

![Client-Server](https://upload.wikimedia.org/wikipedia/commons/thumb/c/c9/Client-server-model.svg/1200px-Client-server-model.svg.png)
