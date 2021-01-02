// Examples of iterator functions
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

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

    // iota can be used to generate sequential numbers from a starting point
    vector<int> iota_test(10);
    iota(begin(iota_test), end(iota_test), 0);
    for(auto i:iota_test){
        cout << i << " " << endl;
    }
    cout << endl;

    // However generate is much more useful. It can do what iota does:
    generate(begin(iota_test), end(iota_test), [j = 0]() mutable { return j++; });
    for(auto i:iota_test){
        cout << i << " " << endl;
    }
    cout << endl;

    // But it can also do so much more
    generate(begin(iota_test), end(iota_test), [j = 0]() mutable { return j+=2; });
    for(auto i:iota_test){
        cout << i << " " << endl;
    }
    cout << endl;

}