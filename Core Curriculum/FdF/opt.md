

# mlx_get_data_addr():
Pikselleri bir resme yazarken, doğrudan mlx_pixel_put kullanmak yavaştır çünkü her pikseli anında pencereye gönderir. Bunun yerine, pikselleri önce bir resme (buffer) yazıp, ardından bu resmi ekrana yansıtmak daha verimlidir. MLX kütüphanesinde, resmin verilerine erişmek için **mlx_get_data_addr** fonksiyonu kullanılır. Bu fonksiyon, resmin bellek adresini almayı sağlar ve piksellerin doğru bir şekilde yazılabilmesi için gerekli bilgileri (bpp, line_length, endian) sağlar. Piksellerin doğru bellek adresine yazılması için belirli bir hesaplama yapılır. Ayrıca, ekran yırtılmasını engellemek için pikselleri geçici bir resme yazmak ve sonra bu resmi ekrana göndermek daha iyi bir yöntemdir.


# translate
Matematikte **"translate" (öteleme)**, bir şeklin belirli bir yönde ve belirli bir mesafede kaydırılması anlamına gelir.

**Özellikleri:**
    Şeklin boyutu, açısı ve yönü değişmez.
    Sadece konumu değişir.
    Genellikle (x, y) → (x + a, y + b) formülüyle ifade edilir (burada a ve b, öteleme miktarlarını gösterir).

Örnek:
Bir noktayı (2, 3) → (5, 7) olarak taşımak, (x + 3, y + 4) kadar ötelenmesi demektir.


# scale 
Matematikte **"scale" (ölçekleme)**, bir şeklin boyutlarının belirli bir oranla büyütülmesi veya küçültülmesi anlamına gelir.  

**Özellikleri:**
- **Ölçekleme**, şeklin oranlarını değiştirirken şeklin iç yapısını bozmadan boyutlarını artırır veya azaltır.
- Genellikle bir **skaler (ölçek) faktör** ile ifade edilir. Örneğin, **2x** ölçekleme, şeklin boyutlarını iki katına çıkarırken, **0.5x** ölçekleme, şekli yarıya indirir.

🔹 **Örnek:**  
Bir üçgenin kenarlarını **2** kat büyütmek, tüm kenarlarının uzunluğunu iki katına çıkarır, ancak açıları ve oranları aynı kalır.


# rotate
Matematikte **"rotate" (dönme)**, bir şeklin belirli bir açı etrafında döndürülmesi işlemidir. Bu işlemde şeklin boyutları değişmez, sadece yönü değişir.

**Özellikleri:**
- Dönme, genellikle bir nokta veya bir eksen etrafında yapılır.
- İki boyutlu bir şekil için dönme, genellikle orijinal (0, 0) noktasına göre veya belirli bir merkez etrafında yapılır.
- Dönme genellikle bir açıyla belirtilir (örneğin, 90°, 180° vb.).

🔹 **Örnek:**  
Bir noktanın **(x, y)** koordinatları, orijinal bir açıya (örneğin, 90°) göre döndürülürse, yeni koordinatlar şöyle hesaplanır:
- **(x', y')** = **(x * cos(θ) - y * sin(θ), x * sin(θ) + y * cos(θ))**
  Burada θ döndürme açısını temsil eder.

# transform 
Matematikte **"transform" (dönüşüm)**, bir nesnenin veya şeklin konumunu, boyutlarını, yönünü veya şeklini değiştirme işlemidir. Bu işlem, genellikle bir veya daha fazla matematiksel işlemin (örneğin, öteleme, ölçekleme, dönme) birleşimiyle gerçekleştirilir.

**Özellikleri:**
- **Dönüşüm**, şekillerin hareket ettirilmesi (öteleme), boyutlarının değiştirilmesi (ölçekleme), dönmesi (dönme) veya bunların kombinasyonlarını içerebilir.

