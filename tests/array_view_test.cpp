#include <iostream>
#include "../include/array_view.hpp"

using utils::array_view;
using utils::make_array_view;

template<typename T>
void print_array_view(array_view<T> arr)
{
    std::cout << "[";
    for (auto x : arr) std::cout << x << ", ";
    std::cout << "]\n";
}

void test_0()
{
    int _arr[]{0, 1, 2, 3, 4, 5};
    array_view<int> arr(_arr);
    std::cout << "arr: ";
    print_array_view(arr);
    std::cout << "arr.size(): " << arr.size() << "\n";
    std::cout << "arr.max_size(): " << arr.max_size() << "\n";
    std::cout << "arr.empty(): " << arr.empty() << "\n";
    std::cout << "*arr.begin(): " << *arr.begin() << "\n";
    std::cout << "*(arr.end() - 1): " << *(arr.end() - 1) << "\n";
    std::cout << "arr[0]: " << arr[0] << "\n";
    std::cout << "arr.at(0): " << arr.at(0) << "\n";
    std::cout << "arr.data(): " << arr.data() << "\n";
    std::cout << "&arr: " << &arr << "\n";
    std::cout << "arr.front(): " << arr.front() << "\n";
    std::cout << "arr.back(): " << arr.back() << "\n";
    std::cout << "arr.pop_front(): ";
    arr.pop_front();
    print_array_view(arr);
    std::cout << "arr.pop_back(): ";
    arr.pop_back();
    print_array_view(arr);
    std::cout << "arr.reverse(): ";
    arr.reverse();
    print_array_view(arr);
    std::cout << "arr.slice(0, 3): ";
    auto temp = arr.slice(0, 3);
    print_array_view(temp);
    std::cout << "arr.assign(6): ";
    arr.assign(6);
    print_array_view(arr);

    try
    {
        std::cout << "arr.at(arr.size() - 1): " << arr.at(arr.size() - 1) << "\n";
        std::cout << "arr.at(arr.size()): " << arr.at(arr.size()) << "\n";
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

}


int main()
{
    test_0();

    return 0;
}