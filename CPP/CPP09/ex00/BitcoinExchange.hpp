
#pragma once    

#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange();
    ~BitcoinExchange();
    
    void    add_to_database(std::string filename);
    void    process_input(std::string input_file);
    double    calculate(std::string date, double value);

private:
        std::map<std::string, double> exrts;

};
