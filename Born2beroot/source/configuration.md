# Sistem Yönetimi ve Güvenlik Kurulumları

Bu doküman, **Linux** sistemlerinde Sudo, UFW, SSH ve Şifreleme Politikarları gibi temel **Sistem Yönetimi** ve **Güvenlik Yapılandırmaları** ele alır.

## Sudo Kurulumu
**sudo (super user do),** bir komutu geçici olarak başka bir kullanıcı (genelde root) yetkileriyle çalıştırmanızı sağlar.
Kendi kullanıcı şifrenizi kullanarak işlem yapabilirsiniz. **root** şifresine ihtiyaç duyulmaz.

### Sudo Kurma
**su (swicth user),** bir kullanıcıdan başka bir kullanıcıya (genelde root) geçiş yapmayı sağlayan bir komuttur.
Kullanıcının şifresini (root şifresini) girmenizi gerektirir.
Öncelikle `root` kullanıcısına geçmek için aşağıdaki komutu kullanın.
```
su root
```

### Sudo'yu Yükleyin
**apt** ve **aptitude**, sistemde yazılımların kurulumu, kaldırılması ve güncellenmesi gibi işlemleri gerçekleştirmek için kullanılır.
apt, sadece komut satırı ile çalışırken aptitude hem komut satırı hem de metin tabanlı kullanıcı arayüzü (TUI) sunar. apt basit bağımlılık çözümü sağlarken, aptitude karmaşık bağımlılık sorunlarını daha esnek şekilde yönetir ve alternatif çözüm önerileri sunar.
Sistem paketini güncelleyin ve sudo paketini yükleyin.
```
apt update && apt upgrade && apt install sudo
```

### Sudo'nun yüklenip yüklenmediğini kontrol etme
dpkg, Debian tabanlı sistemlerde .deb paketlerini yüklemek, silmek ve bilgi almak için kullanılan düşük seviyeli bir araçtır. Bağımlılıkları otomatik olarak yönetmez. Bunun yerine, apt gibi yüksek seviyeli araçlar, paketlerin bağımlılıklarını çözer ve paketleri internetten indirir.
```
dpkg -l sudo
```

### Yeni kullanıcı ekleme
```
sudo useradd -m <kullanıcı_adı>
sudo passwd <kullanıcı_adı>
```

### Kullanıcıyı silme
Bu komut kullanıcyı ve onun tüm ev dizinini ve dosyalarını siler.
```
sudo userdel -r <kullanıcı_adı>
```

### Kullanıcının ID'sini gösterme
```
id -u <kullanıcı_adı>
```

### Kullanıcının şifresini değiştirme
```
sudo passwd <kullanıcı_adı>
```

### Sistemde oturum açmış tüm kullanıcıları listeleme
```
users || sudo getent passwd || cat /etc/passwd
```

### Yeni bir grup oluşturma
```
sudo groupadd <grup_adı>
```

### Bir kullanıcyı gruba eklemek
```
sudo usermod -aG <grup_adı> <kullanıcı_adı> 
```

### Bir kullanıcyı gruba'tan silme
```
sudo usermod -rG <grup_adı> <kullanıcı_adı>
```

### Bir grubu silme
```
sudo groupdel <grup_adı>
```

### Bir kullanıcının üye olduğu tüm grupları listeleme
```
groups <kullanıcı_adı>
```

### Kullanıcın ana grup kimliğini öğrenmek
```
id -g <kullanıcı_adı>
```

### Var olan bütün grupları listeleme
```
sudo getent group || cat /etc/group
```

### Bir gruptaki tüm kullanıcıları listelemek
```
sudo getent group <grup_adı>
```

### Sudoers dosyasında kullanıcı yetkilendirme
Bir kullanıcıya **tam yetki** vermek için, `sudoers` dosyasına şu satır eklenir:
**username ALL=(ALL:ALL) ALL**
sudoers dosyasına gitmek için:
```
sudo visudo
```

- **`username`**: `sudo` komutunu kullanarak sistem üzerinde işlem yapacak kullanıcının adı.
- **`ALL` (ilk)**: **Tüm makinelerde** bu yetkilerin geçerli olmasını sağlar. (Yani, kullanıcı herhangi bir makinada bu yetkilerle işlem yapabilir.)
- **`(ALL:ALL)`**:
  - İlk **`ALL`**: Kullanıcı, **herhangi bir kullanıcı adına** komut çalıştırabilir. Örneğin, `root` kullanıcısı adına işlem yapabilir.
  - İkinci **`ALL`**: Kullanıcı, **herhangi bir grup adına** komut çalıştırabilir.
