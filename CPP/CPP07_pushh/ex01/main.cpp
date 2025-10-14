
#include "iter.hpp"

int main(void)
{
    int const arr_int[] = {1, 2, 3, 4, 5};
    iter(arr_int, 5, cout<int>);

    std::cout << "-----\n";
    float arr_float[] = {75.4f, 64.2f, 2.99f};
    iter(arr_float, 3, cout<float>);

    std::cout << "-----\n";
    char arr_chr[] = {'a', 'b', 'c', 'd', 'e'};
    iter(arr_chr, 5, cout<char>);

    return 0;
}
