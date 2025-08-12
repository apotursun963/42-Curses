

#include <iostream>
#include <fstream>
#include <string>

std::string replaceAll(std::string line, std::string from, std::string to) {
    std::string result;
    int pos = 0;
    int found;    

    if (from.empty())
        return line;
    for (;;) {
        found = line.find(from, pos);              
        if (found == -1)                       
            break;
        result += line.substr(pos, found - pos);    
        result += to;                               
        pos = found + from.length();                
    }
    result += line.substr(pos);                     
    return result;                                  
}

int main(int argc, char **argv)
{
    if (argc != 4)
        return (std::cout << "Usage: " << argv[0] << " <filename> <search> <replace>" << std::endl, 1);       
    
    std::ifstream inputFile(argv[1]);   
    if (!inputFile)
        return (std::cout << "File can't be opened!" << std::endl, 1);

    std::string outputFileName = std::string(argv[1]) + ".replace";

    std::ofstream outputFile(outputFileName.c_str()); 
    if (!outputFile)
        return (std::cout << "Output file can't be created!" << std::endl, 1);

    std::string line;
    while (std::getline(inputFile, line)) {
        outputFile << replaceAll(line, argv[2], argv[3]) << std::endl;
    }
    inputFile.close();
    outputFile.close();
    return 0;
}
