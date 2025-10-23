
#include "MutantStack.hpp"

int main(int, char **) {
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(7);
    mstack.pop();
    mstack.push(213);
    mstack.push(2);

    std::cout << "size: " << mstack.size() << std::endl;

    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); it++)
        std::cout << *it << std::endl;
}


/* ex02 (Mutated Abomination)
Stack (Yığın), çok faydalı bir container'dır ama bir eksiği var
o da stack üzerinde gezinemezsin (iterate edemezsin) Yani for veya while ile içindeki elemanları doğrudan dolaşamazsın.
Bu egzersizde ise bizden istediği:
std::stack’ten türetilmiş ama iterator’larla gezilebilen bir sınıf (MutantStack) yazmak.
push(), pop(), top(), size() zaten stack üzerinde çalışıyro ayrıca iterator funcs (begin, end) ekliyceksin
*/
