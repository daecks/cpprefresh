#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main(){

    //vector<int> test = {1, 2,3,4,5,6,7};
    list<int> test = {1,2,3,4,5,6,7};

//    for(int i=0; i<test.size(); i++){
//        cout << test[i] << endl;
//    }

    for(auto i:test){
        cout << i << endl;
    }

return 0;



}