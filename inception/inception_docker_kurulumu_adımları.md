
# Sanal Makineye Terminal üzerinden Docker Kurlumu

---

## 1️⃣ Sistemi Güncelle

Önce paket listesini güncelleyelim:

```bash
sudo apt update
sudo apt upgrade -y
```

---

## 2️⃣ Gerekli Paketleri Kur

Docker’ın resmi deposunu eklemek için gerekli araçlar:

```bash
sudo apt install -y ca-certificates curl gnupg lsb-release
```

---

## 3️⃣ Docker’ın Resmi GPG Anahtarını Ekle

```bash
sudo mkdir -p /etc/apt/keyrings
curl -fsSL https://download.docker.com/linux/debian/gpg | sudo gpg --dearmor -o /etc/apt/keyrings/docker.gpg
```

Yetkileri ayarla:

```bash
sudo chmod a+r /etc/apt/keyrings/docker.gpg
```

---

## 4️⃣ Docker Repository (Depo) Ekle

```bash
echo \
"deb [arch=$(dpkg --print-architecture) signed-by=/etc/apt/keyrings/docker.gpg] \
https://download.docker.com/linux/debian \
$(lsb_release -cs) stable" | \
sudo tee /etc/apt/sources.list.d/docker.list > /dev/null
```

---

## 5️⃣ Docker’ı Kur

```bash
sudo apt update
sudo apt install -y docker-ce docker-ce-cli containerd.io docker-buildx-plugin docker-compose-plugin
```

---

## 6️⃣ Docker Çalışıyor mu Kontrol Et

```bash
sudo systemctl status docker
```

Çalışıyorsa `active (running)` görmelisin.

---

## 7️⃣ Test: Hello World Container

```bash
sudo docker run hello-world
```

Eğer **“Hello from Docker!”** mesajını görüyorsan her şey tamam ✅

---

## 8️⃣ (Önerilen) Docker’ı sudo’suz Kullanmak

Her seferinde `sudo` yazmak istemiyorsan:

```bash
sudo usermod -aG docker $USER
```

Sonra **oturumu kapatıp tekrar aç** veya:

```bash
newgrp docker
```

Test:

```bash
docker ps
```

---

## 9️⃣ Docker Compose Kontrolü

Artık Compose ayrı bir plugin:

```bash
docker compose version
```


Docker kurarken yaptığımız şey şu:
    - Sistemi güncelledik
    - Docker’ın resmi kaynağını sisteme tanıttık
    - Güvenlik için imza (GPG key) ekledik
    - Docker paketlerini kurduk
    - Docker servisinin çalıştığını test ettik
    - Yetki problemlerini çözdük