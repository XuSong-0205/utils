#include <iostream>
#include "../include/config.hpp"

void test_0()
{
    std::cout << "__CPLUSPLUS: " << __CPLUSPLUS << "\n";
    std::cout << "__HAS_CPP11: " << __HAS_CPP11 << "\n";
    std::cout << "__HAS_CPP14: " << __HAS_CPP14 << "\n";
    std::cout << "__HAS_CPP17: " << __HAS_CPP17 << "\n";

    std::cout << "UTILS_VERSION_MAJOR: " << UTILS_VERSION_MAJOR << "\n";
    std::cout << "UTILS_VERSION_MINOR: " << UTILS_VERSION_MINOR << "\n";
    std::cout << "UTILS_VERSION_PATCH: " << UTILS_VERSION_PATCH << "\n";
    std::cout << "UTILS_VERSION_VALUE: " << UTILS_VERSION_VALUE << "\n";
    std::cout << "UTILS_VERSION_STR: " << UTILS_VERSION_STR << "\n";
    constexpr auto version = UTILS_VERSION_STR;

}

int main()
{
    test_0();

    return 0;
}