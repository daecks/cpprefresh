// Ignore case and non-alphabetical characters,
// is the word a valid palindrome?

#include <iostream>
#include <algorithm>
#include <cassert>
#include <cctype>

bool is_valid_palindrome(std::string thestring){
    bool is_valid_palindrome;

    int stringlength = thestring.length();
    for(int start=0, end=stringlength - 1; start < end; start++, end--){

        // Advance start/end counters to a valid character
        while(!isalpha(thestring[start])){ start ++;};
        while(!isalpha(thestring[end])){ end --; };

        if(tolower(thestring[start]) != tolower(thestring[end])){
            return false;
        }

    }

    return true;
}

int main(){
    
    // Basic tests
    assert(is_valid_palindrome("hannah") == true); // even number of chars
    assert(is_valid_palindrome("rannah") == false); // should be false
    assert(is_valid_palindrome("level") == true); // odd number of chars 

    // Handle uppercase
    assert(is_valid_palindrome("Hannah") == true);
    assert(is_valid_palindrome("HanNaH") == true);

    // Handle non-alpha characters
    assert(is_valid_palindrome("..Hannah$") == true);
    assert(is_valid_palindrome("..H ann ah$") == true);


}