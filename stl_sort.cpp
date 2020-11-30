#include <algorithm>
#include <vector>
#include <iostream>
#include <map>
#include <random>

using namespace std;

class Game{
    public:
        Game(string name, int year, int score) :
        gamename(name), gameyear(year), gamescore(score){}

    string getName(){
        return gamename;
    };
    int getYear(){
        return gameyear;
    };
    int getScore(){
        return gamescore;
    };

    private:
    string gamename;
    int gameyear;
    int gamescore;
};

int main()
{
    vector<int> v{ 2, 7, 1, 6, 2, -2, 4, 0};

    // Standard sorting
    sort(begin(v), end(v));
    for (auto &num : v)
        cout << num << " ";
    cout << endl;

    // Custom sorting with a lambda - descending
    sort(begin(v), end(v), [](int elem1, int elem2){return elem1 > elem2;});
    for (auto &num : v)
        cout << num << " ";
    cout << endl;

    // I'm totally making these years up... I don't remember.
    vector<Game> gamelist{
        {"Kid Icarus", 1986, 10},
        {"Metroid", 1986, 10},
        {"Kung Fu", 1985, 8},
        {"Excitebike", 1985, 7},
        {"Super Mario", 1985, 10},
        {"Commando", 1985, 6},
    };

    sort(begin(gamelist), end(gamelist), [](Game g1, Game g2){return g1.getScore() < g2.getScore();});
    cout << endl;
    for (auto &elem : gamelist)
    {
        cout << elem.getName() << " " << elem.getYear() << " " << elem.getScore();
        cout << endl;
    }
    // Stable sort - resolve any ties if they exist on a partially sorted collection.
    // it will only sort according to the lambda condition you specify. In my example,
    // I want to further sort with incrementing year.
    stable_sort(begin(gamelist), end(gamelist), [](Game g1, Game g2){return g1.getYear() < g2.getYear();});
    cout << endl;
    for (auto &elem : gamelist)
    {
        cout << elem.getName() << " " << elem.getYear() << " " << elem.getScore();
        cout << endl;
    }

    // now to check if our collection is actually sorted, according to our predicate
    cout << "Is it sorted by name? " << is_sorted(begin(gamelist), end(gamelist), [](Game g1, Game g2) { return g1.getName() < g2.getName(); }) << endl;
    cout << "Is it sorted by year? " << is_sorted(begin(gamelist), end(gamelist), [](Game g1, Game g2) { return g1.getYear() < g2.getYear(); }) << endl;

    // finding the max and min elements of a sorted collection
    int max_elem = *(max_element(begin(v), end(v)));
    int min_elem = *(min_element(begin(v), end(v)));

    cout << "Max and min are " << max_elem << " and " << min_elem << " respectively" << endl;

    // How about shuffling the collection? Use the random generator - Mersenne Twister to be precise
    // and shuffle and existing vector.

    random_device randomdevice;
    mt19937 generator(randomdevice());
    shuffle(begin(v), end(v), generator);
    for(auto &elem:v) cout << elem << endl; 

    // Partial sort will sort till the specified location, with elements after
    // unsorted - but all larger than the sorted elements.
    // Partial sort has three params - start and end are first and last params.
    // Middle param is an iterator to stop at... you can use find() for this.
    partial_sort(begin(v), find(begin(v), end(v), 1), end(v));
    cout << "after a partial sort" << endl;
    for(auto &elem:v) cout << elem << endl; 

    // Partial sort copy will only sort the number of items that will be 
    // copied into the vecot you specify
    vector<int> psc(3);
    partial_sort_copy(begin(v), end(v), begin(psc), end(psc));
    cout << "Smallest three elems in vector found by partial_sort_copy" << endl;
    for(auto &elem:psc) cout << elem << endl; 

    // Nth element can be used to find the value at a position should the array
    // had been sorted. Array won't actually be completely sorted - but smaller numbers
    // will be to the left, and larger to the right. Could use this to find median
    // if size_vector/2 is used!
    vector<int> nth_test = {0, -2, -3, 4, 5, 6, 9, 2, 3, 4, 10};
    int median = nth_test.size()/2;
    nth_element(begin(nth_test), begin(nth_test) + median, end(nth_test));
    median = *(begin(nth_test) + median);
    cout << "Median is:" << median << endl;


}