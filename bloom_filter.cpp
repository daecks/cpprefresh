// A bloom filter is used to give probabalistic results of whether a
// value exists in a data set. The structure of a bloom filter is a 
// bit map. As data is added, it is hashed and that hash is modded with 
// the size of the bit map to determine which bit in the map to set.
// Note that because different values could result in the same bit being set,
// false positives may occur. However, if the query of a value results in a bit
// not being set, we know for sure that value does not exist. 
// A good reference: https://www.interviewcake.com/concept/java/bloom-filter 

#include <iostream>
#include <string>
#include <functional>

using namespace std;

class BloomFilter{
    private:
    unsigned int bitmap = 0;
    const int bitmap_num_bits = sizeof(unsigned int) * 8;
    void printBitmap(void);

    public:
    BloomFilter(){}
    void add(string value);
    bool check(string value);
};

void BloomFilter::add(string value){
    size_t str_hash = hash<string>{}(value);
    bitmap |= (1 << (str_hash % bitmap_num_bits));
    printBitmap();
};

bool BloomFilter::check(string value){
    cout << "Checking for value " << value << ": ";
    size_t str_hash = hash<string>{}(value);
    return(bitmap & (1 << (str_hash % bitmap_num_bits)));
}

void BloomFilter::printBitmap(){
    cout << "Current bitmap contents: ";
    for(auto i=0; i<bitmap_num_bits; i++){
        auto each_bit = (bitmap & (1 << i))==0?"0":"1";
        cout << each_bit;
    }
    cout << endl;
}

int main(){
    BloomFilter bf;

    bf.add("milton");
    bf.add("cyril");

    cout << bf.check("milton") << endl;
    cout << bf.check("cyril") << endl;
    cout << bf.check("kristian") << endl;
}