#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <random>

using namespace std;

int main()
{
    // Using 'equal' to test for equality
    vector<int> v{ 1, 2, 3, 6, 5, 10, 4, 60};
    vector<int> w = v;
    bool same = equal(begin(v), end(v), begin(w), end(w));
    cout << "Are they the same? " << same << endl;
    sort(begin(w), end(w));
    same = equal(begin(v), end(v), begin(w), end(w));
    cout << "Are they the same if one is sorted? " << same << endl;

    // Let's find where the arrays diverge with 'mismatch'
    auto firstmismatch = mismatch(begin(v), end(v), begin(w));
    cout << "Value in first vector when mismatch occurred: " << *firstmismatch.first << endl;
    cout << "Value in second vector when mismatch occurred: " << *firstmismatch.second << endl;
    cout << "Length of run before mismatch: " << firstmismatch.first - begin(v) << endl;

    // Accumulate, only counting even numbers
    int thesum = accumulate(begin(v), end(v), 0, [](int i, int total){if(i%2 == 0) return total + i ; return total;});
    cout << "Sum of all even numbers: " << thesum << endl;
    
    // For_each is like a ranged for, but can be used over part of a collection (not whole, as is implied by ranged-for loops)
    // This will set the elements after the first "3", and set them to zero (hence, pass by reference) 
    auto findfirstthree = find(begin(v), end(v), 3);
    for_each(findfirstthree, end(v), [](int& elem){ elem = 0; });

    for(auto i:v){
        cout << i << " ";
    }
    cout << endl;

}