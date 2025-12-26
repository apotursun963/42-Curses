
# Docker'da Kullanılan Bütün Komutlar

---

# 🔵 **1) IMAGE (İMAJ) KOMUTLARI**

### ✔ Image oluşturma

```bash
docker build -t image_adi:tag .
```

### ✔ Image’ları listeleme

```bash
docker images
```

### ✔ Image silme

```bash
docker rmi image_adi
```

### ✔ Kullanılmayan tüm image’ları silme

```bash
docker image prune -a
```

### ✔ Image’ı Docker Hub’a push etme

```bash
docker tag yerel_image kullanıcı/image:tag
docker push kullanıcı/image:tag
```

### ✔ Image inspect (detay görüntüleme)

```bash
docker inspect image_adi
```

---

# 🔵 **2) CONTAINER (KONTEYNER) KOMUTLARI**

### ✔ Container oluşturma + çalıştırma

```bash
docker run image_adi
```

### ✔ Container isim vererek çalıştırma

```bash
docker run --name container_adi image_adi
```

### ✔ Port yönlendirmeli çalıştırma

```bash
docker run -p 5000:5000 image_adi
```

### ✔ Arka planda (detached) çalıştırma

```bash
docker run -d image_adi
```

### ✔ Volume bağlayarak çalıştırma

```bash
docker run -v host_path:container_path image_adi
```

### ✔ Container’ları listeleme (çalışan)

```bash
docker ps
```

### ✔ Container’ları listeleme (tüm)

```bash
docker ps -a
```

### ✔ Container durdurma

```bash
docker stop container_adi
```

### ✔ Container başlatma

```bash
docker start container_adi
```

### ✔ Container yeniden başlatma

```bash
docker restart container_adi
```

### ✔ Container silme

```bash
docker rm container_adi
```

### ✔ Tüm durdurulmuş container’ları silme

```bash
docker container prune
```

### ✔ Container loglarını görme

```bash
docker logs container_adi
```

### ✔ Container içine terminal açma

```bash
docker exec -it container_adi /bin/bash
```

Ya da:

```bash
docker exec -it container_adi sh
```

### ✔ Container inspect (detay görüntüleme)

```bash
docker inspect container_adi
```

---

# 🔵 **3) DOCKER SYSTEM KOMUTLARI**

### ✔ Gereksiz her şeyi temizleme (image + container + network + cache)

```bash
docker system prune -a
```

### ✔ Docker disk kullanımını görme

```bash
docker system df
```

---

# 🔵 **4) VOLUME KOMUTLARI**

### ✔ Volume oluşturma

```bash
docker volume create volume_adi
```

### ✔ Volume listesi

```bash
docker volume ls
```

### ✔ Volume detay

```bash
docker volume inspect volume_adi
```

### ✔ Volume silme

```bash
docker volume rm volume_adi
```

---

# 🔵 **5) NETWORK KOMUTLARI**

### ✔ Yeni network oluşturma

```bash
docker network create network_adi
```

### ✔ Network listesi

```bash
docker network ls
```

### ✔ Network detay

```bash
docker network inspect network_adi
```

### ✔ Container’ı network’e bağlama

```bash
docker network connect network_adi container_adi
```

### ✔ Network silme

```bash
docker network rm network_adi
```

---

# 🔵 **6) DOCKER HUB & REGISTRY KOMUTLARI**

### ✔ Docker Hub’a giriş

```bash
docker login
```

### ✔ Docker Hub’dan image çekme (pull)

```bash
docker pull kullanıcı/image:tag
```

### ✔ Image tag’leme

```bash
docker tag kaynak:tag hedef:tag
```

---

# 🔵 **7) DOCKER COMPOSE KOMUTLARI**

### ✔ Compose ile servisleri başlatma

```bash
docker-compose up
```

### ✔ Arka planda başlatma

```bash
docker-compose up -d
```

### ✔ Tekrar build ederek başlatma

```bash
docker-compose up --build
```

### ✔ Durdurma

```bash
docker-compose down
```

### ✔ Tek servisi yeniden başlatma

```bash
docker-compose restart servis_adi
```

---

# 🔵 **8) DOCKERFILE KOMUTLARI (YAZIM TALİMATLARI)**

### ✔ Temel komutlar:

```dockerfile
FROM -> Olşuturacağın imajın temelini oluşturur. İçinde hangi işletim sistemi veya çalışma ortamının olacağını seçersin
    - FROM ubuntu:latest -> Docker şunu yapar; Ubuntu işletim sisteminden başlayarak imajı oluşturuyorum.
    - yani temeller kurulmuş ve hazır bir şekilde gelir.
    - FROM, Docker imajının temelini seçmendir.
        - Bu temel şunlardan biri olabilir:
            - Bir işletim sistemi → ubuntu, alpine
            - Bir program dili ortamı → python, node
            - Bir hazır servis → nginx, mysql
RUN -> RUN, Docker imajı oluşturulurken içeride bir komut çalıştırır. Yani imajın içinde terminal komutu çalıştırmak için kullanılır. (paket yükleme, klasör oluşturma, bağımlılık yükleme vb.)
COPY
ADD -> Yani bilgisayarındaki bir dosyayı → Docker imajının içine koyar. İmajın içine dosya koyma komutudur (ekstra özellikleri vardır).
CMD -> imagı oluşturduktan sonra RUN ederken komutları çalıştırır. Container çalıştığında otomatik olarak başlayacak komut.
ENTRYPOINT
WORKDIR
EXPOSE
ENV
VOLUME
ARG
LABEL
USER
```

### ✔ ENTRYPOINT vs CMD örneği:

```dockerfile
ENTRYPOINT ["python"]
CMD ["app.py"]
```
