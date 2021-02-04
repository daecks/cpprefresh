// Find a common set of numbers between two lists of numbers

#include <unordered_set>
#include <vector>
#include <iostream>

std::unordered_set<int> find_common_set(std::vector<int> left, std::vector<int> right){

    std::unordered_set<int> common_set;
    std::unordered_set<int> left_set;

    for(int i = 0; i < left.size(); i++){
        left_set.insert(left[i]);
    }

    for(int i = 0; i < right.size(); i++){
        if(left_set.count(right[i]) > 0) common_set.insert(right[i]);
    }

    return common_set;
}

int main(){
    std::vector<int> one = {1,2,3,4,5};
    std::vector<int> two = {1,2,3,4,5};

    std::unordered_set<int> returned;

    returned = find_common_set({1,2,3,4,5}, {1,2,4,4,5});

    for(const auto &i:returned){
        std::cout << i << " ";
    }
    std::cout << std::endl;

}