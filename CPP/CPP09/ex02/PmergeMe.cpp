

#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) {*this = other;}
PmergeMe &PmergeMe::operator=(const PmergeMe& other) {
    (void)other;
    return (*this);
}
PmergeMe::~PmergeMe() {}





void PmergeMe::calculate_duration() {

    struct timeval st;
    struct timeval en;

    std::cout << "Before: ";
    for (std::vector<int>::iterator it = t_vector.begin(); it != t_vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    gettimeofday(&st, NULL);
    sort_element_in_container();    // sorting algorithm
    gettimeofday(&en, NULL);

    long seconds = en.tv_sec - st.tv_sec;
    long microseconds = en.tv_usec - st.tv_usec;
    double duration = (double)seconds * 1000000.0 + (double)microseconds;

    std::cout << "After:  ";
    for (std::vector<int>::iterator it = t_vector.begin(); it != t_vector.end(); it++)
        std::cout << *it << " ";

    std::cout << std::endl;
    std::cout << "Time to process a range of " << t_vector.size() 
        << " elements with std::[..] : " << duration << " us" << std::endl;
} 

void PmergeMe::add_to_containers(int argc, char **args) {
    // added to vector
    for (int i=1; i < argc; i++) {
        int number = atoi(args[i]);
        t_vector.push_back(number);
    }
}

void PmergeMe::sort_element_in_container(void) {
    std::sort(t_vector.begin(), t_vector.end());
}
