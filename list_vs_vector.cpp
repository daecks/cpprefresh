// If using ranged for loops, lists and vectors should be 
// interchangeable. Note that accessing a container with square brackets
// is not supported for a list.

#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(){

    list<int> test = {1,2,3,4,5,6,7};  // or can be a vector

    for(auto i:test){
        cout << i << endl;
    }

    return 0;
}