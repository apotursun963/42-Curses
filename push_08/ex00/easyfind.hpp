
#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

template <typename T>
typename T::iterator easyfind(T &container, int val) {
    typename T::iterator it = std::find(container.begin(), container.end(), val);
    if (it == container.end())
        throw std::runtime_error("'value' not found in container");
    return (it);
}
