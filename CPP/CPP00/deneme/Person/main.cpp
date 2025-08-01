



#include "Person.hpp"


int main(int argc, char const *argv[])
{
    // Person p;        // default constructure
    Person p("Abdullah", "ET", 20);     // parametreli constructure
    
    
    std::cout << p.get_name() << std::endl;
    std::cout << p.get_country() << std::endl;
    std::cout << p.get_age() << std::endl;

    return 0;
}
