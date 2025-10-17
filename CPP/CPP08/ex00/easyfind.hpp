
#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

// vector ve array indekslenebilir olduğu için container[i]
// yapabilioyoruz yoksa list, set vb. ile çalışmaz
template <typename T>
int easyfind(T &container, int val) {
    for (size_t i=0; i < container.size(); i++) {
        if (val == container[i])
            return (container[i]);
    }
    throw std::runtime_error("'value' not found in container");
}
