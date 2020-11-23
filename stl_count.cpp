#include <algorithm>
#include <vector>
#include <iostream>
#include <map>

using namespace std;

int main()
{
    vector<int> v{ 2, 7, 1, 6, 2, -2, 4, 0};

    const int the_target = 2;

    int twos = count(begin(v), end(v), the_target);

    cout << "count vector example, twos = " << twos << endl;

    int odds = count_if(begin(v), end(v), 
    [](auto elem) {return elem %2 != 0;});

    cout << "count_if vector example, odds =  " << odds << endl;

    map<int, int> monthlengths
    {
        {1, 31},
        {2, 28},
        {3, 31},
        {4, 30},
        {5, 31},
        {6, 30},
        {7, 31},
        {8, 31},
        {9, 30},
        {10, 31},
        {11, 30},
        {12, 31}
    };

    int longmonths = count_if(begin(monthlengths), end(monthlengths), [](auto elem){return elem.second == 31;});

    cout << "count_if map example, longmonths = " << longmonths << endl;

    bool allareodd = all_of(begin(v), end(v), [](auto elem) { return elem % 2 != 0;});
    bool anyareodd = any_of(begin(v), end(v), [](auto elem) { return elem % 2 != 0;});
    bool noneareodd = none_of(begin(v), end(v), [](auto elem) { return elem % 2 != 0;});

    cout << "all_of vector example - are all values odd? " << allareodd << endl;
    cout << "any_of vector example - are any values odd? " << anyareodd << endl;
    cout << "none_of vector example - are no values odd? " << noneareodd << endl;
}