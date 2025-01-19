Vim, güçlü ve popüler bir metin düzenleyicisidir. Temel kullanımı öğrendikten sonra hız ve esneklik sağlar. İşte Vim’i kullanmaya başlamak için temel adımlar:  

---

### **1. Vim'i Başlatma**
Terminalde bir dosya açmak için:  
```bash
vim dosya_adi
```
Dosya mevcut değilse, yeni bir dosya oluşturulur.  

---

### **2. Modlar**
Vim'in üç ana modu vardır:  
1. **Komut Modu**: Varsayılan moddur. Komutlar girilir.  
   - **Geçiş**: `ESC` tuşuna basın.
2. **Ekleme Modu**: Yazı yazmak için kullanılır.  
   - **Geçiş**: `i`, `I`, `a`, veya `A` gibi komutlarla girilir.
3. **Komut Satırı Modu**: Dosya işlemleri için kullanılır (kaydetme, çıkış vb.).  
   - **Geçiş**: `:` tuşuna basılır.

---

### **3. Temel Komutlar**

#### **Dosya Yazma ve Çıkma**
- Kaydet ve çık: `:wq` veya `ZZ`
- Sadece kaydet: `:w`
- Çık (kaydetmeden): `:q!`

#### **Hareket**
- Karakter hareketleri:  
  - Sağ: `l`, Sol: `h`, Aşağı: `j`, Yukarı: `k`
- Kelime kelime hareket:  
  - İleri: `w`, Geri: `b`
- Satır başına git: `0`  
- Satır sonuna git: `$`  

#### **Metin Ekleme**
- Mevcut konumda yaz: `i`  
- Satırın sonuna yaz: `A`  

#### **Silme**
- Karakter sil: `x`  
- Satır sil: `dd`  
- Kelime sil: `dw`

#### **Kopyalama ve Yapıştırma**
- Kopyala (yank): `yy`  
- Yapıştır: `p`  

---

### **4. Arama**
- İleri arama: `/kelime`  
- Geri arama: `?kelime`  
- Sonraki eşleşme: `n`  
- Önceki eşleşme: `N`

---

### **5. İptal ve Geri Alma**
- Geri al: `u`  
- Yeniden yap: `CTRL + R`  

---

### **6. Yardım**
Vim ile ilgili yardım almak için:  
```bash
:help
```

---

### **7. Vim'den Çıkma**
Vim’den çıkmak için:
- Kaydet ve çık: `:wq`  
- Kaydetmeden çık: `:q!`



---

Vim'i **modüler bir yapı**da ve **klasör bazlı** bir şekilde kullanmak, özellikle büyük projeler üzerinde çalışırken oldukça kullanışlıdır. İşte bu şekilde bir yapı oluşturmak ve verimli çalışmak için rehber:

---

## **1. Dosya ve Klasör Yapısını Hazırlayın**
Projeler genellikle aşağıdaki gibi bir yapıda organize edilir:

```
proje/
├── src/
│   ├── main.py
│   ├── helper.py
├── tests/
│   ├── test_main.py
│   ├── test_helper.py
├── README.md
├── requirements.txt
```

Bu tür bir yapıda Vim ile çalışırken dosyalar arasında kolayca geçiş yapmak önemlidir.

---

## **2. Vim’i Proje Klasöründe Kullanmak**
Proje klasörüne gidip Vim’i açarak tüm yapıya erişebilirsiniz:

```bash
cd proje
vim
```

Bu komut, projeyi Vim içinde açar ve klasör yapısını yönetmek için aşağıdaki yöntemleri kullanabilirsiniz.

---

## **3. Temel Dosya ve Klasör Yönetimi Komutları**

### **Dosyalar Arasında Geçiş**
- Dosya açma:  
  ```bash
  :e src/main.py
  ```
  **`:e` (edit)** komutu bir dosyayı açar.

- Dosyalar arasında geçiş:  
  - Önceki dosyaya dön: `:e#`  
  - Açık dosyaları listele: `:ls`  
  - Belirli bir dosyayı seç: `:b <dosya_numarası>`

### **Klasör Yapısını Gözlemleme**
- Klasör içeriğini listeleme:  
  ```bash
  :e .
  ```
  **`.`** mevcut dizini temsil eder. Burada dosyaları seçip açabilirsiniz.

---

## **4. Çoklu Dosya ile Çalışma**
### **Sekmeler**
Vim, sekmelerle birden fazla dosyayı aynı anda düzenlemenize olanak tanır.
- Yeni bir sekme aç ve dosya yükle:  
  ```bash
  :tabnew src/helper.py
  ```
- Sekmeler arasında geçiş:  
  - Sonraki sekme: `:tabn`  
  - Önceki sekme: `:tabp`

### **Bölünmüş Ekran**
- Dosyaları yatay olarak böl:  
  ```bash
  :split src/main.py
  ```
  **CTRL + w + w** ile pencereler arasında geçiş yapabilirsiniz.

- Dosyaları dikey olarak böl:  
  ```bash
  :vsplit src/helper.py
  ```

### **Tam Modüler Çalışma**
Bu yöntemler, projedeki dosyalara aynı anda bakmanıza olanak tanır. Örneğin:
- `src/main.py` ve `src/helper.py` yan yana düzenlenebilir.
- Test dosyaları ayrı bir sekmede açılabilir.

