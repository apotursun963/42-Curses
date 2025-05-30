/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atursun <atursun@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/29 17:32:58 by atursun           #+#    #+#             */
/*   Updated: 2025/05/29 17:32:58 by atursun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

// Belirli bir alt dizgeyi başka bir alt dizgeyle değiştiren fonksiyon
std::string replaceAll(const std::string& str, const std::string& from, const std::string& to) {
    if (from.empty())
        return str;

    std::string result;
    size_t pos = 0;
    size_t found;

    while ((found = str.find(from, pos)) != std::string::npos) {
        result += str.substr(pos, found - pos);
        result += to;
        pos = found + from.length();
    }
    result += str.substr(pos);
    return result;
}

int main(int argc, char* argv[]) {
    if (argc != 4) {
        std::cout << "Usage: " << argv[0] << " <filename> <search> <replace>" << std::endl;
        return 1;
    }

    std::ifstream inputFile(argv[1]);
    if (!inputFile) {
        std::cout << "File can't be opened!" << std::endl;
        return 1;
    }

    std::string outputFileName = std::string(argv[1]) + ".replace";
    std::ofstream outputFile(outputFileName.c_str());
    if (!outputFile) {
        std::cout << "Output file can't be created!" << std::endl;
        return 1;
    }

    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << replaceAll(line, argv[2], argv[3]) << std::endl;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}

/*
Bir program yazmanız isteniyor. Program üç parametre alacak: bir dosya adı ve iki tane string (s1 ve s2).
Program, verilen dosyayı açacak ve içeriğini yeni bir dosyaya (orijinal dosya adının sonuna .replace eklenmiş haliyle) kopyalayacak.
Kopyalama sırasında, dosya içindeki her s1 ifadesini s2 ile değiştirecek.

std::ifstream (input file stream):
Dosyadan veri okumak için kullanılır. Yani bir dosyayı açıp içeriğini satır satır veya karakter karakter okuyabilirsiniz.
std::ofstream (output file stream):
Dosyaya veri yazmak için kullanılır. Yani bir dosya oluşturup içine veri yazabilirsiniz.
*/
