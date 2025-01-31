## Sistem yönetimi (system administration) Nedir ?
-------------------------------------------------
Sistem yönetimi, bilgisayar sistemlerinin, ağların ve sunucuların yönetilmesi, 
bakımının yapılması ve güvenliğinin sağlanması sürecidir. 
Sistem yöneticileri, altyapının sorunsuz çalışmasını sağlamak için donanım, 
yazılım ve güvenlik önlemleriyle ilgilenir.

### Sistem Yönetimi Kavramlarından Bazıları:
  - **Kullanıcı hesapları yönetimi**:
    - Kullanıcı hesapları yönetimi, bir bilgisayar sisteminde her birey için `kimlik` oluşturulması ve bu kimliğin kontrol edilmesidir. Sistem yöneticileri, her kullanıcıya özgü hesaplar oluşturur ve her hesabın erişim haklarını belirler. Bu haklar, kullanıcıların hangi kaynaklara erişebileceğini ve hangi işlemleri gerçekleştirebileceğini düzenler. Örneğin, bazı kullanıcılar yalnızca okuma iznine sahipken, diğerleri yazma ve düzenleme izni alabilir. Bu, güvenliği sağlamak ve kullanıcıların sadece yetkilendirildikleri verilere erişmesini temin etmek için oldukça önemlidir.

  - **Şifreleme politikaları**:
    - Şifre politikaları, kullanıcıların güçlü ve güvenli şifreler oluşturmasını sağlamak amacıyla belirlenen kurallardır. Bu kurallar, şifrelerin **minimum uzunluğu**, **karmaşıklığı (büyük/küçük harf, rakam, özel karakter kullanımı)** ve **geçerlilik süresi** gibi unsurları içerir. Güçlü şifreler, siber saldırılara karşı bir savunma hattı oluşturur ve kullanıcı hesaplarının kötüye kullanımını engeller. Ayrıca, şifrelerin periyodik olarak değiştirilmesi veya eski şifrelerin kullanılmaması gibi güvenlik önlemleri de şifre politikalarının bir parçasıdır.

  - **Güvenlik duvarı (firewall) yönetimi**:
    - Güvenlik duvarı yönetimi, ağdaki trafiği izleyerek ve denetleyerek zararlı erişimlerin engellenmesini, yetkilendirilmiş trafiğin ise geçmesini sağlamayı amaçlar. Güvenlik duvarları, **iç ağ** ile **dış ağ** arasındaki iletişimi kontrol eder ve bu iletişimi belirli kurallara göre filtreler. Örneğin, yalnızca belirli `IP` adreslerinden gelen bağlantılara izin verilebilir veya yalnızca belirli `portlar` üzerinden veri alışverişine müsaade edilebilir. Bu sayede, kötü niyetli yazılımlar ve saldırılar ağın içine girmeden engellenmiş olur.

  - **Servis yönetimi**:
    - Servis yönetimi, sunucularda çalışan yazılımların izlenmesi, başlatılması, durdurulması ve güncellenmesi süreçlerini içerir. Sunucularda birçok farklı hizmet çalışır: web sunucuları, veritabanı sunucuları, e-posta sunucuları gibi. Bu hizmetlerin düzgün çalışması, sistemin genel performansı ve erişilebilirliği için kritik öneme sahiptir. 
Sistem yöneticileri, bu servislerin aktif olup olmadığını izler, gerektiğinde yeniden başlatır veya durdurur, ayrıca güvenlik güncellemelerini ve yazılım sürümlerini takip ederek günceller. Bu yönetim, hizmetlerin kesintisiz çalışmasını sağlamak için hayati bir rol oynar.


## Sanallaştırma (Virtualization) Nedir ?
--------------------------------------
**Sanallaştırma**, bir fiziksel bilgisayar üzerinde birden fazla sanal makine çalıştırma teknolojisidir. Bu teknoloji, donanım kaynaklarını (işlemci, bellek, depolama vb.) birden fazla bağımsız ortamda, yani sanal makinelerde izole bir şekilde kullanmaya olanak tanır. Her sanal makine, kendi işletim sistemine ve uygulamalarına sahip olup, fiziksel makineden bağımsız gibi çalışabilir.

## **Nasıl Çalışır**:
Sanallaştırma, bir hipervizör (sanallaştırma yöneticisi) aracılığıyla gerçekleştirilir. 
Hipervizör, fiziksel donanım ile sanal makineler arasındaki kaynakları yönetir ve her sanal makineyi izole eder.
  - **Tip 1 Hipervizör (bare-metal)**:
    - Doğrudan donanım üzerinde çalışır. Genellikle veri merkezlerinde kullanılır. Örnekler: VMware ESXi, Microsoft Hyper-V.
- **Tip 2 Hipervizör (hosted**):
    - Bir işletim sistemi üzerinde çalışır ve kullanıcı bilgisayarlarında daha yaygın olarak kullanılır. Örnekler: VirtualBox, VMware Workstation.
Hipervizör, sanal makinelerin işlemci, bellek ve depolama gibi kaynakları verimli bir şekilde kullanmasını sağlar.
Her sanal makine, kendi işletim sistemine sahip olup bağımsız olarak çalışır.


