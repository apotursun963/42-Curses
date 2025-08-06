
#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        int i = 1;
        while (argv[i])
        {
            int j = 0;
            while (argv[i][j])
            {
                std::cout << (char) std::toupper(argv[i][j]);
                j++;
            }
            std::cout << " ";
            i++;
        }
        std::cout << "\n";
    }
    return 0;
}

/*
Bu program komut satırından aldığı argümanları büyük harfe çevirip ekrana yazacak. 
Argüman verilmezse özel bir mesaj basacak.
*/
