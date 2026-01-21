

#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <sys/time.h>   // gettimeofday() için
#include <algorithm>    // std:sort için



class PmergeMe {
private:
    std::vector<int> t_vector;
    std::deque<int>  t_deque;

public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe &operator=(const PmergeMe& other);
    ~PmergeMe();

    void add_to_containers(int argc, char **args);
    void sort_element_in_vector(void);
    void sort_element_in_deque(void); 
    void calculate_duration();



};

/*
Deque (Double-Ended Queue), adından da anlaşılacağı gibi iki ucundan da işlem yapılabilen 
doğrusal (linear) bir soyut veri yapısıdır (ADT). 
Teorik olarak kuyruk (queue) ve yığın (stack) yapılarını tek bir çatı altında birleştirir.
Deque, elemanların hem başından (front) hem de sonundan (back) eklenip çıkarılabildiği bir veri yapısıdır.
Klasik kuyrukta sadece
ekleme → sondan, çıkarma → baştan yapılabilir
Deque’de ise her iki uç da serbesttir


deque işlemleri
push_back
push_front
pop_back
pop_front
index erişimi (at)
insert / erase (orta)

*/


