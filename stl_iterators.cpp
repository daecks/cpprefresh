// Examples of iterator functions
#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
#include <array>

using namespace std;

int main(){

    cout << "'back_inserter' can be used to insert elements at the end of vector of unknown size" << endl;
    vector<int> v;
    fill_n(back_inserter(v), 5, 9);
    for(auto i:v) cout << i << " "; cout << endl;

    // An alternative way of using iota.  the [n = 0] is alias capture, where we don't need to define "n"
    // outside of the lambda beforehand
    cout << "Adding more elements with 'generate_n' and lambdas" << endl;
    generate_n(back_inserter(v), 5, [n=0]()mutable{return n++;});
    for(auto i:v) cout << i << " "; cout << endl;
    
    deque<int> w;
    cout << "'front_inserter' can be used with linked lists, like 'deque'" << endl;
    generate_n(front_inserter(w), 5, [n=0]()mutable{return n+=2;});
    for(auto i:w) cout << i << " "; cout << endl;

    cout << "Using 'back_inserter' allows us to copy unique elements from one vector to another" << endl;
    vector<int> v1 = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    cout << "Source vector contents:" << endl;
    for(auto i:v1) cout << i << " "; cout << endl;
    vector<int> v2;
    sort(begin(v1), end(v1));
    unique_copy(begin(v1), end(v1), back_inserter(v2));
    cout << "Destination vector contents (remember to sort the source first!):" << endl;
    for(auto i:v2) cout << i << " "; cout << endl;

    cout << "Easy way to reverse a string using 'reverse_copy' and 'back_inserter'" << endl;
    string mystring = "This is a normal string";
    string reversedstring;
    reverse_copy(begin(mystring), end(mystring), back_inserter(reversedstring));
    cout << "Original: " << mystring << " Reversed: " << reversedstring << endl;

    cout << "Reverse iterators start from the end, and incrementing them moves to one past the beginning!" << endl;
    vector<int> v3 = {1, 2, 3, 4, 5, 6, 7, 8, 3, 9, 10};
    cout << "Finding the three closest to the end of the array" << endl;
    auto lastthree = find (rbegin(v3), rend(v3), 3);
    auto distance = lastthree - rbegin(v3);
    cout << "The last value of three was " << distance << " elements from the end of the vector" << endl;

    cout << "Is the first value of three in the first half of the vector?" << endl;
    auto firstthree = find(begin(v3), end(v3), 3);
    bool firsthalf = (firstthree - begin(v3)) < (end(v3) - firstthree);
    cout << firsthalf << endl;
    
    cout << "You can have an array of constants (not a vector of constants... \nthis doesn't make sense if you think about how vectors are resized)" << endl;
    array<const int, 5> const_array {1, 3, 4, 7, 11};
    cout << "And you can get an iterator to the start of the array. You can move the iterator along,\nand dereference it to get the value, but you can't assign a new value" << endl;
    auto const_iterator = begin(const_array);
    cout << *(const_iterator+3) << endl;

}