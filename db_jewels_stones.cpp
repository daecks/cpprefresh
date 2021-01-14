#include <iostream>

using namespace std;

int count_matches(string one, string two){

    int matches = 0;

    for(auto &left_char:one){
        for(auto &right_char:two){
            if(left_char == right_char) matches++;
        }
    }

    return matches;

}

int main(){

    cout << count_matches("ab", "abc") << endl;
    cout << count_matches("Af", "AaaddfFf") << endl;
    cout << count_matches("AYOPD", "ayopd") << endl;

    return 0;
}