- **`ALL` (ikinci)**: Kullanıcı, **tüm komutları** çalıştırmaya yetkilidir


### Kullanıcıyı sudo grubuna ekleme
Bir kullanıcıyı sudo grubuna eklerseniz, bu kullanıcı yönetici (root) haklarına sahip olur ve sudo komutunu kullanarak sistemde yönetici yetkileriyle işlem yapabilir.
```
sudo usermod -aG sudo <kullanıcı_adı> 
```

### Root oturumdan çıkış
root oturumdan çıkmak için:
```
exit
```


## UFW Kurulumu
UFW (Uncomplicated Firewall), `Linux` sistemlerinde kullanılan, basit bir **güvenlik duvarı** aracıdır. Temel amacı, ağ trafiğini izleyerek zararlı erişimleri engellemek ve yalnızca yetkilendirilmiş (belirtilmiş) erişimlerin geçişine izin vermektir. Bu sistem, **iç a**ğ ile **dış ağ** arasındaki iletişimi kontrol eder. Güvenlik duvarları, yalnızca belirli **IP** adreslerinden gelen bağlantılara veya belirli **portlar** üzerinden veri alışverişine izin vererek, ağdaki kötü niyetli yazılımları ve saldırıları engeller. Kullanım alanları, Sunucularda dış bağlantılara karşı güvenlik sağlamak ve Belirli IP'ler veya port'lar üzerinden trafiği sınırlamak.
  - **Dış Ağ (External Network)**: İnternet gibi, dış dünyadaki herkese açık olan geniş bir ağdır.
  - **İç Ağ (Loca Network)**: Evdeki veya iş yerindeki bilgisayarların, yazıcıların ve diğer cihazların bağlı olduğu özel ağdır. (örneğin, Wİ-Fİ ağ).
  - **IP Adresi**: Cihazların (bilgisayar, telefon, yazıcı vb.) internet veya yerel ağ üzerinde birbirleriyle iletişim kurmasını sağlayan, **benzersiz** bir sayısal kimliktir.

UFW'yi yüklemek
```
sudo apt install ufw
```

UFW'yi etkinleştirmek ve devre dışı bırakamk.
```
sudo ufw enable
sudo ufw disable
```

Port açmak, yani port üzerinden gelen giden ağ trafiğine izin vermek.
Bu, dış dünyadan (internet gibi) gelen bağlantıların iç ağa erişmesine izin vermek için kullanılır.
```
sudo ufw allow <port>
```

Port kapatmak, yani port üzerinden gelen giden ağ trafiğini engellemek/silmek.
```
sudo ufw deny <port> || sudo ufw delete allow <port> || sudo ufw delete <kural>
```

Durum kontrolü, güvenlik duvarının etkin olup olmadığını, hangi kuralların uygulandığını ve mevcut yapılandırmayı gösterir.
```
sudo ufw status || sudo ufw status verbose || sudo ufw status numbered
```

Belirli bir IP'den yalnızca HTTP trafiğine izin vermek
```
sudo ufw allow from 192.168.1.100 to any port 80
```

## SSH Kurulumu ve Yapılandırılması
**SSH (Secure Shell)**, uzak sunuculara güvenli bir şekilde bağlanmak için kullanılan bir ağ protokolüdür.
Güvenliği, verileri şifreleyerek ve kimlik doğrulama isteyerek sağlar.
  - **Protokol**, İki cihaz arasındaki veri iletişimini düzenleyen kurallar ve standartlardır. Verilerin nasıl gönderileceğini ve alınacağını belirler. örneğin, HTTP, HTTPS ve SSH gibi farklı protokoller vardır.
  - **Port (Liman),** ağdaki cihazlar arasındaki iletişimi sağlayan "kapılar"dır. Fiziksel portlar (USB, Ethernet gibi) cihazlar arasında veri iletimini sağlar. Sanal portlar ise yazılım seviyesinde, belirli hizmetler veya uygulamalar için kullanılır. Örneğin, **SSH** için **22** numaralı port kullanılır. 

### Paket Listesini Güncelleme
Öncelikle sistem paketlerini güncelleyin:
```
sudo apt update && sudo apt upgrade
```

### Openssh Server'ı Yükleme
SSH sunucusunu yüklemek için:
```
sudo apt install openssh-server
```

### SSH Hizmetinin Durmunu Kontrol Etme
SSH sunucusunun aktif olup olmadığını kontrol etme:
```
sudo systemctl status ssh
```
Eğer SSH hizmeti aktifse **active (running)** mesajını görürsünüsz.
Eğer aktif değilse SSH sunucusunu başlatmak için:
```
sudo systemctl start ssh
```

SSH hizmetini inactive yapmak.
```
sudo systemctl stop ssh
```

