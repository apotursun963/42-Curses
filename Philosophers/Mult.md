**Çoklu İşleme ve Çoklu İş Parçacığına Giriş**  

### **Çoklu İş Parçacığı (Multi-Threading) Nedir?**  
Basit bir şekilde anlatmak gerekirse, **çoklu iş parçacığı (multi-threading)**, bir programın aynı süreç (process) içinde birden fazla iş parçacığını (thread) eş zamanlı olarak çalıştırmasını sağlar. İş parçacıklarını, bir sürecin daha küçük ve bağımsız çalışabilen bileşenleri olarak düşünebilirsiniz. Bu iş parçacıkları, aynı bellek alanını paylaşarak belirli görevleri bağımsız şekilde yerine getirebilir.  

Özellikle **dosya okuma, kullanıcıdan giriş bekleme** gibi işlemler sırasında çoklu iş parçacığı oldukça faydalıdır. Örneğin, bir iş parçacığı beklerken, diğer iş parçacıkları işlem yapmaya devam edebilir.  

### **Çoklu İş Parçacığının Avantajları ve Dezavantajları**  

✅ **Avantajları:**  
- **Kaynakların Verimli Kullanımı:** İş parçacıkları, aynı bellek alanını paylaştığı için veri paylaşımı kolaydır.  
- **Düşük Bellek Kullanımı:** Her iş parçacığı için ayrı bir bellek tahsis edilmesine gerek yoktur.  
- **Hızlı Geçiş (Context Switching):** İş parçacıkları arasında geçiş yapmak, süreçler arasında geçiş yapmaya kıyasla daha hızlıdır.  

❌ **Dezavantajları:**  
- **Senkronizasyon Karmaşıklığı:** Paylaşılan kaynaklara erişimi yönetmek zordur ve yarış koşulu (race condition) gibi sorunlara yol açabilir.  
- **Python'da Küresel Yorumlayıcı Kilidi (GIL):** Python'un **Global Interpreter Lock (GIL)** yapısı, aynı anda birden fazla iş parçacığının gerçek paralel işlem yapmasını engeller.  
- **Tıkanma (Deadlock) Riski:** İş parçacıkları senkronize edilmezse, birbirlerini sonsuza kadar bekleyerek kilitlenebilirler.  

---

### **Çoklu İşlem (Multi-Processing) Nedir?**  
Çoklu işlem (multiprocessing), **birden fazla süreci aynı anda çalıştırma** tekniğidir. Her süreç (process) kendi bellek alanına sahip olduğu için birbirinden bağımsız çalışır. Bunu, aynı anda birden fazla **Python yürütücüsünün (interpreter)** çalıştırılması gibi düşünebilirsiniz.  

Bu yapı, özellikle **çok çekirdekli sistemlerde** gerçek paralel işlem yapmayı sağlar. Her süreç farklı bir işlemci çekirdeğine atanabilir, böylece hesaplama gücü maksimum seviyeye çıkartılabilir.  

### **Çoklu İşlemin Avantajları ve Dezavantajları**  

✅ **Avantajları:**  
- **Gerçek Paralellik:** Her süreç farklı bir işlemci çekirdeğinde çalışabilir.  
- **Hata Yalıtımı (Fault Isolation):** Bir süreç çökerse, diğer süreçler bundan etkilenmez.  
- **GIL’in Aşılması:** Python'da **çoklu işlem**, GIL’in sınırlamalarını aşarak paralel hesaplama yapılmasını sağlar.  

❌ **Dezavantajları:**  
- **Yüksek Bellek Kullanımı:** Her sürecin kendi bellek alanı olduğundan, bellek tüketimi iş parçacıklarına kıyasla daha fazladır.  
- **İşlemler Arası İletişim (IPC) Karmaşıklığı:** İşlemler arasında veri paylaşımı ve haberleşme, iş parçacıklarına kıyasla daha zordur.  
- **Daha Yavaş Geçiş (Context Switching):** Süreçler arasında geçiş yapmak, iş parçacıklarına göre daha fazla kaynak tüketir.  

---

### **Ne Zaman Hangisini Kullanmalıyız?**  
✅ **Çoklu İş Parçacığı (Multi-Threading) Kullanılmalı:**  
- **G/Ç ağırlıklı (I/O-bound) işlemlerde**  
- **Dosya okuma/yazma, ağ istekleri, kullanıcı giriş bekleme gibi işlemler sırasında**  
- **Bir web sunucusunun istemci isteklerini yönetmesi gerektiğinde**  

✅ **Çoklu İşlem (Multi-Processing) Kullanılmalı:**  
- **CPU ağırlıklı (CPU-bound) işlemlerde**  
- **Büyük veri işleme, makine öğrenimi model eğitimi, karmaşık matematiksel hesaplamalar gibi ağır işlem gücü gerektiren durumlarda**  
- **Birden fazla işlemci çekirdeğinin gücünden faydalanmak istendiğinde**  
