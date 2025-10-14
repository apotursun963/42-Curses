
#include "Array.hpp"

int main(int, char **)
{
    Array<int> nums(15);

    for (int i=0; i < nums.size(); i++)
        nums[i] = i + 1;
    for (int i=0; i < nums.size(); i++)
        std::cout << nums[i] << ", ";    

    Array<int> nums_copy = nums;    
    nums_copy[0] = 777;

    Array<int> nums_assign = nums;  
    nums_assign[1] = 888;

    std::cout << "\nCopied nums_copy[0]: " << nums_copy[0] << std::endl;
    std::cout << "Original nums[0]: " << nums[0] << std::endl;

    std::cout << "Copied nums_assign[1]: " << nums_assign[1] << std::endl;
    std::cout << "Original nums[1]: " << nums[1] << std::endl;

    try {
        std::cout << nums[0] << std::endl;
        std::cout << nums[20] << std::endl;
    }
    catch (std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }
    return 0;
}
