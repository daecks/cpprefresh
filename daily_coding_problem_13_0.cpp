#include <iostream>
#include <unordered_map>
#include "timefunc.h"

int coin_ways(int cent_total){

    if(cent_total < 0) return 0;
    if(cent_total == 0) return 1;

    return(coin_ways(cent_total - 1) + coin_ways(cent_total - 5));
}

int coin_ways_cached(int cent_total, std::unordered_map<int, int> &cache){

    if(cache.count(cent_total) > 0){ // C++20 has a 'contains' https://en.cppreference.com/w/cpp/container/map/contains
        return cache[cent_total];
    }

    if(cent_total < 0) return 0;
    if(cent_total == 0) return 1;

    cache[cent_total] = coin_ways_cached(cent_total - 1, cache) + coin_ways_cached(cent_total - 5, cache);
    return cache[cent_total];
}

int main(){

    int coins_result;
    auto microseconds = TimeFunc([&](){ coins_result = coin_ways(70); });
    std::cout << "Uncached impl result: " << coins_result << " took time (millis): " << microseconds << '\n';
 
    std::unordered_map<int, int> cache;
    microseconds = TimeFunc([&](){ coins_result = coin_ways_cached(70, cache); });
    std::cout << "Cached impl result: " << coins_result << " took time (millis): " << microseconds << '\n';

}