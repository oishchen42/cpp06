#include "Serializer.hpp"

int main()
{
    Data testData;

    std::cout << "===Original Data===\n";
    std::cout << "testData.name: " << testData.name << std::endl;
    std::cout << "testData.value: " << testData.value << std::endl;
    std::cout << "testData memorry: " << &testData << std::endl;
    std::cout << "========================\n";

    uintptr_t raw = Serializer::serialize(&testData);
    std::cout << "\n===Raw representation===\n";
    std::cout << "raw: " << raw << std::endl;
    std::cout << "========================\n";

    Data* reworkedData = Serializer::deserialize(raw);
    std::cout << "\n===Original Data===\n";
    std::cout << "reworkedData.name: " << (*reworkedData).name << std::endl;
    std::cout << "reworkedData.value: " << (*reworkedData).value << std::endl;
    std::cout << "reworkedData memorry: " << reworkedData << std::endl;
    std::cout << "========================\n";

    if (reworkedData == &testData)
        std::cout << "\n===SUCCESS===\n";
    else
        std::cout << "===SMTH WENT WRONG\n===";
}