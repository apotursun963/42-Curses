
#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <algorithm>

/*
1. Bu Fonskiyon template func olduğu için farklı container türleri (std::vector, std::list, std::deque) çalışabilir
Buradaki (template <typename T>) T bir container'ın türünü ifade eder. (T = std::vector<int> | T = std::list<int>)  

2. typename T::iterator
Bu ifade, T türüne ait iterator tipini belirtir. Çünkü her STL container’ın kendine özgü bir iterator türü vardır:
std::vector<int>::iterator | std::list<int>::iterator | std::deque<int>::iterator 
Bu yüzden typename anahtar kelimesi kullanılır — derleyiciye T::iterator’ın bir tür (type) olduğunu açıkça söyler.

3. find() fonksiyhnu belirtilen (begin, end) aralıkta val değerini arar.
Bulursa o elemana iterator döner, bulamazsa container.end() döner. ve runtime_error ile çıkar
yok eğer Değer bulunduysa, o elemana işaret eden iterator döner.

4. it'in tipini std::vector<int>::iterator yapmışsın ama bu sadece vector containiri için çalışır
diğer containerlar ile çalışmasını istersen o zaman "typename T::iterator" yapmalısın. 
Bu, O container’a özgü iterator tipidir. yani Genel (template) hale getirir.
*/

template <typename T>
typename T::iterator easyfind(T &container, int val) {
    typename T::iterator it = std::find(container.begin(), container.end(), val);
    if (it == container.end())
        throw std::runtime_error("'value' not found in container");
    return (it);
}
