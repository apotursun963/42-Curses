
#pragma once

#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>

class Span {
public:
    Span();
    Span(unsigned int N);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void    addNumber(int num);
    int     shortestSpan();
    int     longestSpan();

private:
    size_t              max_size;
    std::vector<int>    vec;
};
