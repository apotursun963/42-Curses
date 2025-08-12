

#include "Harl.hpp"
#include <cstring>

int main(int argc, char **argv)
{
    Harl test;

    if (argc != 2)
        return (std::cout << "Usage: ./harlFilter level\n", 0);
    if (
        strcmp(argv[1], "DEBUG") &&
        strcmp(argv[1], "INFO") &&
        strcmp(argv[1], "WARNING") &&
        strcmp(argv[1], "ERROR")
    )
        return (std::cout << "Wrong level type\n", 0);
    test.complain(argv[1]);
}
