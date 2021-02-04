#include <iostream>
#include <string>
#include <cassert>
#include <stack>

bool is_string_same(std::string s, std::string t){

    std::stack<char> left_stack;
    for(auto &character:s){
        if(character != '#') {
            left_stack.push(character);
        }else if(!left_stack.empty()){
            left_stack.pop();
        }
    }

    std::stack<char> right_stack;
    for(auto &character:t){
        if(character != '#') {
            right_stack.push(character);
        }else if(!right_stack.empty()){
            right_stack.pop();
        }
    }

    if(left_stack.size() != right_stack.size()) return false;

    while(!left_stack.empty()){
        if(left_stack.top() != right_stack.top()) return false;
        left_stack.pop();
        right_stack.pop();
    }

    return true;
}

int main(){

    assert(true == is_string_same("#B", "B"));
    assert(true == is_string_same("AB#", "A"));
    assert(true == is_string_same("CD##AB", "AB"));
    assert(true == is_string_same("como#pur#ter", "computer"));
    assert(false == is_string_same("cof#dim#ng", "code"));

}