#include <iostream>
#include <string>

template<int N, typename T>
class Array
{
private:
    T m_Array[N];

public:
int getSize() const { return N; }
};

int main()
{
    Array<5, int> arr1;  // Creates an array of size 5
    Array<10, int> arr2; // Creates an array of size 10
    return 0;
}