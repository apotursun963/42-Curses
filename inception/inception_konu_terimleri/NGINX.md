# 🌐 NGINX Nedir?

**NGINX (engine-x diye okunur)**, yüksek performanslı bir **web sunucusu**, **reverse proxy**, **load balancer** ve **cache sunucusu** olarak çalışan güçlü bir yazılımdır.

Basitçe söylemek gerekirse:

> **NGINX, internette bir kullanıcı bir siteye girdiğinde, o isteği karşılayan ve doğru yere yönlendiren kapı görevlisidir.**

---

## 🧠 NGINX Ne İşe Yarar?

NGINX tek bir şey yapmaz, **birden fazla kritik görevi** vardır:

### 1️⃣ Web Sunucusu
Web sunucusu, internet üzerinden gelen kullanıcı isteklerini (HTTP/HTTPS) karşılayan ve bu isteklere web sayfaları veya dosyalarla cevap veren bir sistemdir. Bir kullanıcı tarayıcıdan bir web sitesine girdiğinde, web sunucusu bu isteği alır, gerekli HTML, CSS, JavaScript veya diğer dosyaları (static & index dosyalar) bulur ve kullanıcıya gönderir. Kısaca web sunucusu, bir web sitesinin internette erişilebilir olmasını sağlayan temel yapıdır. Örnek web sunucuları: NGINX, Apache, IIS
* Tarayıcı → Web Sunucusu → Web Sitesi

Kullanıcı tarayıcıdan bir siteye girer:

```
kullanıcı → NGINX → HTML / CSS / JS
```

NGINX:

* Web sayfalarını sunar
* Statik dosyaları (resim, CSS, JS) **çok hızlı** servis eder

---

### 2️⃣ Reverse Proxy (En Önemli Kullanımı)
Reverse proxy, kullanıcıdan gelen istekleri doğrudan arka plandaki sunuculara göndermek yerine, bu istekleri önce kendisi karşılayan ve ardından uygun olan backend sunucuya ileten ara bir sunucudur. Kullanıcı, gerçek uygulama sunucularını görmez ve tüm iletişim reverse proxy üzerinden gerçekleşir. Bu yapı sayesinde backend sunucular gizlenir, güvenlik artar, trafik daha iyi yönetilir ve performans iyileştirilebilir. Ayrıca reverse proxy, HTTPS yönetimi, önbellekleme ve yük dengeleme gibi görevleri de üstlenebilir.
NGINX çoğu zaman **arkadaki uygulamaları korur**.

```
kullanıcı → NGINX → Backend (Node, Django, PHP, Java)
```

Avantajları:

* Backend direkt internete açık olmaz
* Güvenlik artar
* Trafik kontrol edilir

---

### 3️⃣ Load Balancer (Yük Dengeleme)
Load Balancer (yük dengeleyici), kullanıcılardan gelen istekleri tek bir sunucuya yüklenmek yerine, birden fazla sunucuya dengeli şekilde dağıtan sistemdir. Amaç, sistemin daha hızlı, daha kararlı ve kesintisiz çalışmasını sağlamaktır. Yük dengeleyici sayesinde bir sunucu aşırı yüklenirse ya da devre dışı kalırsa, istekler otomatik olarak diğer çalışan sunuculara yönlendirilir. Bu yapı hem performansı artırır hem de servis sürekliliğini (high availability) sağlar.
Birden fazla sunucun varsa:

```
kullanıcı → NGINX
            ├─ Server 1
            ├─ Server 2
            └─ Server 3
```

NGINX:

* Gelen istekleri sunucular arasında paylaştırır
* Bir sunucu düşerse diğerine yönlendirir

---

### 4️⃣ Cache (Önbellekleme)
Cache (önbellekleme), sık kullanılan verilerin veya istek sonuçlarının geçici olarak daha hızlı erişilebilen bir yerde (RAM, DİSK, TARAYICI, CDN) saklanması işlemidir. Kullanıcı aynı veriyi tekrar istediğinde, sunucu bu veriyi yeniden üretmek veya backend’e gitmek yerine önbellekten sunar. Bu sayede sistem daha hızlı çalışır, sunucu yükü azalır ve kullanıcıya daha kısa sürede yanıt verilir. Web sistemlerinde cache; sayfalar, API cevapları, resimler veya diğer statik içerikler için kullanılabilir.
NGINX:

* Sık istenen cevapları hafızada tutar
* Backend’e her seferinde gitmez
* Site **çok daha hızlı açılır**

---

### 5️⃣ SSL / HTTPS Yönetimi
SSL / HTTPS yönetimi, bir web sitesi ile kullanıcı arasındaki veri iletişiminin şifrelenerek güvenli hale getirilmesi sürecidir. Bu yönetim sayesinde tarayıcı ile sunucu arasında gönderilen bilgiler üçüncü kişiler tarafından okunamaz veya değiştirilemez. Web sunucusu ya da NGINX gibi bir reverse proxy, SSL sertifikasını kullanarak HTTPS bağlantısını kurar, sertifikanın geçerliliğini kontrol eder ve gelen HTTP isteklerini HTTPS’e yönlendirebilir. Böylece kullanıcı güvenliği sağlanır, veri gizliliği korunur ve web sitesinin güvenilirliği artırılır.
NGINX:

* SSL sertifikalarını yönetir
* HTTP → HTTPS yönlendirmesi yapar
* Let’s Encrypt ile çok sık kullanılır

---

## 🚀 NGINX Neden Bu Kadar Popüler?

### 🔥 Apache’ye Göre Avantajları

| Özellik            | NGINX        | Apache |
| ------------------ | ------------ | ------ |
| Performans         | 🚀 Çok hızlı | Orta   |
| Bellek kullanımı   | Düşük        | Yüksek |
| Eşzamanlı bağlantı | Çok iyi      | Zayıf  |
| Modern mimari      | ✔️           | ❌      |

👉 Özellikle **yüksek trafikli sitelerde** NGINX tercih edilir.

---

## ⚙️ NGINX Nasıl Çalışır? (Kısa Teknik Mantık)

NGINX:

* **Event-driven (olay tabanlı)** çalışır
* Tek işlemle binlerce isteği yönetebilir
* Thread açmaz → RAM’i yormaz

Bu yüzden:

> **Aynı donanımda Apache’den çok daha fazla kullanıcıya hizmet eder**

## 🧠 Kısaca Özetlersek

> **NGINX**, web trafiğini yöneten, hızlandıran, güvenli hale getiren ve sistemin yükünü dengede tutan çok güçlü bir sunucudur.
