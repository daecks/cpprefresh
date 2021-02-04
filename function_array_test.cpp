// A precursor method to how I plan to split up 6502 opcodes
// Notes:
// https://stackoverflow.com/questions/7477310/why-cant-i-create-a-vector-of-lambdas-of-the-same-type-in-c11

#include <iostream>
#include <array>
#include <functional>

void add4(int &a){
    a+=4;
}

int main(){

    int a;

    auto add1 = [](int &a){ ++a; };
    auto subtract1 = [](int &a){ --a; };
    auto add2 = [](int &a){ a+=2; };
    auto subtract3 = [](int &a){ a-=3; };

    std::array<std::function<void(int &)>, 5> function_array = { 
        add1, 
        subtract1, 
        add2, 
        subtract3,
        add4
    };

    int test_number = 0;
    for(int i = 0; i < function_array.size(); i++){
        function_array[i](test_number);
        std::cout << test_number << std::endl;
    }
   

}