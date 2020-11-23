#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    vector<int> v{ 1, 7, 1, 6, 2, -2, 4, 0, 42, 83, 2, 1, -1, 2, 21, 5, 5, -7};
    string s{ "Wow this is like really cool!"};

    // find the first 1 in the collection
    auto result = find(begin(v), end(v), 1);

    // check if we found "1" in the vector
    if(result != end(v)){
        cout << "we found a value of " << *result << endl;
    }

    // Use the iterator returned from the first search to find another value *after*
    auto result2 = find(result, end(v), 42);

    // Check if we found the magic number
    if(result2 != end(v)){
        cout << "we found a value of " << *result2 << endl;
    }

    // find the first occurrence from a list of numbers
    vector<int> partfibs{ 3, 5, 8, 13, 21};
    result = find_first_of(begin(v), end(v), begin(partfibs), end(partfibs));
    cout << "We found this number from the partial fibs in the vector: " << *result << endl;

}