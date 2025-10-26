
#pragma once

#include <iostream>
#include <stack>


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

/*
“Container adapter” nedir?
C++’ta container adapter, başka bir container’ın (örneğin std::deque, std::vector, std::list) üzerinde 
çalışan bir “sarmalayıcı” (wrapper) sınıftır.
Kendi başına veri tutmaz, bunun yerine altında bir gerçek container kullanır.
std::stack, LIFO (Last In First Out) mantığıyla çalışan bir container adapter’dir.
Ama kendi içinde verileri bir başka container’da tutar.
- Varsayılan olarak -> std::deque<T>  = gerçek veri burada tutulur
- Tabi görünüşte -> std::stack<T>     = stack bu deque'yi kullanır
- std::stack<<int, std::deque<int>> s;  // stack bu deque'yi kullanır

std::stack, STL’deki “container adapter” denen yapılardan biridir. 
Yani kendi başına bir container değildir — başka bir container’ı içinde kullanır.
stack içinde container olarak list, vector veya deque kullanabilir

- std::stack hangi veri yapısını içeride kullanıyorsa, container_type onun türüdür.
Yani std::stack, içeride bir std::deque<int> kullanır.
İşte o std::deque<int> kısmına container_type denir.
std::stack<int>::container_type == std::deque<int>

- this:
std::stack sınıfında, asıl veriler c adında bir container içinde tutulur.
Bu c değişkeni protected olduğu için, MutantStack gibi std::stack’ten türeyen sınıflar tarafından erişilebilir.
*/
