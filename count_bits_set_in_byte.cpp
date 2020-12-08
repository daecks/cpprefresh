// Count bits set in a byte
#include <iostream>

using namespace std;

int get_set_bits(unsigned short test){
    int set_bits = 0;
    for (int i = 0; i < 8; i++)
    {
        if ((1 << i) & test)
            set_bits++;
    }
    return set_bits;
}

int main(){
    cout << get_set_bits(5) << endl;
    cout << get_set_bits(11) << endl;
    cout << get_set_bits(1) << endl;
    cout << get_set_bits(0) << endl;
}