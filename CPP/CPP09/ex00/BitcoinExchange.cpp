
#include "BitcoinExchange.hpp"
#include <cstring>
#include <cstdlib>

// bütün orthodoks şeyleri eklenecekmi öğren ona göre ver
// ayrıca evo pag'e bak
BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

/*
input file stream: ifstream -> dosyayı açıp içindeki verileri okumamıa olanak sağlıyor
*/

void BitcoinExchange::add_to_database(std::string filename) {
    std::ifstream file(filename.c_str());   // ifstream const kabul ettiği iççin c_str() yaptım
    if (file.is_open() == false)
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    while (std::getline(file, line)) {
        size_t comma_idx = line.find(',');   // hata durumlarını ele (mesela yoksa)
        if (comma_idx == std::string::npos)
            std::cout << "Error: bad input => " << line << std::endl;

        std::string date = line.substr(0, comma_idx);
        std::string value = line.substr(comma_idx + 1);
        exrts[date] = atof(value.c_str());  // str -> double/float   (hatalı stringleri 0 olarak döndürür.)
    
    }

    // std::cout << "size: " << exrts.size() << std::endl;  
    // for (std::map<std::string, double>::iterator it = exrts.begin(); it != exrts.end(); ++it)   // elemanları yazdırmak
    //     std::cout << "date: " << it->first << "rate: " << it->second << std::endl;

}

/*
calculateValue() fonksiyonu, verilen bir tarih ve miktar (amount) için Bitcoin’in karşılığını hesaplıyor.
*/
double BitcoinExchange::calculate(std::string date, double value) {
    if (value < 0)
        throw std::runtime_error("Error: not a positive number.");

    if (value > 1000)
        throw std::runtime_error("Error: too large a number.");

    std::map<std::string, double>::const_iterator it = exrts.lower_bound(date);
    if (it == exrts.end() || it->first != date) {
        if (it == exrts.begin())
            throw std::runtime_error("bad input mannn");
        --it;
    }
    return (it->second * value);    // it->second: tarihe en yakın Bitcoin kuru
}


void BitcoinExchange::process_input(std::string input_file) {
    std::ifstream file(input_file.c_str());   // ifstream const kabul ettiği iççin c_str() yaptım
    if (file.is_open() == false)
        throw std::runtime_error("Error: could not open file.");

    std::string line;
    while (std::getline(file, line)) {
        size_t pipe_idx = line.find('|');   // hata durumlarını ele (mesela yoksa)
        if (pipe_idx == std::string::npos)
            std::cout << "Error: bad input => " << line << std::endl;

        std::string date = line.substr(0, pipe_idx);
        std::string value_str = line.substr(pipe_idx + 1);

        try {
            double value = atof(value_str.c_str());
            double final_result = calculate(date, value);
            std::cout << date << "=> " << value << " = " << final_result << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
}
