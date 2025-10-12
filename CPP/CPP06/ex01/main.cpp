
#include "Serialization.hpp"

std::ostream    &operator<<(std::ostream &out, Data const &arg) {
    out << arg.value << std::endl;
    return out;
}

int main(void)
{
    Data *data = new Data;

    data->value = 10;
    std::cout << "Original Pointer: " << data << std::endl;

    uintptr_t serialized = Serializer::serialize(data);
    std::cout << "Serialized Value: " << serialized << std::endl;

    Data* deserialized = Serializer::deserialize(serialized);
    std::cout << "Deserialized Value: " << deserialized << std::endl;

    if (deserialized == data)
        std::cout << "data is Equal to deserialized" << std::endl;
    else
        std::cout << "data is not Equal to deserialized" << std::endl;
    delete data;
    return 0;
}
