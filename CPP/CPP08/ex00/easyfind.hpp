

#pragma once

#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
int easyfind(T &container, int val) {
    typename T::iterator it = container.begin();
    typename T::iterator end = container.end();

    while (it != end) {
        if (val == *it)
            return (*it);
        it++;
    }
    throw std::runtime_error("there is not found 'value' in container");
}
