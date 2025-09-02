
#pragma once

#include <iostream>
#include <cstdlib>

class Brain {
private:
    std::string ideas[100];

public:
    Brain();
    Brain(const Brain &other);
    Brain &operator=(const Brain &other);
    ~Brain();

    void        fillIdeas(void);
    std::string getRandomIdea(void);
};
