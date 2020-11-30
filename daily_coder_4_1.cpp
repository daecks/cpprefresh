// Exercise 4.1 Implement a max stack

#include <iostream>
#include <stack>
#include <algorithm>
#include <exception>

class maxstack{
    private:
    std::stack<int> stack;
    std::stack<int> mstack;

    public:
    maxstack(){};
    void push(int val){
        stack.push(val);
        if(mstack.empty()){
            mstack.push(val);
        }else{
            mstack.push(std::max(val, mstack.top()));
        }
    }

    int pop(){
        mstack.pop();
        int val = stack.top();
        stack.pop();
        return val;
    }

    int max(){
        if(mstack.empty()){
            throw 8; // my custom exception
        }
        return mstack.top();
    }
};


int main(){

    maxstack thestack;
    thestack.push(1);
    thestack.push(3);
    thestack.push(2);
    thestack.push(42);
    thestack.push(19);

    std::cout << "Max element is: " << thestack.max() << std::endl;
    std::cout << "Removing: " << thestack.pop() << std::endl;
    std::cout << "Removing: " << thestack.pop() << std::endl;
    std::cout << "Max element is: " << thestack.max() << std::endl;
    std::cout << "Removing: " << thestack.pop() << std::endl;
    std::cout << "Removing: " << thestack.pop() << std::endl;
    std::cout << "Removing: " << thestack.pop() << std::endl;
    try
    {
        std::cout << "Max element is: " << thestack.max() << std::endl;
    }
    catch (int e)
    { // catch any exception with ellipses
        std::cout << "Caught an exception: " << e << std::endl;
    }
}