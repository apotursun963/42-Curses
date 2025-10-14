
#pragma once

#include <iostream>

template <typename T, typename F>
void    iter(T *arr, int len, void(*func)(F)) {
    int i = -1;
    while (++i < len)
        func(arr[i]);
}

template <typename T>
void    cout(T const &value) {
    std::cout << value << std::endl;
}
