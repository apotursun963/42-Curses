
**Wireframe model**, bir 3D nesneyi veya haritayı **sadece çizgiler ve noktalar kullanarak** gösterme tekniğidir.
Yani yüzeyler, dokular, gölgeler yoktur → sadece iskelet görünümü vardır.

Kısacası:
👉 **3D yapının tel kafes hali**
👉 FDF’nin ekranda çizdiği model tam olarak budur.

---

# 🔍 **Daha net anlatım**

Bir 3D şekli düşün: dağ, tepe, küp, arazi…
Bu şeklin:

* köşeleri (noktaları)
* bu köşeleri birleştiren kenarları (çizgiler)

ile çizildiğini hayal et.
İşte bu görünüm **wireframe** modelidir.

Her nokta sadece çizgilerle bağlanır → tıpkı telden yapılmış bir maket gibi.

---

# 🏔️ **FDF’de wireframe ne anlama geliyor?**

FDF projesinde:

* `.fdf` dosyasındaki her sayı bir **yükseklik (z)** değeridir.
* Bu değerlerden bir **3D grid** oluşturursun.
* Bu grid içindeki noktaları:

  * sağdaki komşuya,
  * alttaki komşuya
    **çizgiyle bağlarsın.**

Böylece dağlık arazi gibi görünen bir **3D tel kafes harita** oluşur.

Yani FDF’nin ekrana çizdirdiği görüntü → **wireframe (tel kafes)**.

---

# 🎨 Özet:

**Wireframe = yüzeysiz, doldurmasız, sadece çizgilerden oluşan 3D görünüm.**
