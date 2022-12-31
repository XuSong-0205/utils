#include <iostream>
#include "../../include/io/color.hpp"

void test_0()
{
    namespace color = utils::io::color;
    const auto print_color = [](color::color col, const char* str)
    {
        std::cout << col << str << "\n" << color::status::CLEAR;
    };

    print_color(color::color::F_WHITE,  "hello c++03");
    print_color(color::color::F_RED,    "hello c++11");
    print_color(color::color::F_YELLOW, "hello c++14");
    print_color(color::color::F_GREEN,  "hello c++17");
    print_color(color::color::F_CYAN,   "hello c++20");
    print_color(color::color::F_BLUE,   "hello c++23");
    print_color(color::color::F_PURPLE, "hello c++26");

}


int main()
{
    test_0();


    return 0;
}