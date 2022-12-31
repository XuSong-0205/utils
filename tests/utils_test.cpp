#include <iostream>
#include "../include/utils.hpp"

void test_0()
{
    const auto print_abs = [](int num)
    {
        std::cout << "abs(" << num << ") = " << utils::abs(num) << "\n";
    };

    print_abs(-1);
    print_abs(INT_MIN);     // error
    print_abs(0);
    print_abs(1);
    print_abs(INT_MAX);

}

int main()
{
    test_0();


    return 0;
}