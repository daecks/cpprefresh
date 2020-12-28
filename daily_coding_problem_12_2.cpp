#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool matches_first_char(string string_to_match, string regex){

    return( (string_to_match[0] == regex[0]) || 
        (regex[0] == '.' && string_to_match.size() > 0) );

}

bool matches(string string_to_match, string regex){

    // Empty regex matches empty string 
    if(regex == "") return (string_to_match == "");

    // If regex is a single character or second character is not an asterisk 
    if( (regex.size() == 1) || (regex[1] != '*') ){
        if(matches_first_char(string_to_match, regex)){
            return( matches( string_to_match.substr(1), regex.substr(1) ) );
        }else{
             return false;
        }
    }else{
        // Handle the case where the first character of the regex is succeeded by an asterisk
        if( matches(string_to_match, regex.substr(2))) return true;
        
        // Handle more cases where the regex may continue to match, up until it doesn't or
        // we hit an asterisk
        int i = 0;
        while(matches_first_char(string_to_match.substr(i), regex)){
            if(matches(string_to_match.substr(i+1), regex.substr(2))) return true;
            i++;
        }

    }

    
    return false;

}

int main(){

    // Simple cases of same length and . character
    cout << (matches_first_char("test", "test") == true) << endl;
    cout << (matches_first_char("test", "rest") == false) << endl;
    cout << (matches_first_char("test", ".est") == true) << endl;

    cout << (matches("", "") == true) << endl;
    cout << (matches("nope", "") == false) << endl;

    cout << (matches("nope", "no") == false) << endl;

    cout << (matches("bird", "b.*") == true) << endl;
    cout << (matches("bird", "bi.*") == true) << endl;
    cout << (matches("bird", "bir.*") == true) << endl;
    cout << (matches("bird", "bird.*") == true) << endl;
    cout << (matches("brid", "bird.*") == false) << endl;

}