
#include "easyfind.hpp"

int main(int, char **)
{
    {
        std::cout << "\033[1;33m<<<Vector Container>>>\033[0m" << std::endl;

        std::vector<int> vec;
        vec.push_back(7);
        vec.push_back(235);
        vec.push_back(75);
        vec.push_back(5432);
        vec.pop_back();
        vec.insert(vec.begin(), 42);

        try {
            std::vector<int>::iterator res2 = easyfind(vec, 33);
            std::cout << "value founded -> " << *res2 << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        std::cout << "\033[1;31m<<<List Container>>>\033[0m" << std::endl;

        std::list<int> lst;
        lst.push_back(34);
        lst.push_back(25);
        lst.push_front(734);

        try {
            std::list<int>::iterator it1 = easyfind(lst, 25);
            std::cout << "value founded -> " << *it1 << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }

    {
        std::cout << "\033[1;32m<<<Deque Container>>>\033[0m" << std::endl;

        std::deque<int> deq;
        deq.push_back(99);
        deq.push_back(234);
        deq.push_front(11);
        deq.push_back(3);
        deq.pop_back();
        deq.pop_front();

        try {
            std::deque<int>::iterator it2 = easyfind(deq, 234);
            std::cout << "Value found -> "<< *it2 << std::endl;
        }
        catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }
    }
    return 0;
}
