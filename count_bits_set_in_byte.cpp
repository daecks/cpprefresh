// Count bits set in a passed-in value 
#include <iostream>

template <typename T>
size_t get_set_bits(T test){
   auto set_bits = 0;
    
   for (int i = 0; i < sizeof(T); i++)
    {
        if ((1 << i) & test)
            set_bits++;
    }
    return set_bits;
}

int main(){
    std::cout << get_set_bits(5) << std::endl;
    std::cout << get_set_bits(12) << std::endl;
    std::cout << get_set_bits(1) << std::endl;
    std::cout << get_set_bits(0) << std::endl;
}