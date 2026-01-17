
#include "BitcoinExchange.hpp"
#include <cstring>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {*this = other;}
BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other)
        this->exrts = other.exrts;
    return (*this);
}
BitcoinExchange::~BitcoinExchange() {}



/*
input file stream: ifstream -> dosyayı açıp içindeki verileri okuymama olanak sağlıyor
*/
/*
bu fonksyonu ile data.csv dosyasındaki verileri parsladım
date ve rate olmak üzere map veri yapısına ekledim
*/
void BitcoinExchange::add_database(std::string filename) {
    std::ifstream file(filename.c_str());   // ifstream const kabul ettiği iççin c_str() yaptım
    if (file.is_open() == true) {
        std::string line;
        while (std::getline(file, line)) {
            size_t comma_idx = line.find(',', 0);   // hata durumlarını ele (mesela yoksa)
            if (comma_idx == std::string::npos) {   // npos: no posotion (böyle bir karakter yok anlamına geliyr)
                std::cout << "Error: bad input (büyük ihtimalle if'e girmez de neyse)=> " << line << std::endl;
                continue;
            }
            std::string date = line.substr(0, comma_idx);
            std::string exrt = line.substr(comma_idx + 1);
            exrts[date] = atof(exrt.c_str());  // str -> double/float   (hatalı stringleri 0 olarak döndürür.)

        // örnek mape eklenen verileri iterator ile yazdırma
        // std::cout << "size: " << exrts.size() << std::endl;
        // if (atof(exrt.c_str()) == 0) {
        //     for (std::map<std::string, double>::iterator it = exrts.begin(); it != exrts.end(); it++)
        //         std::cout << it->first << ": " << it->second << std::endl;
        // }
        }
    }
    else
        throw std::runtime_error("Error: could not open file.");
}

int ctrl_date(std::string date) {
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    size_t st = date.find_first_not_of(" \t");
    size_t en = date.find_last_not_of(" \t");
    if (st == std::string::npos)
        return (1);
    std::string cleaned_date = date.substr(st, en - st + 1);
    if (cleaned_date.length() != 10 || cleaned_date[4] != '-' || cleaned_date[7] != '-')
        return (1);
    for (size_t i=0; i < cleaned_date.length(); i++) {
        if (cleaned_date[i] == '-')
            continue;
        if (!std::isdigit(cleaned_date[i]))
            return (1);
    }
    int year = std::atoi(cleaned_date.substr(0, 4).c_str());
    int month = std::atoi(cleaned_date.substr(5, 2).c_str());
    int day = std::atoi(cleaned_date.substr(8, 2).c_str());
    if ((year < 2009 || year > 2022) || (month < 1 || month > 12) || (day < 1 || day > days[month - 1]))
        return (1);
    return (0);
}

void BitcoinExchange::process_input(std::string input_file) {
    std::ifstream file(input_file.c_str());   // ifstream const kabul ettiği iççin c_str() yaptım
    if (file.is_open() == true) {
        std::string line;
        while (std::getline(file, line)) {
            size_t pipe_idx = line.find('|', 0);   // hata durumlarını ele (mesela yoksa)
            if (pipe_idx == std::string::npos) {
                std::cout << "Error: bad input => " << line << std::endl;
                continue;
            }
            // tarih ve değeri (bitcoin adedini) ayırma (string olarak)
            std::string date = line.substr(0, pipe_idx);
            std::string value_str = line.substr(pipe_idx + 1);
            if (!strncmp(value_str.c_str(), " value", 6))
                continue;
            if (ctrl_date(date)) {
                std::cout << "Error: bad date input" << " => " << date << std::endl;
                continue;
            }
            try {                
                double value = atof(value_str.c_str());
                double final_result = 0;

                if (value < 0)
                    throw std::runtime_error("Error: not a positive number.");
                if (value > 1000)
                    throw std::runtime_error("Error: too large a number.");

                // amaç: Girilen tarih map’te yoksa, o tarihten önceki en yakın tarihi bulmak.
               // lower_bound(): küçük OLMAYAN ilk elemanı döndürür. (date ≥ aranan olan ilk eleman)
               // basitle, “Bana aranan değere eşit ya da ondan büyük ilk şeyi ver.”
                std::map<std::string, double>::const_iterator it = exrts.lower_bound(date); // const_iterator: Sadece okuma
                // it == exrts.end():
                // eğer lower_bound(date) map’te date’ten büyük veya eşit hiçbir tarih bulamadı.
                // it->first != date: lower_bound bir eleman buldu ama exact tarih değil.
                if (it == exrts.end() || it->first != date) {   // ikisinde de exact tarih yoksa giriyor
                    if (it == exrts.begin())    // “Bir önceki tarihe gidebilir miyim?” diyor (gidemez çünkü it begin() eşit en eski tarihten önce daha eski bir tarih yok<)
                        throw std::runtime_error("Error: date too old.");
                    --it;   // Bir önceki tarihi kullan (en yakın geçmiş tarih)
                }
                // bitcoin miktarını (value), o tarihteki bitcoin fiyatıyla çarpıyor.
                final_result = it->second * value;
                std::cout << date << "=> " << value << " = " << final_result << std::endl;
            }
            catch (std::exception &e) {
                std::cout << e.what() << std::endl;
            }
        }
    }
    else
        throw std::runtime_error("Error: could not open file.");
}
