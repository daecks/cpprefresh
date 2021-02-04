// Use the arrow operator to give us the offset 
// of a variable in a stucture
#include <iostream>

struct OffsetTest{
    int a,b,c;
};

int main(){

    int offset_a = (long)&((OffsetTest*)0)->a;
    int offset_b = (long)&((OffsetTest*)0)->b;
    int offset_c = (long)&((OffsetTest*)0)->c;
    std::cout << offset_a << ", " << offset_b << ", " << offset_c << std::endl;

}

