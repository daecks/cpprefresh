// Implementation of a fenwick tree
// based on https://www.youtube.com/watch?v=GURRzAKL1lY

#include <iostream>
#include <vector>
#include <chrono>
#include <numeric>

using namespace std;

using std::chrono::steady_clock;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::microseconds;
using std::chrono::nanoseconds;
using std::chrono::duration_cast;

// Here a template is used to time how 
// much time a function takes to complete
template <typename Func>
long long TimeFunc(Func f){

    auto start = chrono::high_resolution_clock::now();
    f();
    auto finish = chrono::high_resolution_clock::now();

    return duration_cast<nanoseconds>(finish - start).count();
}

class fenwick
{
private:
    vector<int> fenwick_tree;
    int sum(int pos);
    int input_size; 
    vector<int> input;
    void increment(int postition, int val);

public:
    fenwick(vector<int> &input);
    int sum_range(int range_start, int range_end);
    void update(int postition, int val);
};

fenwick::fenwick(vector<int>& input):input(input){
    
    // init fenwick tree in O(n) time.
    // First step: create a fenwick array one element larger than the input.
    // The fenwick array index is offset by one
    input_size = input.size();
    fenwick_tree.resize(input_size+1);
    fenwick_tree[1] = input[0];

    // Intermediate step: init fenwick tree with cumulative sum
    auto init_fenwick_tree = [&](){};
    for(int i = 1; i<input_size; i++){
        fenwick_tree[i+1] = fenwick_tree[i] + input[i];
    }

    // From each node, remove the value of the parent node
    for(int i = input_size; i > 0; i--){
        int parent = i - (i & -i);
        if(parent >= 0){
            fenwick_tree[i] -= fenwick_tree[parent];
        }
    }
}

int fenwick::sum(int pos){
    int result = 0;
    pos++;
    while(pos > 0){
        result += fenwick_tree[pos];
        pos = pos - (pos & -pos);
    } 
    return result;
}

// Calculate sum from range_start to range_end inclusive
int fenwick::sum_range(int range_start, int range_end){
    return(sum(range_end) - sum(range_start - 1));
}


void fenwick::increment(int position, int val){
    // fenwick tree index offset is always 1. 
    position++;
    while(position <= input_size){
        fenwick_tree[position] += val; 
        position = position + (position & -position);
    }
}

// Update a val at position
// Underneath, this will increment the original array by a value,
// and then we'll have to recalculate the fenwick tree based on that.
void fenwick::update(int position, int val){
    int diff = val - input[position];
    input[position] =  val;
    increment(position, diff);
}

int main(){

    // Fill up a large vector with numbers
    vector<int> input(100000);
    iota(begin(input), end(input), 0);

    int start_position = 5;
    int end_position = 50000;
    int result;

    // Time taken with fenwick tree
    fenwick fenwick_test(input);
    auto nanoseconds = TimeFunc([&](){ result = fenwick_test.sum_range(start_position, end_position); });
    cout << "Time taken = " << nanoseconds << " result = " << result << endl;

    // Time taken with summing an array test
    auto standard_sum = [&](){return accumulate(begin(input)+start_position, begin(input)+end_position+1, 0);};
    nanoseconds = TimeFunc([&](){ result = standard_sum(); });
    cout << "Time taken = " << nanoseconds << " result = " << result << endl;

}