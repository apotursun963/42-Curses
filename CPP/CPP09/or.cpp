
#include <iostream>
#include <ctime>
#include <iomanip>

void example_function()
{
    for (int i = 0; i < 1000000; i++)
    {
        // boş döngü
    }
}

int main()
{
    clock_t start;
    clock_t end;

    start = clock();

    example_function();

    end = clock();

    double duration_us =
        (double)(end - start) * 1000000.0 / CLOCKS_PER_SEC;

    std::cout << duration_us << " us" << std::endl;

    return 0;
}


// int main()
// {
//     struct timeval start;
//     struct timeval end;

//     gettimeofday(&start, NULL);

//     example_function();

//     gettimeofday(&end, NULL);

//     long seconds = end.tv_sec - start.tv_sec;
//     long microseconds = end.tv_usec - start.tv_usec;

//     long duration = seconds * 1000000 + microseconds;

//     std::cout << "Gecen sure: " << duration << " us" << std::endl;

//     return 0;
// }
