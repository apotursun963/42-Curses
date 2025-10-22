
#include <iostream>
#include <string>


int topla(int a, int b) {
    return (a + b);
}

float topla(float a, float b) {
    return (a + b);
}

char topla(char a, char b) {
    return (a + b);
}


int main(int , char **)
{
    std::cout << topla(6, 4) << std::endl;
    std::cout << topla(2.3f, 3.2f) << std::endl;
    std::cout << topla('1', '2') << std::endl;

    
    return 0;
}





















// ---------

template <typename T>
T   topla(T a, T b) {
    return (a + b);
}

int main(int , char **)
{
    std::cout << topla(6, 4) << std::endl;
    std::cout << topla(2.3f, 3.2f) << std::endl;
    std::cout << topla('1', '2') << std::endl;

    return 0;
}


// -----
/*
bu fonksiyon iki farklı veri türü ile işlem yapabiliyor (T ve C)
*/
template <typename T, typename C>
C   topla(T a, C b) {
    return (a + b);
}

int main(int, char **) {
    std::cout << topla(4, 6.4) << std::endl;
    std::cout << topla(6, 4) << std::endl;
    std::cout << topla(2.3f, 3.2f) << std::endl;

    std::string str = "tursun";
    std::cout << topla('a', str) << std::endl;

    return 0;
}
