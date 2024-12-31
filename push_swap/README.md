
# Stack veri yapısı nedir, nasıl çalışır ve ne gibi operasyonları vardır
Stack (Yığın), LIFO (Last In, First Out) prensibiyle çalışan bir veri yapısıdır. Bu prensibe göre, en son eklenen eleman ilk önce çıkarılır. Günlük hayattan bir örnekle ifade edecek olursak, üst üste konulan tabaklar bir stack yapısına benzetilebilir: En son koyulan tabak, ilk önce alınır.



linked list ile Stack oluşturusak eklenen elemanlar bir sonraki düğümü değilde bir önceki elemanı işaret ediyor çünkü LIFO yani eklenen elemanın top'ta olması gerekiyor.

struct'ları arrary'ler yerine linked list ile tanımlamamız aslında daha avantajlı çünkü array'ler static boyutludur linked list'ler ise dinamik boyutludur.




/*
Bu tür bir stack tabanlı proje için aşağıdaki gibi adımlar ekleyebilirsiniz:

1. **Başlangıç Değerlerini Al**: 
   - terminalden aldığı argümanları kontrol et ve geçerli olup olmadığını kontrol et. (Boş değerler veya hatalı girişler için hata mesajları ver).

2. **Argümanları Geçerli Formatla Depola**:
   - Argümanları sayılara dönüştürüp ilk stack'e (`a` stack) yerleştirin.
   - Hatalı veri girişi (örneğin, sayılar dışında bir şey girildiğinde) durumunda hata mesajı verin.

3. **Stack'lerdeki Durumu Kontrol Et**:
   - **Empty Check**: Stack'lerin boş olup olmadığını kontrol et. Eğer boşsa, yapılacak işlem olmadığını belirtin.
   - **Sorted Check**: `a` stack'inin sıralı olup olmadığını kontrol et. Eğer sıralıysa, daha fazla işlem yapmaya gerek olmayabilir.

4. **Swap (sağ, soldan takas)**:
   - `a` stack'inde veya `b` stack'inde iki üst öğeyi takaslayın. Bu işlem sırasındaki değişiklikleri göster.

5. **Push (stack'ler arası veri taşıma)**:
   - `a` stack'inden `b` stack'ine veri taşıyın veya tam tersi.
   - `a`'dan `b`'ye push yapıldığında, `b` stack'inin sonuna veri eklenirken, `a` stack'inden en üst veri çıkar.

6. **Rotate (dönme işlemi)**:
   - `a` veya `b` stack'ini döndürün, yani ilk öğeyi en sona ekleyin. 
   - Bu işlemin ardından stack'lerin yeni durumu görüntülenmeli.

7. **Reverse Rotate (ters dönme işlemi)**:
   - `a` veya `b` stack'ini ters yönde döndürün, yani son öğeyi en başa ekleyin.
   - İşlem sonrası stack'lerin güncellenmiş hali gösterilmeli.

8. **Push to Sorted Stack**:
   - `a` stack'ini sıralı bir şekilde `b` stack'ine aktarın. Burada, sıralı yapıyı takip ederek verileri doğru sırayla taşıyabilirsiniz.

9. **Performing the Sorting Algorithm**:
   - Stack'teki sayıları sıralamak için kendi algoritmanızı yazın. Örneğin, **Selection Sort** veya **Insertion Sort** gibi bir algoritma kullanılabilir. Bu adımda, belirli bir sıralama düzeni sağlanana kadar swap, rotate ve push işlemleri yapılır.

10. **Output the Results**:
    - Her işlem sonrası stack'lerin durumunu terminalde gösterin. Bu, her adımdan sonra kullanıcıya nasıl bir değişiklik yapıldığını ve nasıl ilerlediğini gösterecektir.

11. **Edge Case Management**:
    - Hatalı veya beklenmeyen veriler için edge case senaryoları ekleyin. (Örneğin, boş input, aynı sayılar veya negatif sayılar.)

12. **Exit/End Program**:
    - Bütün işlemler tamamlandığında veya kullanıcı tarafından `exit` komutu verildiğinde programı düzgün bir şekilde sonlandırın.

Bunlar dışında, algoritmaların verimli çalışması ve hızlı işlem yapması için ek optimizasyonlar da yapılabilir.
*/
