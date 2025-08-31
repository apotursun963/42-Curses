

#pragma once

#include <iostream>

class Brain {
private:
    std::string ideas[100];

public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();

    void    SelectRandIdeas(void);
    void    fill_to_ideas(const std::string arr[]);

};