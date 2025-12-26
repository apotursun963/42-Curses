
Aşağıda **Docker’ı tamamen kavramanı sağlayacak**, zorluk seviyelerine göre ilerleyen **egzersizler ve mini projeler** listesi hazırladım. Hepsini adım adım yaparsan Docker mantığını %100 oturtursun.

---

# 🟩 **Seviye 1 — Temel Egzersizler (Isınma)**

![Image](https://www.docker.com/app/uploads/2021/11/docker-containerized-and-vm-transparent-bg.png?utm_source=chatgpt.com)

![Image](https://docs.docker.com/get-started/images/docker-architecture.webp?utm_source=chatgpt.com)

### ✅ **1. Hello Docker**

**Amaç:** Image → Container arasındaki ilişkiyi anlamak.
**Görev:**

* Basit bir `Dockerfile` yaz.
* İçine sadece `echo "Hello Docker"` yapan bir script koy.
* Image’ı build et, container’ı çalıştır.

**Kazandığın şey:** Build–Run mantığını anlamak.

---

### ✅ **2. Python Script Containerization**

**Amaç:** Uygulamanı container içine yerleştirmeyi öğrenmek.
**Görev:**

* Basit bir Python kodu yaz (`print("Docker öğreniyorum")`)
* Bunu container içinde çalıştır.

**Ekstra:** Kodun dışarıdan parametre almasını sağla.

---

### ✅ **3. Port Açma (EXPOSE / -p)**

**Amaç:** Container’ın dış dünya ile konuşmasını öğrenmek.
**Görev:**

* Flask ile çok basit bir web server yaz.
* `5000` portunu aç.
* Port mapping yaparak tarayıcıdan gör:

```sh
docker run -p 5000:5000 flask-app
```

---

# 🟨 **Seviye 2 — Orta Seviye Egzersizler (Mantığı Pekiştirme)**

![Image](https://docker-docs.uclv.cu/storage/images/types-of-mounts-bind.png?utm_source=chatgpt.com)

![Image](https://media2.dev.to/dynamic/image/width%3D1280%2Cheight%3D720%2Cfit%3Dcover%2Cgravity%3Dauto%2Cformat%3Dauto/https%3A%2F%2Fdev-to-uploads.s3.amazonaws.com%2Fuploads%2Farticles%2Fkovqfq6zmrjzomygfxg9.png?utm_source=chatgpt.com)

![Image](https://miro.medium.com/v2/resize%3Afit%3A1400/1%2ARgfuJCT7OEJanx8p3kuOrA.png?utm_source=chatgpt.com)

![Image](https://media.geeksforgeeks.org/wp-content/uploads/20230426184651/microsoft-azure-load-balancing.webp?utm_source=chatgpt.com)

### ✅ **4. Volumes Deneyi**

**Amaç:** Verinin container silinse bile kaybolmamasını öğrenmek.
**Görev:**

* Bir Python scripti yaz, her çalıştığında dosyaya tarih yazsın.
* Container silinse bile dosyanın korunmasını sağla.

**Komut:**

```sh
docker run -v data:/app/data myapp
```

---

### ✅ **5. Environment Variables Kullanımı**

**Amaç:** Config yönetimini kavramak.
**Görev:**

* Bir uygulama yaz (Flask olabilir).
* `APP_MODE` isminde environment variable oku.
* `dev` → "Development Mode"
* `prod` → "Production Mode"
  şeklinde çıktı versin.

---

### ✅ **6. Docker Network ile 2 Container Konuşturma**

**Amaç:** Mikroservis mantığını anlamak.
**Görev:**

* Bir container Flask API olsun (api_service)
* Bir container Python script olsun (client_service)
* Client, API’den veri çeksin.
* İki container da aynı network içinde olsun.

Konsept:

```sh
docker network create mynet
docker run --network=mynet api_service
docker run --network=mynet client_service
```

---

# 🟧 **Seviye 3 — İleri Seviye Mini Projeler (Gerçek Senaryolar)**

![Image](https://media.geeksforgeeks.org/wp-content/uploads/20240715174859/Microservices-with-Docker-Containers.webp?utm_source=chatgpt.com)

![Image](https://www.researchgate.net/publication/351626260/figure/fig1/AS%3A1024410047750148%401621249796981/Microservice-architecture-with-docker.png?utm_source=chatgpt.com)

![Image](https://labs.iximiuz.com/content/files/tutorials/docker-multi-stage-builds/__static__/multi-stage-build.png?utm_source=chatgpt.com)

![Image](https://media2.dev.to/dynamic/image/width%3D800%2Cheight%3D%2Cfit%3Dscale-down%2Cgravity%3Dauto%2Cformat%3Dauto/https%3A%2F%2Fdev-to-uploads.s3.amazonaws.com%2Fuploads%2Farticles%2Fd97mifvnbylgfverzea2.png?utm_source=chatgpt.com)

### 🚀 **7. Multi-Stage Dockerfile ile Prod Build**

**Amaç:** Gerçek şirketlerde kullanılan Dockerfile yapısını öğrenmek.
**Görev:**

* Bir React veya Node.js projesi seç.
* Multi-stage Dockerfile yaz:

  * Stage 1 → Build
  * Stage 2 → Sadece build çıktısını çalıştır

**Hedef:** Image boyutunu min 2 kat küçült.

---

### 🚀 **8. Docker Compose ile 3 Servislik Uygulama**

**Amaç:** Docker Compose mantığını tamamen oturtmak.
**Görev:**
3 servisten oluşan bir sistem kur:

* **web** (Flask / Node.js)
* **db** (PostgreSQL)
* **redis** (cache)

Hepsi `docker-compose.yaml` içinde yönetilecek.

Ekstra:

* Web servisi .env dosyasından DB bilgilerini alsın.

---

### 🚀 **9. Fullstack Blog Uygulaması (Dockerized)**

**Amaç:** Gerçek bir projeyi baştan sona containerize etmek.
**Görev:**

* Backend: Flask veya Node.js
* Frontend: React
* Database: PostgreSQL
* Reverse proxy: Nginx
* Hepsini `docker-compose` ile ayağa kaldır.

Sonuç:
Tarayıcıya `http://localhost` yaz → Blog açılacak.

---

# 🟥 **Seviye 4 — Uzman Seviyesi (DevOps Mantığı)**

![Image](https://docs.docker.com/engine/swarm/images/swarm-diagram.webp?utm_source=chatgpt.com)

![Image](https://k21academy.com/wp-content/uploads/2021/08/Swarm_ArchitectureDiagram.png?utm_source=chatgpt.com)

![Image](https://kubernetes.io/images/docs/kubernetes-cluster-architecture.svg?utm_source=chatgpt.com)

![Image](https://kubernetes.io/images/docs/components-of-kubernetes.svg?utm_source=chatgpt.com)

### 🔥 **10. Load Balanced Web App (Docker Swarm)**

**Amaç:** Şirketlerdeki production mantığını öğrenmek.
**Görev:**

* Basit bir web app image’ı oluştur.
* Swarm mode aç:

  ```sh
  docker swarm init
  ```
* Replicas = 3 olacak şekilde deploy et.

**Hedef çıktı:**
Tarayıcıyı yeniledikçe container id değişecek.

---

### 🔥 **11. Nginx + App + DB — Production Mimari**

**Amaç:** Kurumsal seviyede Docker kullanımı.
**Görev:**

* Nginx → Reverse proxy
* Uygulama (Flask/Node)
* PostgreSQL
* Log ve volume yönetimi
* Multi-network kullanarak izole ortam

---

# 🎯 Tavsiye: Ben seviye seviyeyi takip ederek sana her projeyi yazdırabilirim

İstersen:

👉 **“Seviye 1 egzersizlerini birlikte yapalım”** diyebilirsin.
👉 Ya da **herhangi bir projeyi seç** → bütün kodları + Dockerfile + compose dosyası + adım adım talimatları çıkarayım.

Hangisiyle başlamak istersin TursunAldo?
