

#pragma once

#include <iostream>
#include <cstdlib>
#include <vector>
#include <sys/time.h>   // gettimeofday() için
#include <algorithm>    // std:sort için



class PmergeMe {
private:
    std::vector<int> t_vector;


public:
    PmergeMe();
    PmergeMe(const PmergeMe& other);
    PmergeMe &operator=(const PmergeMe& other);
    ~PmergeMe();

    void add_to_containers(int argc, char **args);
    void sort_element_in_container(void);
    void calculate_duration();



};
