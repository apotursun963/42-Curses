

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


/*
Bu egzersizde, bir önceki egzersizdeki Harl sınıfını biraz daha geliştiriyorsun.
Temel amaç, kullanıcıdan bir seviye ("DEBUG", "INFO", "WARNING", "ERROR") alıp,
bu seviyeden başlayarak tüm üst seviyedeki mesajı ekrana bastırmak.
mesela WARNING yazdır çıktı olarak WARNING ve ERROR mesajları yazdırılır.
*/