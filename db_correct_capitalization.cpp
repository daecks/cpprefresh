// Check if correct capitalization is used, which is a string containing:
// 1 - All capitals
// 2 - A capital as the first letter
// 3 - no capitals

#include <cassert>
#include <string>
#include <cctype>

bool is_correct_capitalization(std::string str){
    int uppercase_count = 0;
    bool all_uppercase = true;
    bool start_capitalized = isupper(str[0]);

    for(int i=0; i<str.length(); i++){
        if(isupper(str[i])) {
            uppercase_count++;
        }
    }

    if(start_capitalized){
        if(uppercase_count == str.length()) return true;
        else return false;
    }else{
        if(uppercase_count > 0) return false;
    }
    return true;
}


int main(){

    assert(is_correct_capitalization("WTF") == true);
    assert(is_correct_capitalization("WTf") == false);
    assert(is_correct_capitalization("wtf") == true);
    assert(is_correct_capitalization("wtF") == false);

}