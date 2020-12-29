#include <iostream>
#include <unordered_map>
#include "timefunc.h"
#include <vector>
#include <algorithm>

int staircase(int remaining_stairs, std::unordered_map<int, int> &cache){

    if(cache.count(remaining_stairs) > 0){
        return cache[remaining_stairs];
    }

    if(remaining_stairs < 0) return 0;
    if(remaining_stairs == 0) return 1;

    cache[remaining_stairs] = staircase(remaining_stairs - 1, cache) + staircase(remaining_stairs - 2, cache);
    return cache[remaining_stairs];
}

int staircase_permutations(int remaining_stairs, std::unordered_map<int, int> &cache, std::vector<int> &allowed_step_sizes){

    if(cache.count(remaining_stairs) > 0){
        return cache[remaining_stairs];
    }

    if(remaining_stairs < 0) return 0;
    if(remaining_stairs == 0) return 1;

    int sum = 0;
    for(auto i:allowed_step_sizes){
        sum += staircase_permutations(remaining_stairs - i, cache, allowed_step_sizes);
    }
    // replaces old version below
    //cache[total_stairs] = staircase(total_stairs - 1, cache) + staircase(total_stairs - 2, cache);
    cache[remaining_stairs] = sum;
    return cache[remaining_stairs];
}

int main(){

    std::unordered_map<int, int> cache;
    std::cout <<  "Total number of permutations: " <<  staircase(4, cache) << '\n';

  
    std::unordered_map<int, int> new_cache;
    std::vector<int> steps_allowed{1,2};
    std::cout <<  "Total number of permutations with adjustable steps allowed: " <<  staircase_permutations(4, new_cache, steps_allowed) << '\n';
}