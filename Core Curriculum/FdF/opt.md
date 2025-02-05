# renkleri mavi yap
# key handling degistir
# 


# mlx_get_data_addr():
Pikselleri bir resme yazarken, doğrudan mlx_pixel_put kullanmak yavaştır çünkü her pikseli anında pencereye gönderir. Bunun yerine, pikselleri önce bir resme (buffer) yazıp, ardından bu resmi ekrana yansıtmak daha verimlidir. MLX kütüphanesinde, resmin verilerine erişmek için **mlx_get_data_addr** fonksiyonu kullanılır. Bu fonksiyon, resmin bellek adresini almayı sağlar ve piksellerin doğru bir şekilde yazılabilmesi için gerekli bilgileri (bpp, line_length, endian) sağlar. Piksellerin doğru bellek adresine yazılması için belirli bir hesaplama yapılır. Ayrıca, ekran yırtılmasını engellemek için pikselleri geçici bir resme yazmak ve sonra bu resmi ekrana göndermek daha iyi bir yöntemdir.


# Proje adımları
- initialize durumları
    - Dosya içindeki veriler okunmalı *read_map*
        - read_map ile öncelikle kordinatlar init edilmeli
        - sonra dosyadan her bir noktayı okuyup ve bu noktaları belirtilen koordinatlara yerleştirilecek
        - daha kordinatlar eski yerine center edilmeli
    - mlx_init tanımlanmalı
    - image init edilmeli
    - camera init edilmeli
    - en sonunda bu fdf yapısı döndürülmeli
- render süreci

