#include <iostream>

using namespace std;

string dutch_flag_solver(string flag_array){

    int array_length = flag_array.length();
    int low = 0, mid = 0;
    int high = flag_array.length() - 1; 

    while( mid <= high ){
        switch(flag_array[mid]){
            case 'R': // move to start
                swap(flag_array[mid], flag_array[low]);
                low++;
                mid++;
                break;
            case 'G': // leave as is
                mid++;
            break;
            case 'B': // move to end
                swap(flag_array[mid], flag_array[high]);
                high--;
            break;
        }
    }

    return flag_array;

}

int main(){

    cout << dutch_flag_solver("GBRRBRG") << endl;

}
