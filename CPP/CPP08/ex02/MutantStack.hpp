
#pragma once

#include <iostream>
#include <stack>


/*
typename: Derleyiciye “bu bir tür ismi” der
*/
template <typename T>
class MutantStack : public std::stack<T> {
public:
    MutantStack() {};
    MutantStack(const MutantStack &other) {*this = other;};
    MutantStack &operator=(const MutantStack &other) {(void)other; return (*this);};
    ~MutantStack() {};

    // “iterator adında bir tür tanımlıyorum; bu, std::stack’in kullandığı container’ın iterator türüdür.”
    typedef typename std::stack<T>::container_type::iterator iterator;

    iterator begin() {
        return (this->c.begin());       // “Stack içindeki container’ın başından itibaren gezmeye başla.”
    }
    iterator end() {
        return (this->c.end());     // “Stack içindeki container’ın sonuna kadar git (son elemandan bir sonraki konum).”
    }
};
