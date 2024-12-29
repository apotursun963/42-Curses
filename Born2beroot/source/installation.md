#  VirtualBox'ta Debian Kurulumu

## VirtualBox'ta Sanal Makine Oluşturma

1. **VirtualBox**'ı açın ve **Yeni** butonuna tıklayın.
2. Aşağıdaki bilgileri girerek sanal makinenizi oluşturun:
   - **Name**: `Born2beRoot`
   - **Machine Folder**: `/sgoinfre/goinfre/Perso/your_login`
   - **Type**: `Linux`
   - **Version**: `Debian (64-bit)`
   - **Memory Size**: `1024 MB`
   - **Hard Disk Size**: `31.00 GB`
3. Ayarları kontrol ettikten sonra **Finish** butonuna tıklayın.

## Debian Kurulumu
1. ISO Bağlayın: Debian ISO dosyasını sanal makineye bağlayın ve kurulumu başlatın.
3. Kurulum Seçimi: Debian başladığında `install` seçeneğine tıklayın.
4. Dil ve Bölge Ayarları: Dil, Coğrafi konum ve Kalvye düzenini seçin.
5. Hostname: `your_login42` olarak belirleyin.
6. Domain: Domain adını boş bırakın.
7. Şifre Belirleyin: Güçlü bir root şifresi oluşturun.
8. Kullanıcı Oluşturun: Yeni bir kullanıcı oluşturun ve güçlü bir şifre belirleyin.

## Disk Bölümlendirilmesi
Disk bölümlendirilmesi, bir sabit disk veya SSD gibi bir depolama aygıtının, birden fazla bağımsız bölüme (partition) ayrılması işlemidir. Bu bölümler, depolama cihazının farklı alanlarını ayrı ayrı kullanmayı sağlar ve her biri işletim sistemi tarafından ayrı bir disk gibi algılanır.

### Disk Bölümlendirme Türleri
   - Birincil Bölüm (Primary Partition):
     - Doğrudan disk üzerinde oluşturulan bağımsız bir bölümdür. İşletim sistemleri genellikle buradan önyüklenir. Bu bölüm, bilgisayarın açılışında önyükleme yapabilmesi için gereklidir ve diskin ana bölümleri olarak kullanılır. Birincil bölümler, diskteki verilerin en temel ve kritik yönetimini sağlar.
   - Mantıksal Bölüm (Logical Partition):
     - Bir diskte sınırsız sayıda mantıksal bölüm oluşturulabilir. Bu, kullanıcıların verilerini daha verimli yönetmelerini sağlar. Mantıksal bölümler, genellikle müzik, film, yazılım gibi dosyaların depolanması için kullanılır ve birincil bölümlere göre daha az kritik verilere ev sahipliği yaparlar.

### Adımlar:
1. **Manual Bölümleme Seçeneğini Seçin**
2. **Harddisk Seçin** - `SCSI13 (0,0,0) (sda)`
3. **Yes** Seçeneğini Tıklayın

### Oluşturulacak İki Bölüm:

#### **Şifrelenmemiş /boot Bölümü**
**Adımlar:**
- `pri/log xxGB FREE SPACE` > `Create a new partition`
- Boyut olarak **500MB** belirleyin.
- Tip olarak **Primary** seçin.
- Başlangıç (Beginning) olarak seçin.
- **Mount point** olarak `/boot` seçin.
- `Done` butonuna tıklayın.

#### **Şifrelenmiş Mantıksal Hacim (Encrypted Logical Volumes) Bölümü**
**Adımlar:**
- `pri/log xxGB FREE SPACE` > `Create a new partition`
- Boyut olarak **max** belirleyin.
- Tip olarak **Logical** seçin.
- **Mount point** olarak `Don't mount it` seçin.
- `Done` butonuna tıklayın.

## Disk Şifreleme

Disk şifreleme, bir diskteki tüm verilerin şifrelenmesi işlemidir. Bu sayede, diskteki verilere sadece yetkili `root` kullanıcılar erişebilir. Şifreleme, diski okuma girişiminde bulunan kişilerden verilerin korunmasını sağlar.

### Adımlar:
1. `Configure encrypted volumes` seçeneğini tıklayın.
2. **Yes** seçeneğini tıklayın.
3. `Create encrypted volumes` seçeneğini seçin.
4. `/dev/sda5` bölümünü seçin.
5. `Done` > `Finish` > `Yes` butonlarına tıklayın.
6. Disk şifrelemesi için bir şifre belirleyin.

