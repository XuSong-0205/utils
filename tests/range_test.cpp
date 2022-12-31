#include <iostream>
#include "../include/range.hpp"

using utils::range;


#define PRINT_RANGE(...)                                        \
{                                                               \
    std::cout << "range(" << #__VA_ARGS__ << "): \t[";          \
    for (auto i : range(__VA_ARGS__)) std::cout << i << ", ";   \
    std::cout << "]\n";                                         \
}


void test_0()
{
    const auto print_range = [](const range& ran)
    {
        std::cout   << "range: [";
        for (auto i : ran) std::cout << i << ", ";
        std::cout << "]\n";
    };


    PRINT_RANGE(10);
    PRINT_RANGE(10, 0, -1)
    PRINT_RANGE(0, 10, 2);
    PRINT_RANGE(10, 0, -2);

}

int main()
{
    test_0();


    return 0;
}