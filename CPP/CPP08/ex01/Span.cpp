
#include "Span.hpp"

Span::Span() : max_size(0) {}
Span::Span(unsigned int N) : max_size(N) {}
Span::Span(Span const &other) {*this = other;}
Span::~Span() {}
Span &Span::operator=(Span const &other) {
    if (this != &other) {
        this->max_size = other.max_size;
        this->vec = other.vec;
    }
    return (*this);
}

void    Span::addNumber(int num) {
    if (this->vec.size() < max_size)
        this->vec.push_back(num);
    else
        throw std::runtime_error("Vector is already full Or empty");
}

int Span::shortestSpan() {
    if (vec.size() < 2)
        throw std::runtime_error("to find shortestSpan it must be atleast 2 element");

    std::sort(vec.begin(), vec.end());

    int dif = 0;
    int shortest = INT_MAX;
    for (size_t i = 0; i < vec.size() - 1; i++) {
        dif = vec[i + 1] - vec[i];
        if (dif < shortest)
            shortest = dif;
    }   
    return (shortest);
}

int Span::longestSpan() {
    if (vec.size() < 2)
        throw std::runtime_error("to find longestSpan it must be atleast 2 element");
    std::sort(vec.begin(), vec.end());
    int lgst_gap = vec.back() - vec.front();
    return (lgst_gap);
}
