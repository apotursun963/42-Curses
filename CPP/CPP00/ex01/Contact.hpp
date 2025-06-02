
#pragma once

#include <string>

// kapsülleme bir classın detaylarını/özelliklerini olabildiğince gizlemek/korumak anlamına gelir.
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