## ISO Dosyası Nedir ?
---------------------
ISO dosyası, bir **diskin dijital kopyasını** içerir. İçerisinde işletim sisteminin dosyaları, kurulum verileri, sistem dosyaları ve genellikle önyükleme için gerekli dosyalar bulunur. Bu, bir `CD`, `DVD` (Veri Depolama)  veya `USB`'ye yazılarak fiziksel bir diske benzer şekilde kullanılabilir.


## Hostname (ağ adı) Nedir ?
----------------------------
Bir cihazın ağ üzerinde tanımlanan benzersiz adıdır. Genellikle bir bilgisayar, sunucu veya diğer ağ cihazları, birbirlerini tanımak ve iletişim kurmak için host adlarını kullanır. Hostname, cihazın ağdaki kimliğini belirler ve genellikle bir ağda hangi cihazların bulunduğunu belirlemek için kullanılır.

## Kullanıcı Türleri
--------------------
- **Root Kullanıcı**:
Bir bilgisayar sistemindeki en yüksek yetkiye sahip kullanıcıdır. Bu kullanıcı, sistemdeki tüm dosyalara ve kaynaklara erişim sağlar, diğer kullanıcıları yönetebilir ve sistemin yapılandırmasını değiştirebilir.

- **Normal Kullanıcı**:
Kendi dosyalarına ve belirli kaynaklara erişebilir, ancak sistem dosyalarına veya diğer kullanıcıların verilerine erişemez. root'a göre sınırlı yetkiye sahiptir.


## **Linux klasör yapıları ve işlevleri:**
-------------------------------------------
- `/root`:
  - Sistemin kök dizini olarak kabul edilir ve burada sistemin temel dosyaları, yardımcı programlar, ana dizinler, ve kullanıcılar için yerler bulunur.
- `/bin`:
  - Temel sistem komut dosyaları ve yardımcı programlar içerir. Bu komutlar, sistem açıldığında ve sorun durumlarında kullanılmak üzere dizayn edilmiştir. İçerisinde bulunan komutlar, sistemin herhangi bir durumda çalışmasını sağlar. Sistem başlatıldığında, bunlar direkt olarak kullanılabilir olmalıdır. Örneğin, ls (dosya listesi), cp (dosya kopyalama), mv (dosya taşıma) gibi komutlar bu dizindedir.
- `/home`:
  - Her kullanıcı için kişisel dosyaların ve ev dizinlerinin saklandığı yerdir. Her bir kullanıcı için ayrı bir dizin oluşturulur, örneğin **/home/username**. Kullanıcıların kendi belgeleri, müzikleri, belgeleri ve diğer kişisel verileri burada saklanır.
- `/etc`:
  - Sistem yapılandırma dosyaları içerir. Bu dizin, sistemin nasıl çalışacağına dair ayar dosyalarını barındırır. Konfigürasyon dosyaları (/etc/passwd, /etc/fstab, /etc/hostname gibi) bu dizinde bulunur. Bu dosyalar, sistemin temel yapı taşlarını tanımlar ve sistemdeki kullanıcılar, ayarlar, ağ yapılandırmaları gibi önemli bilgileri içerir.
- `/var`:
  - Değişken veriler ve log dosyaları içerir. Bu dizin, sistemin çalışma sırasında oluşan loglar, önbellek dosyaları, veri tabanları ve dökümanlar gibi dinamik verilerin saklandığı yerdir. 
- `/usr`:
  - Kullanıcı programları ve kütüphaneler. Kullanıcı tarafından erişilen ve kullanılan programlar, yardımcı uygulamalar ve kütüphaneler bu dizinde bulunur. İçerisinde bin, lib, ve share gibi alt dizinler bulunur. Örneğin, ofis yazılımları, grafik araçları, metin editörleri gibi programlar bu dizindedir. Bu dizin, kullanıcı uygulamaları ve yazılımları için ana yerdir.
- `/tmp`:
  - Kullanıcıların ve programların geçici olarak dosyalarını saklamak için kullanılan bir dizindir. Bu dizin zamanla temizlenir ve tüm dosyalar kaybolur. Geçici dosyalar genellikle hızlıca silinmesi gereken veriler için kullanılır. Örneğin, geçici yüklemeler, tarayıcı önbellekleri, veya bir programa özgü veriler burada tutulur.
- `/boot`:
  - Bu dizin, bilgisayarın başlangıç işlemi sırasında gerekli olan dosyaların bulunduğu yerdir. /boot dizini, genellikle sistemin başlatılması için gerekli olan dosyaları içerir ve bu dosyaların bir kısmı yalnızca başlangıç sırasında kullanılmak üzere tasarlanmıştır.


## **Disk (HDD/SSD)**
--------------------
Bir depolama aygıtıdır ve veriler **kalıcı** olarak saklanır, yani bilgisayar kapalı olsa bile veriler kaybolmaz. **Diskler**, genellikle büyük kapasitelere sahip olup, uzun vadeli **veri depolama** için kullanılır. Diskler, işletim sistemi, uygulamalar, kişisel dosyalar ve veritabanları gibi kalıcı verilerin depolanması için kullanılır.


