
#pragma once

#include <string>

class Contact
{
private:
    std::string firstName, lastName, nickName, phoneNumber, secret;
public:
    void set(std::string&, std::string&, std::string&, std::string&, std::string&);
    std::string getFirstName();
    std::string getLastName();
    std::string getNickName();
    std::string getPhone();
    std::string getSecret();
};
