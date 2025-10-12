
#pragma once

#include <iostream>

template <typename T, typename F>   // bu funcs iki tür parametre alır (T, F)
void    iter(T *arr, int len, F func) {
    int i = -1;
    while (++i < len)
        func(arr[i]);
}

/* !Önemli
The function passed as the third parameter may take its argument by const reference
or non-const reference, depending on the context.
*/
template <typename T>
void    cout(T const &value) {
    std::cout << value << std::endl;
}
