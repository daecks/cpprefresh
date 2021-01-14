#include <iostream>
#include <vector>
#include <cassert>
#include <unordered_set>

using namespace std;

bool two_sum(vector<int> num_array, int target){

    for(int i=0; i<num_array.size(); i++){
        for(int j=i+1; j<num_array.size(); j++){
            if(num_array[i] + num_array[j] == target) return true;
        }
    }

    return false;
}

bool two_sum_fast(vector<int> num_array, int target){

    unordered_set<int> seen_numbers;
    int difference;

    for(int i=0; i<num_array.size(); i++){
        difference = target - num_array[i];

        if(seen_numbers.find(difference) != seen_numbers.end()) return true;

        seen_numbers.insert(num_array[i]);
    }

    return false;
}

int main(){

    assert(two_sum({1,2,3,4}, 2) == false);
    assert(two_sum({1,2,3,4}, 7) == true);
    assert(two_sum({4, 2, 6, 5, 2}, 4) == true);
    
    assert(two_sum_fast({4, 2, 6, 5, 2}, 4) == true);

}