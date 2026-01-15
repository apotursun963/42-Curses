
#pragma once    

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange();
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange &operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    void    add_to_database(std::string filename);
    void    process_input(std::string input_file);

private:
        std::map<std::string, double> exrts;
};
