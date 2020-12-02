#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    vector<int> source{ 1, 2, 3, 6, 5, 10, 4, 60};
    vector<int> destination(source.size());
    // This is the long way!
    copy(begin(source), end(source), begin(destination));

    // A much faster way of copying the whole collection
    vector<int> fastest = source;

    // only copy elements if a precondition is met, in this case, they are even.
    vector<int> copyifdemo(source.size());
    copy_if(begin(source), end(source), begin(copyifdemo), [](int elem) { return elem % 2 == 0; });

    cout << "The original vector 'source'" << endl;
    for(auto i:source) cout << i << " "; cout << endl;

    cout << "A copied vector, copying only if elements are even" << endl;
    for(auto i:copyifdemo) cout << i << " "; cout << endl;

    cout << "Remove all elements of value \"4\" from 'source'" << endl;
    auto removed4 = remove(begin(source), end(source), 4);

    cout << "Elements are removed, but vector size remains the same (last element duplicated)" << endl;
    for(auto i:source) cout << i << " "; cout << endl;
    
    cout << "The method erase will remove dangling elements" << endl;
    source.erase(removed4, end(source));
    for(auto i:source) cout << i << " "; cout << endl;

    cout << "Removing 3 from 'source', in one line" << endl;
    source.erase(remove(begin(source), end(source), 3), end(source));
    for(auto i:source) cout << i << " "; cout << endl;

    // big fat note: destruction doesn't necessarily occur upon remove.
    // it will occur on erase.

    vector<int> demo(10);
    cout << "Default for vectors is zero" << endl;
    for(auto i:demo) cout << i << " "; cout << endl;

    cout << "'fill' populates with specified value" << endl;
    fill(begin(demo), end(demo), 8);
    for(auto i:demo) cout << i << " "; cout << endl;
    
    cout << "'fill_n' populates a range with specified value" << endl;
    fill_n(begin(demo), 5, 1);
    for(auto i:demo) cout << i << " "; cout << endl;

    cout << "'generate' will create numbers according to a lambda" << endl;
    int generator = 10;
    generate(begin(demo), end(demo), [&generator](){return generator-=2;});
    for(auto i:demo) cout << i << " "; cout << endl;

    cout << "'replace' simply replaces a value with another, 'replace_if' will do it if a condition is met (via a lambda)" << endl;
    replace_if(begin(demo), end(demo), [](int elem){ return elem < 0;}, 2);
    for(auto i:demo) cout << i << " "; cout << endl;

    cout << "remove duplicates using 'unique'. Relies on collection being 'sort'ed, and use of 'erase'" << endl;
    vector<int> demo2 = demo;
    sort(begin(demo2), end(demo2));
    demo2.erase(unique(begin(demo2), end(demo2)), end(demo2));
    for(auto i:demo2) cout << i << " "; cout << endl;




}