# Mantıksal Hacim Yöneticisi (LVM) Kurulumu

Mantıksal Hacim Yöneticisi (LVM), disk bölümlerini daha esnek bir şekilde yönetmeyi sağlayan bir araçtır. LVM, fiziksel diskleri mantıksal hacimlere (sanal depolama) ayırarak, disk alanını daha verimli kullanmanıza, genişletmenize ve yönetmenize imkan tanır. Ayrıca, hacimleri kolayca birleştirebilir veya ayırabilirsiniz, böylece depolama kapasitesini daha esnek bir şekilde yönetebilirsiniz.

## Hacimler (Volumes) Grubu Oluşturma

1. **Configure the logical volume manager**: `Yes`
2. **Create volume group**: `LVMGroup` > `/dev/mapper/sda5_crypt`

## Mantıksal Hacimler (Logical Volumes) Oluşturma

Aşağıdaki mantıksal hacimleri oluşturun:

- **Create logical volume**: `LVMGroup` > `root` > `xxGB`
- **Create logical volume**: `LVMGroup` > `tmp` > `xxGB`
- **Create logical volume**: `LVMGroup` > `srv` > `xxGB`
- **Create logical volume**: `LVMGroup` > `home` > `xxGB`
- **Create logical volume**: `LVMGroup` > `swap` > `xxGB`
- **Create logical volume**: `LVMGroup` > `var` > `xxGB`
- **Create logical volume**: `LVMGroup` > `var-log` > `xxGB`

İşleminiz tamamlandığında **Display configuration details**'i tıklayın ve **Finish**'i seçin.

## Dosya Sistemlerini ve Bağlama Noktalarını Ayarlama

Her mantıksal birim için dosya sistemlerini ve bağlama noktalarını aşağıdaki gibi ayarlayın:

- **LV root**: `1 xxGB` > **Use as**: `Ext4` > **Mount point**: `/` > `Done`
- **LV tmp**: `1 xxGB` > **Use as**: `Ext4` > **Mount point**: `/tmp` > `Done`
- **LV srv**: `1 xxGB` > **Use as**: `Ext4` > **Mount point**: `/srv` > `Done`
- **LV home**: `1 xxGB` > **Use as**: `Ext4` > **Mount point**: `/home` > `Done`
- **LV swap**: `1 xxGB` > **Use as**: `swap area` > `Done`
- **LV var**: `1 xxGB` > **Use as**: `Ext4` > **Mount point**: `/var` > `Done`
- **LV var-log**: `1 xxGB` > **Use as**: `Ext4` > **Mount point** > **Enter manually**: `/var/log` > `Done`

## Bölümlendirmeyi Bitirip Değişiklikleri Yazma

- **Finish partitioning and write changes to disk** seçeneğine tıklayın.
- **Yes** butonuna tıklayarak işlemi onaylayın.


## Debian Kurulumu Bitirin

### 1. Tarama Ayarları
- **Tarama (`scan`)** yapma: **No**

### 2. Ülke ve Mirror Seçimi
- **Ülke (`country`)** seçin.
- **Archive mirror** (Arşiv aynası) seçin.

### 3. Proxy Ayarları
- **HTTP proxy** alanını **boş bırakın**.
- **Continue** butonuna tıklayın.

### 4. Yazılım Seçimi
- **No**, study'ye katılmanıza gerek yok.
- Tüm yazılımları **uncheck** (işaretini kaldırın).

### 5. GRUB Kurulumu
- **Yes**, GRUB'ı **/dev/sda** üzerine kurun.
- **Continue** butonuna tıklayın.

### 6. Kurulum Tamamlandı
- Kurulum tamamlandı! Sanal makine şimdi yeniden başlatılacak.
- Şifreyi girin ve oluşturduğunuz kullanıcıyla giriş yapın.

### 7. Kurulumun Doğruluğunu Kontrol Etme
Kurulumu doğru şekilde tamamlayıp tamamlamadığınızı kontrol etmek için aşağıdaki komutları çalıştırabilirsiniz:
   - Sistemdeki disk ve bölümleri görüntülemek için:
      ```bash
      lsblk
      ```
   - İşletim sistemi sürümünü kontrol etmek için:
      ```bash
      cat /etc/os-release
      ```
   - Disklerin bağlı olup olmadığını kontrol etmek için:
      ```bash
      df -h
      ```
   - Oluşturduğunuz kullanıcının doğru şekilde eklenip eklenmediğini görmek için
      ```bash
      whoami || who || w
      ```
