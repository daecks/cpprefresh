#include <iostream>
#include <stack>
#include <cassert>

bool is_order_valid(std::string characters){

    std::stack<char> character_stack;
    
    for(auto &character:characters){
        switch(character){
            case '[':
            case '{':
            case '(':
                character_stack.push(character);
            break;

            case ']':
                if(character_stack.top() == '[') character_stack.pop();
                break;
            case '}':
                if(character_stack.top() == '{') character_stack.pop();
                break;
            case ')':
                if(character_stack.top() == '(') character_stack.pop();
                break;
        }
    }

    if(character_stack.empty()) return true;

    return false;
}

int main(){

    assert(true == is_order_valid("()"));
    assert(true == is_order_valid("[]"));
    assert(true == is_order_valid("{}"));
    assert(false == is_order_valid("(]"));
    assert(false == is_order_valid("[}"));
    assert(false == is_order_valid("{)"));
    assert(true == is_order_valid("()[]{}"));
    assert(true == is_order_valid("([]{})"));

}
