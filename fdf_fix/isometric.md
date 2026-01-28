
# İzometrik projeksiyon Nedir ?
Isometrik projeksiyon, 3 boyutlu bir nesneyi veya haritayı 2 boyutlu ekranda 3D görünüyormuş gibi göstermek için kullanılan özel bir matematiksel projeksiyon türüdür.
kısacası, 3D noktaları 2D ekrana yansıtan bir teknik
Ama bunu yaparken nesnenin üç eksenini de eşit açıyla gösterir.


# 🔍 **Daha net açıklama**

3D uzayda bir noktan var:  
**(x, y, z)**

Ekranda sadece **(x', y')** koordinatları kullanırsın.  
Isometrik projeksiyon, bu 3D noktayı 2D’ye şöyle çevirir:

## 📌 **Isometric projection formülü**
```
x2d = (x - y) * cos(30°)
y2d = (x + y) * sin(30°) - z
```

Bu sayede:
- X ekseni → sağ alt çapraz,
- Y ekseni → sol alt çapraz,
- Z ekseni → dikey yukarı

gibi görünür.

Yani 3 eksen ekranda **eşit açılarla (120°)** görünür → 3D hissi verir.


# 🎨 **FDF’de neden kullanılıyor?**

FDF projesi, yükseklik haritasını (z değerleri) kullanarak 3D dağ–vadi görüntüsünü çizer.  
Isometrik projeksiyon sayesinde:

✔️ Harita 3D görünür  
✔️ Z değerleri yukarı doğru kabarır  
✔️ 2D pencerede 3D bir “tel kafes” görüntüsü oluşur

---

# ⚙️ **Basit bir örnek**

🌍 3D nokta:  
`(2, 1, 5)`

Isometric hesap:

```
x2d = (2 - 1) * cos(30°) = 0.866
y2d = (2 + 1) * sin(30°) - 5 = -3.5
```

Ekranda bu nokta (0.86, -3.5) gibi görünür → yukarı kalkmış bir tepe gibi.

