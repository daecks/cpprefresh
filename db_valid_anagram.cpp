#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool is_anagram(string left, string right){

    unordered_map<char, int> charmap;

    if(left.length() != right.length()){
        return false;
    }

    // For the left string, create a map of characters 
    for(auto &c:left){
        charmap[c]++;
    }

    cout << charmap.size() << endl;
    return false;
}


int main(){
    is_anagram("This", "That");
    
    return 0;
}
