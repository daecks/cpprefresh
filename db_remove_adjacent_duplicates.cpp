#include <iostream>
#include <cassert>
#include <stack>
#include <string>

std::string remove_adjacent_duplicates(std::string the_string){
    std::stack<char> stack;
    for(auto &character:the_string){
        if(!stack.empty() && character == stack.top()) {
            stack.pop();
        }else{ 
            stack.push(character);
        }
    }
    
    std::string retval;
    while(!stack.empty()){
        retval = stack.top() + retval;
        stack.pop();
    }
    return retval;
}

int main(){
    assert("" == remove_adjacent_duplicates("abccba"));
    assert("fbar" == remove_adjacent_duplicates("foobar"));
    assert("a" == remove_adjacent_duplicates("abccbefggfe"));
}