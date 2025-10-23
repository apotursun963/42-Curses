
#include "MutantStack.hpp"

int main(int, char**) {

    MutantStack<int> mstack;

    mstack.push(6);
    mstack.push(3);
    mstack.push(5);
    mstack.pop();
    mstack.push(2);

    std::cout << "Size: " << mstack.size() << std::endl;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
        std::cout << *it << std::endl;
    return (0);
}



/* ex02 (Mutated Abomination)
Stack (Yığın), çok faydalı bir container'dır ama bir eksiği var
o da stack üzerinde gezinemezsin (iterate edemezsin) Yani for veya while ile içindeki elemanları doğrudan dolaşamazsın.

Bu egzersizde ise bizden istediği:
std::stack’ten türetilmiş ama iterator’larla gezilebilen bir sınıf (MutantStack) yazmak.

push(), pop(), top(), size() zaten stack üzerinde çalışıyro ayrıca iterator funcs (begin, end) ekliyceksin
*/
