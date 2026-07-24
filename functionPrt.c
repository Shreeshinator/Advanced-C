// function pointer example in C

#include <stdio.h>
// Define a function that takes an integer and returns its square
int square(int x) {
    return x * x;
}

int main() {
    // Declare a function pointer that points to a function taking an int and returning an int
    int (*funcPtr)(int) = square;
    // Syntax: return_type (*pointer_name)(parameter_types) = function_name;

    // Use the function pointer to call the square function
    int number = 5;
    int result = funcPtr(number);

    printf("The square of %d is %d\n", number, result);
    return 0;
}