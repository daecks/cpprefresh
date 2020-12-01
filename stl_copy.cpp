#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <random>

using namespace std;

int main()
{
    vector<int> source{ 1, 2, 3, 6, 5, 10, 4, 60};
    vector<int> destination(source.size());
    // This is the long way!
    copy(begin(source), end(source), begin(destination));

    // A much faster way of copying the whole collection
    vector<int> fastdest = source;

    // only copy elements if a precondition is met
    vector<int> copyifdemo(source.size());
    copy_if(begin(source), end(source), begin(copyifdemo), [](int elem) { return elem % 2 == 0; });

    for(auto i:source) cout << i << " ";
    cout << endl;

    for(auto i:copyifdemo) cout << i << " ";
    cout << endl;
}