### SSH Sunucusunun Dinlediği Port'u Değiştirme
SSH Sunucusunun Varsayılan Olarak Dinlediği (Beklediği) Port 22'dir. Güvenliği Arttırmak İçin Bu Port'u Değiştirebiliriz.
  - SSH yapılandırma dosyasını düzenlemek için:
    ```
    sudo nano /etc/ssh/sshd_config
    ```
  - Port değerini değiştirme:
    ```
    #Port 22 >>> Port 4242
    ```
  - yapılandırmayı kaydetmek için:
    ```
    Ctrl + O | Enter | Ctrl + X
    ```

### SSH Hizmetini Yeniden Başlatma
Yapılandırma Değişiklerinin Geçerli Olması İçin SSH Hizmeti Yeniden Başlatmamız Gerekir:
```
sudo systemctl restart ssh
```

### Güvenlik Duvarı (UFW) Eklemek
Yeni Port'un Güvenlik Duvarında İzinli Olmasını Sağlamak İçin:
```
sudo ufw allow <port>
```

Güvenlik Duvarında Port İzni Kaldırmak
Eğer bir portu engellemek isterseniz:
```
sudo ufw delete allow <port>
```

### Sanal Makineye Bağlantı Kurma (VirtualBox)
Sanal makine üzerinden bağlantı kurmak için port yönlendirme yapmanız gerekir.
  - VirtualBox ayarlarını yapılandırma
    - VirtualBox sanal makinenizi seçin.
    - Ayarlar >> Ağa >> Bağadaştırıc 1 (Adapter 1) kısmına gidin.
    - Gelişmiş >> Port yönlendirme seçeneğini (Port Forwarding) seçin.
  - Port yönlendirme kuralı ekleme
    - Ad: SSH
    - Protokol: TCP
    - Ana Bilgisayar Portu (Host Port): 4242
    - Konuk Portu (Guest Port): 4242
  Değişiklikleri Kaydedin.

### SSH İle Bağalantı Kurma
SSH bağlantısını, host makinenizden (Ana Bilgisayar) kurmak için aşağıdaki komutu kullanabilirsiniz:
```
ssh <kullanıcı_adı>@localhost -p <port>
```

### Ağ yapılandırması ve IP adresi bilgilerini görüntülemek
```
ip a || hostname -I
```

### SSH Oturumundan Çıkış
SSH bağlantısını sonlandırmak için terminalde şu komutu yazın:
```
exit
```

## Şifreleme Politikaları
Şifre politikaları, şifrelerin güvenliğini sağlamak amacıyla belirlenen kurallardır. Bu kurallar genellikle şifre uzunluğu, geçerlilik süresi, değiştirme sıklığı ve kullanıcıya uyarı mesajı gönderilmesi gibi öğeleri içerir.

### Şifre Süresi ve Değiştirme Kuralları:
  - Şifre her 30 günde bir dolmalı.
    - `sudo chage -M 30 <kullanıcı_adı>`
  - Şifre değiştirildikten 2 gün sonra tekrar değiştirilebilir.
    - `sudo chage -m 2 <kullanıcı_adı>`
  - Şifre süresi dolmadan 7 gün önce uyarı verilmelidir.
    - `sudo chage -W 7 <kullanıcı_adı>`
  - Kullanıcı ayarlarını kontrol etmek için:
    - `chage -l <kullanıcı_adı>`
  - Veya `sudo nano /etc/login.defs` dosyasına giderek belirtilen adımları **manuel** olarak uygulayabilirsinisz.

### Şifre Uzunluğu ve Karakter Kuralları:
  - Şifre en az 10 karakter olmalı.
    - `minlen = 10`
  - Şifre, bir büyük harf, bir küçük harf ve bir rakam içermeli.
    - `ucredit = -1`
    - `lcredit = -1`
    - `dcredit = -1`
  - Şifre 3’ten fazla aynı karakteri içermemeli.
    - `maxrepeat = 3`
  - Şifre kullanıcının adını içermemeli.
    - `usercheck = 1`
  - Eski şifreden en az 7 farklı karakter olmalı (root hariç).
    - `difok = 7`
  - Kullanıcıya en fazla 3 kez şifre oluşturma denemesi hakkı olmalı.
    - `retry = 3`
  - Yukarda belirtilen adımlara göre `sudo nano /etc/pam.d/common-password || sudo nano /etc/security/pwquality.conf` dosyasına giderek yapılandırmaları gerçekleştirin. Ayrıca **Root şifresi** de yukarıdaki kurallara uymalıdır.

### Kullanıcı Şifresini Değiştirme
```
sudo passwd <kullanıcı_adı>
```
