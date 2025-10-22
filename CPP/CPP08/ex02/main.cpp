

#include "MutantStack.hpp"

// kendi testini yazman gerkiro 
// int main(int, char **)
// {
    
//     return 0;
// }


int main()
{
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;
    mstack.pop();
    std::cout << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
    return 0;
}



/* ex02 (Mutated Abomination)
Stack (Yığın), çok faydalı bir container'dır ama bir eksiği var
o da stack üzerinde gezinemezsin (iterate edemezsin) Yani for veya while ile içindeki elemanları doğrudan dolaşamazsın.

Bu egzersizde ise bizden istediği:
std::stack’ten türetilmiş ama iterator’larla gezilebilen bir sınıf (MutantStack) yazmak.

push(), pop(), top(), size() zaten stack üzerinde çalışıyro ayrıca iterator funcs (begin, end) ekliyceksin

*/
