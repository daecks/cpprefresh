#include <iostream>

int addone(int i){
    if(i>5) return i;
    i++; // cannot do this on the line below
    return addone(i);
}

int main(){
    std::cout << addone(0) << std::endl;
}