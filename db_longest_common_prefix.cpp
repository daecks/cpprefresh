// Find the longest common prefix among a vector of strings

#include <string>
#include <vector>
#include <cassert>
#include <iostream>


using namespace std;

string longest_common_prefix(vector<string> strings_list){

// The algorithm: use the first string as your baseline string
// foreach character in that string, check if ther other strings 
// have matching characters in that position.
    int index = 0;
    string retval;
    for(auto &current_char:strings_list[0]){
        for(int i = 1; i < strings_list.size(); i++){ // start index 1 because we get chars from string at index 0
            if(index > strings_list[i].size() || current_char != strings_list[i][index]){
                return retval;
            }
        }

        retval += current_char;
        index++;
    }

    return retval;

}

int main(){

    assert(longest_common_prefix({"them", "the", "that"}) == "th");
    assert(longest_common_prefix({"what the heck", "no way", "crazy"}) == "");

}