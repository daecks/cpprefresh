// Given an array of integers, all values occur three times except for one.
// Find the integer that does not occur three times.
#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

int find_unique(vector<int> integer_list){

    vector<int> bit_count(32);
    for(auto &current_int:integer_list){
        for(int i=0; i<32; i++){
            if(current_int & (1 << i)) bit_count[i]++;
        }
    }

    int unique_int = 0;
    for(int i=0; i<32; i++){
        if(bit_count[i] % 3 !=0){ 
            unique_int += (1 << i);
        }
    }
    return unique_int;
}

int main(){
    assert(find_unique({1,2,3,3,3,2,2}) == 1);
    assert(find_unique({10,20,13,13,13,20,20}) == 10);
}