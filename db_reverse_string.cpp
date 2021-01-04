#include <iostream>
#include <algorithm>

std::string reverse_string(std::string thestring){
    int stringlength = thestring.length();
    for(int i=0; i<stringlength/2; i++){
        std::swap(thestring[i], thestring[stringlength - 1 - i]);
    }

    return thestring;
}

std::string reverse_string_oldschool(std::string thestring){
    int stringlength = thestring.length();
    for(int i=0; i<stringlength/2; i++){
        char tmp = thestring[i];
        thestring[i] = thestring[stringlength - 1 - i];
        thestring[stringlength - 1 -i ] = tmp;
    }

    return thestring;
}

int main(){

    // Method 1
    std::cout << reverse_string("This is reversed") << std::endl;

    // Method 2
    std::string str("This is reversed");
    std::reverse(begin(str), end(str));
    std::cout << str << std::endl;

    // Method 3
    std::cout << reverse_string_oldschool("This is reversed") << std::endl;

}