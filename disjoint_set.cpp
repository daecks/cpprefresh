#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

// A disjoint set is that where no member can appear in more than
// one set or group. The parent of a set is the representative of that set.

class DisjointSet
{
private:
    unordered_map<int, int> disjoint_set;

public:
    void makeSet(vector<int> const &wholeset)
    {
        // On creation of a disjoint set, each member is its own set,
        // and thus its own parent, until merge/union operations are performed.
        for (int member : wholeset) disjoint_set[member] = member;
    }

    // Finds the parent of the set to which the element belongs. 
    // A parent is an element that matches its index in the set
    int findSet(int elem)
    {                     
        if (disjoint_set[elem] == elem) 
            return elem;
        return findSet(disjoint_set[elem]);
    }

    // Merges two subsets containing elements m and n.
    // Logic is to find the parent of each set to which each element belongs,
    // and arbitrarily assign 
    void unionSet(int m, int n)
    { 
        int x = findSet(m);
        int y = findSet(n);
        disjoint_set[x] = y;
    }

    int getNumGroups(){
        // The number of groups is the number of parents, 
        // i.e. the number keys that match their map index
        int groupCount = count_if(begin(disjoint_set),
                                  end(disjoint_set),
                                  [](auto elem) { return elem.first == elem.second; });
    }
};

void printSetMembership(vector<int> const &everything, DisjointSet &djset)
{
    for (int i : everything)
        cout << djset.findSet(i) << " ";
    cout << '\n';
}

int main()
{
    vector<int> wholeset = {1,2,3,4,5}; 
    DisjointSet djset;                    
    djset.makeSet(wholeset);              

    cout << "Contents of the set: ";
    printSetMembership(wholeset, djset);
    
    djset.unionSet(3,4);  
    cout << "Contents of the set after merging 3,4: ";
    printSetMembership(wholeset, djset);

    cout << "To which set does 3 belong? " << djset.findSet(3) << endl;
    cout << "How many groups are there? " << djset.getNumGroups() << endl; 

    djset.unionSet(4,5);  
    cout << "Contents of the set after merging 4,5: ";
    printSetMembership(wholeset, djset);
    cout << "How many groups are there? " << djset.getNumGroups() << endl; 

    return 0;
}