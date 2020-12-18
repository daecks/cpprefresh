#include <iostream>

using namespace std;

// Number of moves required is (2^n - 1) discs.
// Consider towers A, B, C, where A is source,
// B is intermediate, and C is destination.

// If 1 disc, number of moves is (2^1 - 1) = 1 move
// A -> C.

// If two discs, number of moves is (2^2 - 1) = 3 moves
// A -> B
// A -> C
// B -> C

// If three discs, number of moves is (2^3 - 1) = 7 moves
// A -> C
// A -> B
// C -> B
// A -> C
// B -> A
// B -> C
// A -> C


void tower_of_hanoi(int number_of_discs, char left, char middle, char right){

    if(number_of_discs == 1){
        cout << "Move " << left << " to " << right << endl;
    }else{
        tower_of_hanoi(number_of_discs - 1, left, right, middle);
        cout << "Move " << left << " to " << right << endl;
        tower_of_hanoi(number_of_discs - 1, middle, left, right);
    }

}

int main(){
    
    // Try with one disc
    cout << "One disc\n";
    tower_of_hanoi(1, 'A', 'B', 'C');

    cout << "Two discs\n";
    tower_of_hanoi(2, 'A', 'B', 'C');

    cout << "Three discs\n";
    tower_of_hanoi(3, 'A', 'B', 'C');

    cout << "Four discs\n";
    tower_of_hanoi(4, 'A', 'B', 'C');

    return 0;

}