## **Bellek (Ram)**
--------------------
Bir geçici depolama aygıtıdır. Bilgisayar açık olduğu sürece, çalışan programlar, veriler ve işlemci tarafından kullanılan veriler burada tutulur. RAM, **geçici** olarak veri saklar ve bilgisayar kapatıldığında veriler kaybolur. Genellikle daha küçük kapasitelere sahiptir. RAM, programların hızlı çalışmasını sağlar çünkü işlemciye hızlı veri erişimi sunar.


## **İşlemci (CPU)**
--------------------
Bilgisayarın **beyni** olarak düşünülebilir. Bilgisayarın tüm hesaplama ve işlem gücünü sağlayan temel bileşendir. CPU, **komutları işler**, **verileri hesaplar** ve **uygulamaları çalıştırır**. 
- **İşlemci**: Bilgisayarın çalışması için gerekli tüm işlemleri yapar.
- **Hız**: Verileri çok hızlı işleyebilme yeteneğine sahiptir, bu sayede bilgisayarın genel performansını belirler.
- **Çekirdek**: Modern CPU'lar birden fazla çekirdeğe sahip olabilir, her çekirdek bağımsız bir işlem yapabilir, bu da çoklu görevleri daha verimli hale getirir.
**Fiziksel CPU**: Bilgisayarın içinde bulunan gerçek işlemci donanımıdır. Tüm hesaplama ve veri işleme işlemlerini yapar.
**Sanal CPU**: Fiziksel CPU'nun sanal ortamda oluşturulmuş bir yansımasıdır. Genellikle sanal makinelerde (VM) kullanılır ve fiziksel CPU'nun kaynaklarını paylaşarak işlem yapar, yani fiziksel CPU gerçek donanım iken, sanal CPU sanal makinelerde fiziksel CPU'nun kaynaklarını kullanan sanal bir işlemciyi ifade eder.
CPU, bilgisayarın tüm işlemlerini yöneten ve çalıştıran en önemli parçadır. Programlar çalışırken, veriler üzerinde hesaplamalar yapar ve bilgisayarın düzgün çalışmasını sağlar.


## Bir Sanal Makine Nedir, Nasıl Çalışır ve Amacı Nedir?
---------------------------------------------------------
### **Bir Sanal Makine Nedir ve Neden Kullanırız:**
Bir sanal makine, fiziksel bir makineyi taklit ederek canlandırmayı yardımcı olan bir yazılımdır. Yani bilgisayarın için kurduğumuz bir bilgisayardır.
Neden kullanırız? Mesela yeni bir işletim sistemi denemek istiyorsak, ya da şüphelendiğimiz bir dosya vardır, onu sanal makinede açıp deneriz ve sisteme vereceği zararları aslında sanal makineye vermiş olur ve ana bilgisayarı hiç bir şekilde etkilemez.

### **Bir Sanal Makine Nasıl Çalışır?**
Sanal makineler, hypervisor adı verilen bir yazılım katmanı aracılığıyla çalışır. Hypervisor, ana bilgisayarın donanımını sanal makinelere dağıtarak her birinin bağımsız ve izole şekilde çalışmasını sağlar:
  - **Bare-metal Hypervisor**: Doğrudan donanım üzerinde çalışır (ör. VMware ESXi).
  - **Hosted Hypervisor**: Bir işletim sistemi üzerine kurulur (ör. VirtualBox).
Hypervisor, donanımı sanallaştırarak sanal makinelerin fiziksel donanımı paylaşmasını ve verimli kullanılmasını sağlar.

## **Bir Sanal Makinenin Amacı Nedir?**
Kaynakların Daha Etkin Kullanımı:
Bir fiziksel sunucunun (örneğin, güçlü bir bilgisayarın) işlemci gücü, bellek kapasitesi ve depolama alanı gibi kaynakları genelde tam kapasite kullanılmaz. Sanal makineler, bu kaynakları bölerek birden fazla görev için kullanılabilir hale getirir.
Sonuç: Tek bir fiziksel sunucunun kaynaklarını verimli bir şekilde birden fazla göreve bölersiniz. Böylece, hem maliyet düşer hem de verim artar.

## **Cron Nedir ?**
-------------------
Linux ve Unix tabanlı sistemlerde belirli görevlerin otomatik olarak belirlenen zamanlarda çalıştırılmasını sağlayan bir sistem aracıdır.

### **Crontab Dosyası:**
`crontab` komutu, kullanıcıların kendi görevlerini tanımlayabileceği bir sistem sunar. `crontab -e` komutu, mevcut crontab dosyasını düzenlemek için kullanılır.
Bir crontab dosyası, beş alanlık bir ifade ile belirtilen zamanlama ve komut içeriğini içerir:

- **Dakika (0-59)**
- **Saat (0-23)**
- **Gün (1-31)**
- **Ay (1-12)**
- **Gün (0-6, 0=Pazar)**

Örnek:
`0 2 * * * /usr/bin/backup_script.sh`
Bu, her gün saat 02:00'de `backup_script.sh` adlı komutun çalıştırılacağını belirtir.
