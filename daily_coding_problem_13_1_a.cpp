#include <iostream>
#include <unordered_map>
#include "timefunc.h"

int staircase(int total_stairs, std::unordered_map<int, int> &cache){

    if(cache.count(total_stairs) > 0){
        return cache[total_stairs];
    }

    if(total_stairs < 0) return 0;
    if(total_stairs == 0) return 1;

    cache[total_stairs] = staircase(total_stairs - 1, cache) + staircase(total_stairs - 2, cache);
    return cache[total_stairs];
}

int main(){

    std::unordered_map<int, int> cache;
    std::cout <<  "Total number of permutations: " <<  staircase(5, cache) << '\n';
    // Should be 5 permutations:
    // 1, 1, 1, 1
    // 1, 1, 2
    // 1, 2, 1
    // 2, 1, 1 
    // 2, 2

}