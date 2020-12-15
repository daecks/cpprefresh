// Finds the distance between two words in a string.
// The words may be jumbled
// Return distance or -1 if two words don't exist

#include <list>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int word_distance(string jumbledstring, string word){

    list<char> firstword, secondword;

    // Convert word to list of characters to iterate through
    for(auto &c:word){
        firstword.push_back(c);
    }

    // Make a copy - one for coming from the left, 
    // another for coming from the right.
    secondword = firstword;

    auto left = begin(jumbledstring);
    for(left; left != end(jumbledstring); left++){
        // Remove only one instance of a letter by finding its location
        // and then erasing it. Continue until we've found all letters.
        auto location = find(begin(firstword), end(firstword), *left);
        if(location != end(firstword)) firstword.erase(location);
        if(firstword.empty()) break;
    }

    auto right = end(jumbledstring)-1;
    for(right; right != begin(jumbledstring); right--){
        // Same logic as for coming from the left, except we begin at the end.
        auto location = find(begin(secondword), end(secondword), *right);
        if(location != end(secondword)) secondword.erase(location);
        if(secondword.empty()) break;
    }

    return (right - left - 1);
}

int main(){
    cout << word_distance("pgrorammerddddpddrogmerram", "programmer") << endl;
}
