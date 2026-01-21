
#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}
PmergeMe::PmergeMe(const PmergeMe& other) {*this = other;}
PmergeMe &PmergeMe::operator=(const PmergeMe& other) {
    (void)other;
    return (*this);
}
PmergeMe::~PmergeMe() {}


void PmergeMe::calculate_duration() {

    struct timeval v_st, v_en;
    struct timeval d_st, d_en;

    std::cout << "Before : ";
    for (std::vector<int>::iterator it = t_vector.begin(); it != t_vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    gettimeofday(&v_st, NULL);
    sort_element_in_vector();    // sorting algorithm
    gettimeofday(&v_en, NULL);

    long v_seconds = v_en.tv_sec - v_st.tv_sec;
    long v_microseconds = v_en.tv_usec - v_st.tv_usec;
    double v_duration = (double)v_seconds * 1000000.0 + (double)v_microseconds;

    // ------------
    gettimeofday(&d_st, NULL);
    sort_element_in_deque();    // sorting algorithm
    gettimeofday(&d_en, NULL);

    long d_seconds = d_en.tv_sec - d_st.tv_sec;
    long d_microseconds = d_en.tv_usec - d_st.tv_usec;
    double d_duration = (double)d_seconds * 1000000.0 + (double)d_microseconds;

    std::cout << "After:  ";
    for (std::vector<int>::iterator it = t_vector.begin(); it != t_vector.end(); it++)
        std::cout << *it << " ";

    std::cout << std::endl;
    std::cout << "Time to process a range of " << t_vector.size()
        << " elements with std::vector : " << v_duration << " us" << std::endl;

    std::cout << "Time to process a range of " << t_deque.size() 
        << " elements with std::deque : " << d_duration << " us" << std::endl;
}

void PmergeMe::add_to_containers(int argc, char **args) {
    for (int i=1; i < argc; i++) {
        int number = atoi(args[i]);
        t_vector.push_back(number); // vektöre ekleme
        t_deque.push_back(number);  // deque ekleme
    }
}

void PmergeMe::sort_element_in_vector(void) {
    std::sort(t_vector.begin(), t_vector.end());
}

void PmergeMe::sort_element_in_deque(void) {
    std::sort(t_deque.begin(), t_deque.end());
}

