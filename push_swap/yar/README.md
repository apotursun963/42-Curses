
# Stack veri yapısı nedir, nasıl çalışır ve ne gibi operasyonları vardır
Stack (Yığın), LIFO (Last In, First Out) prensibiyle çalışan bir veri yapısıdır. Bu prensibe göre, en son eklenen eleman ilk önce çıkarılır. Günlük hayattan bir örnekle ifade edecek olursak, üst üste konulan tabaklar bir stack yapısına benzetilebilir: En son koyulan tabak, ilk önce alınır.



linked list ile Stack oluşturusak eklenen elemanlar bir sonraki düğümü değilde bir önceki elemanı işaret ediyor çünkü LIFO yani eklenen elemanın top'ta olması gerekiyor.

struct'ları arrary'ler yerine linked list ile tanımlamamız aslında daha avantajlı çünkü array'ler static boyutludur linked list'ler ise dinamik boyutludur.
