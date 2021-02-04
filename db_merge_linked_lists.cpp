#include <iostream>
#include <list>
#include <cassert>

std::list<int> merge_lists(const std::list<int> &one, const std::list<int> &two){

    std::list<int> merged_list;

    auto one_it = begin(one);
    auto two_it = begin(two);

    while(one_it != end(one) || two_it != end(two)){
        if(one_it != end(one) && *one_it < *two_it){
            merged_list.push_back(*one_it);
            one_it++;
        }else if(two_it != end(two)){
            merged_list.push_back(*two_it);
            two_it++;
        }
    }

    return merged_list;
}

int main(){

    std::list<int> result = {1, 2, 3, 4, 5, 6};

    assert( result == merge_lists({1, 2, 3}, {4, 5, 6}));

    assert( result == merge_lists({1, 3, 5}, {2, 4, 6}));

    assert( result == merge_lists({1, 3}, {2, 4, 5, 6}));
}