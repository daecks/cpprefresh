// Examples of type punning and general pointer manipulation
#include <iostream>

struct Example{
    int a, b, c;
    float d, e;
};

int main(){

    Example e = {1, 2, 3, 1.0, 2.0};

    // Get at what offset a variable is
    int offset_a = (long)&((Example*)nullptr)->a;
    std::cout << "Offset of a is: " << offset_a << std::endl;

    int offset_c = (long)&((Example*)nullptr)->c;
    std::cout << "Offset of c is: " << offset_c  << std::endl;
    
    std::cout << "Offset of c is: " << offsetof(Example, c) << std::endl;

    // Type punning: re-interpret data at a location
    // In this case, get the value of b
    int value_at_offset = *(int*)((char*)&e + 4);
    std::cout << "Value at offset is : " << value_at_offset << std::endl;

    // Re-interpret as array
    int* position = (int*)&e;
    std::cout << "Contents at position 0: " << position[0] << ", position 1: " << position[1] << std::endl;



}