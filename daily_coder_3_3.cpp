#include <iostream>
#include <list>

using namespace std;

int main()
{
    list<int> l = {1, 2, 3, 4, 5};

    // Create an iterator to navigate the list
    //list<int>::iterator it = l.begin();
    auto it = l.begin();

    while(it != l.end()){
        // Operating on every other node...
        // If previous node's value is greater, swap previous and current
        // If next node's value is greater, swap current and next
        auto prev = it;
        auto current = ++it;
        auto next = ++it;

        // Check we didn't go out of bounds with the above!
        if(current == l.end() || next == l.end()) break;

        if(*prev > *current) iter_swap(current, prev);
        else if(*next > *current) iter_swap(current, next);
    }

    // Print it all out
    for(auto val:l) cout << val << endl;

}