

#include <iostream>
#include <fstream>
#include <string>

// Belirli bir alt dizgeyi başka bir alt dizgeyle değiştiren fonksiyon
std::string replaceAll(const std::string& str,  const std::string& from, const std::string& to) {
    if (from.empty())
        return str;

    std::string result;     // Sonuçları biriktireceğimiz yeni string
    size_t pos = 0;        // Hangi karakterden başlayarak arama yapacağımızı belirtir.
    size_t found;           // Bulunan from’un bulunduğu yerin indeksini tutar.

    /*
    -Döngü ile Arama ve Değiştirme:
        - find(): str içinde, pos’dan başlayarak ilk from’u arar.
        - Bulursa:
            - result’a, aradığımız metne kadar olan kısmı ekler.
            - Ardından to’yu ekler.
            - Aramanın başlangıç noktasını güncelleriz.
        - Bulamazsa döngü biter.
    - Kalan Kısmı Eklemek:
    - Döngüden çıktıktan sonra, string’in geri kalanını da result’a ekleriz.
    - Sonuç:
        - Değiştirilmiş string döner.
    */
    while ((found = str.find(from, pos)) != std::string::npos) {
        result += str.substr(pos, found - pos);
        result += to;
        pos = found + from.length();
    }
    result += str.substr(pos);
    return result;
}

int main(int argc, char **argv)
{
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " <filename> <search> <replace>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);   // dosyayı okuma
    if (!inputFile) {
        std::cout << "File can't be opened!" << std::endl;
        return 1;
    }

    // Çıktı dosyasının adını belirler ve dosyayı açar.
    std::string outputFileName = std::string(argv[1]) + ".replace";
    std::ofstream outputFile(outputFileName.c_str());   // dosyaya yazma
    if (!outputFile) {
        std::cout << "Output file can't be created!" << std::endl;
        return 1;
    }

    /*
    Dosyayı satır satır okur.
    Her satırda, aranan string’i bulur ve değiştirir.
    Sonucu çıktı dosyasına yazar.
    */
    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << replaceAll(line, argv[2], argv[3]) << std::endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}

/*
ex04 amacı
---
Bu egzersizin amacı, bir dosya içindeki belirli bir kelimeyi başka bir kelimeyle 
değiştirip sonucu yeni bir dosyaya yazan bir program geliştirmektir. 

Program üç parametre alır: (./replace input.txt s1 s2)
- Dosya adı
- Aranacak kelime (s1)
- Yerine yazılacak kelime (s2)

İşleyiş:
- Dosya açılır, satır satır okunur.
- Her satırda, s1 geçen tüm yerler s2 ile değiştirilir.
- Sonuç, yeni bir dosyaya (input.txt.replace) yazılır.
- Hatalı durumları (dosya bulunamaz, parametre eksik vs.) güzelce ele al.

1. Dosya İşlemleri
std::ifstream (input file stream): Dosyadan okuma yapmak için kullanılır.
std::ofstream (output file stream): Dosyaya yazmak için kullanılır.

2. String Manipülasyonu
std::string::find(): Bir string içinde alt string aramak için kullanılır.
std::string::substr(): Stringin bir kısmını almak için kullanılır.
replaceAll fonksiyonu: Bir satırda geçen tüm s1’leri s2 ile değiştirir.
*/
