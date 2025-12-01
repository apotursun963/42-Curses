
# 42 Docs kullanmaya çalış


# FDF Nedir ?

# ✅ **FDF Projesi**

FDF, 42 okulunun grafik kütüphanesi olan **MiniLibX (mlx)** ile yaptığın **3D bir harita (yükseklik haritası)** gösterme projesidir.

Amaç:
**Bir .fdf dosyasındaki sayıların (x, y, z) nokta koordinatlarına karşılık geldiği bir 3D araziyi, isometrik projeksiyon ile ekranda tel kafes (wireframe) şeklinde çizmek.**

---

# 🧩 **1. Girdi Dosyası (.fdf) Nedir?**

Örnek:

```
0 0 0 0 0
0 0 10 10 0
0 0 10 10 0
0 0 0 0 0
```

Bu bir **yükseklik haritasıdır**.

* yatay index → **x**
* dikey index → **y**
* sayı → **z (yükseklik)**

Yani dosyadaki her sayı bir (x, y, z) noktasını temsil eder.

---

# 🎨 **2. Program Ne Yapacak?**

Programın şunları yapacak:

### ✔️ Dosyayı okuyacak

→ get_next_line() ve ft_split() kullanarak tüm sayıları okursun.
→ Her satır bir y koordinatıdır.
→ Her sayı bir z değeridir.

### ✔️ Noktaları bellekte saklayacak

Bir 2D array gibi:

```c
map[y][x] = z;
```

### ✔️ Her noktayı isometrik projeksiyonla 2D ekrana dönüştürecek

Isometrik formül genelde şudur:

```
x_iso = (x - y) * cos(30°)
y_iso = (x + y) * sin(30°) - z
```

Yani 3D noktaları 2D ekrana çevirirsin.

### ✔️ Komşu noktaları çizgi ile bağlayacak (wireframe)

Her nokta:

* sağındaki ile çizgi çizer
* aşağısındaki ile çizgi çizer

Böylece tel kafes ortaya çıkar.

---

# 🔑 **4. Mandatory (Zorunlu) Gereksinimler**

* C ile yazılacak
* Norm kurallarına uyacak
* Global değişken YASAK
* MLX kullanmak zorunlu
* ESC → program kapanmalı
* Çaprazdaki X tuşu → kapanmalı
* Pencere davranışı sorunsuz olmalı
* Bellek sızıntısı olmayacak
* Çıktı tamamen isometrik bir harita olacak



###########

Kısacası: **Evet, elindeki `.fdf` dosyasında verilen 2D haritayı, ekranda 3D bir *wireframe* (iskelet) görünümü olarak göstermen gerekiyor.**

Ama detay şöyle:

## ✔️ Ne yapıyorsun?

* `.fdf` dosyasındaki her sayı **bir yükseklik (z değeri)**.
* Dosyadaki satırlar **y eksenini**, satır içindeki sütunlar **x eksenini** temsil ediyor.
* Sen bu 2D matrisi okuyorsun → her (x, y) noktasına z yüksekliğini ekliyorsun → bu **3D noktalar kümesi** oluyor.
* Sonra bu 3D noktaları **isometric projection** ile 2D ekrana dönüştürüyorsun.
* Çıkan noktaları **çizgilerle bağlıyorsun**, böylece bir 3D dağ–vadi haritası gibi görünüyor.

Yani aslında gerçek 3D çizim yok; matematikle 3D’yi 2D ekrana *yansıtıyorsun*.

---

## ✔️ Bir örnekle açıklayalım

Dosya şöyle olsun:

```
0 0 0
0 10 0
0 0 0
```

Bu 3×3 grid.

Ortadaki nokta 10 yüksekliğinde → bir tepecik.

Bunu ekrana şöyle çiziyorsun:

* Tüm noktaları isometrik projeksiyon formülüyle 2D’ye çeviriyorsun:

  ```
  x2d = (x - y) * cos(30°)
  y2d = (x + y) * sin(30°) - z
  ```

* Sonra sağa ve aşağıya olan komşularına çizgiler çiziyorsun.

Sonuç: **tel kafesli bir 3D görüntü**.

---

## ✔️ Sonuç olarak:
**Evet, 2D yükseklik haritasını 3D model gibi göstermen gerekiyor, ama çizim aslında 2D ekranda yapılıyor. 3D görünüm matematikle oluşturuluyor.**


###########
# ✅ **Mandatory kısmında istenen özellikler (sadece maddeler)**

1. **Map dosyasını (.fdf) okuyup parse etmek.**
2. **Her noktanın (x, y, z) koordinatını oluşturmak.**
3. **Bu noktaları isometric projection ile 2D ekrana dönüştürmek.**
4. **Noktalar arasında çizgi çizmek (wireframe).**
5. **Sağa ve aşağıya komşu noktalarla doğru çizmek.**
6. **MiniLibX ile bir pencere açmak.**
7. **Map’i pencerede görüntülemek.**
8. **Pencereyi ESC ile kapatabilmek.**
9. **Pencereyi çarpı (X) tuşuyla kapatabilmek.**
10. **Bellek sızıntısı olmamalı.**
