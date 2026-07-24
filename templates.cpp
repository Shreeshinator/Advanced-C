// Templates demo in C++
#include <iostream>

template <typename type>
void Print(type value) {
    std::cout << value << std::endl;
}

int main() {
    Print(42);          // Calls Print<int>
    Print(3.14);       // Calls Print<double>
    Print("Hello");    // Calls Print<const char*>
    Print<std::string>("World"); // Calls Print<std::string>
    return 0;
}