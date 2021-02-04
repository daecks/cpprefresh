// Given a string, find the position of the first unique character

#include <iostream>
#include <string>
#include <unordered_map>
#include <cassert>

int get_location_first_unique(std::string thestring){

    // First populate an unordered map to count occurrences of characters
    std::unordered_map<char, int> char_frequency;
    for(int i = 0; i<thestring.size(); i++){
        char_frequency[thestring[i]]++;
    }

    for(int i = 0; i<thestring.size(); i++){
        if(char_frequency[thestring[i]] == 1){
            return i;
        }
    }

    return -1;
    
}

int main(){

    std::cout << get_location_first_unique("thisist") << std::endl;
    std::cout << get_location_first_unique("ththth") << std::endl;

}

