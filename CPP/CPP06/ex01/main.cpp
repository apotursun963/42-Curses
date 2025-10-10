


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


/* Amaç
- Bir Data yapısı (struct) oluşturacaksın. 
Bu boş olmayacak (yani içinde en az bir data member olacak, mesela int value;).
- Bir Serializer sınıfı yazacaksın.
- Kullanıcı bu sınıftan nesne oluşturamayacak (constructor’ı private olacak).
- İçinde sadece static metodlar olacak:
    - serialize(Data* ptr) → Data* pointer’ını alıp uintptr_t tipine çevirecek.
    - deserialize(uintptr_t raw) → integer’ı alıp tekrar Data* pointer’ına çevirecek.
- Test programında:
- Bir Data nesnesi oluşturacaksın.
- Onun adresini serialize() ile integer’a çevireceksin.
- O integer’ı tekrar deserialize() ile pointer’a çevireceksin.
- Ve bu pointer’ın orijinal pointer ile aynı olduğunu kontrol edeceksin (== ile).

---
reinterpret_cast -> Pointerlar arasında yapılan dönüşümlerdir (dikkatli olunmalıdır).
Örneğin, bir tam sayıyı bir işaretçiye ya da bir işaretçiyi başka bir tür işaretçiye dönüştürebilir.

*/
