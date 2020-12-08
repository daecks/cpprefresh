// Examples of iterator functions
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){

    vector<int> v1 = {1, 2, 3, 4, 5, 6};

    cout << "It's a rotate. Everything is a rotate." << endl;
    cout << "Here is the vector that is to be rotated" << endl;
    for(auto i:v1) {cout << i << " ";} cout << endl;
    cout << "Now to move the number 5 to before 2" << endl;

    auto two = find(begin(v1), end(v1), 2);
    auto five = find(begin(v1), end(v1), 5);
    rotate(two, five, five+1);
    for(auto i:v1) {cout << i << " ";} cout << endl;


}