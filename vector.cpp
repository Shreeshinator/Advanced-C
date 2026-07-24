// Vectors demo in C++

#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
    float x, y, z;
};

std::ostream& operator<<(std::ostream& os, const Vertex& v)
{
    os << "Vertex(" << v.x << ", " << v.y << ", " << v.z << ")";
    return os;
}

int main(void)
{
   std::vector<Vertex> vertices;
   vertices.reserve(10); // reserve space for 10 vertices
   vertices.push_back({1.0f, 2.0f, 3.0f});
   vertices.push_back({4.0f, 5.0f, 6.0f});
   vertices.emplace_back(7.0f, 8.0f, 9.0f); // construct in place
   for (const auto& v : vertices) // for each vertex in the vector
   {
       std::cout << v << std::endl;
   }
   // All uses of static keyword in C++:
   /*
   1. Static local variables: Variables that retain their value between function calls.
   2. Static global variables: Variables that are only accessible within the file they are declared in.
   3. Static member variables: Variables that belong to the class rather than any specific object of the class.
   4. Static member functions: Functions that belong to the class rather than any specific object of the class.
   implementation of all four listed above:
   1. Static local variable example:
    void counter() {
        static int count = 0; // retains its value between calls
        count++;
        std::cout << "Count: " << count << std::endl;
    }
   2. Static global variable example:
    static int globalCount = 0; // only accessible within this file
    void incrementGlobalCount() {
        globalCount++;
        std::cout << "Global Count: " << globalCount << std::endl;
    }
   3. Static member variable example:
    class MyClass {
    public:
        static int staticMember; // belongs to the class, not any object
    };
    int MyClass::staticMember = 0; // definition of static member variable
   4. Static member function example:
    class MyClass {
    public:
        static void staticFunction() { // belongs to the class, not any object
            std::cout << "This is a static member function." << std::endl;
        }   
   */
}