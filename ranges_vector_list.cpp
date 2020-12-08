#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(){

    vector<int> test = {1, 2,3, 4, 5,6};

    for(auto it = test.begin(); it != (test.end() -1); it++){
        cout << *it << endl;
    }

    auto end = test.end() -1;

    auto result = accumulate(test.begin(), test.end() - 1, 0);
    cout << result << endl;


}
