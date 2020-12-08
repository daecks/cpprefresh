#include <iostream>
#include <queue>

using namespace std;

// Heaps of min and max type can be implemented with a priority queue
// https://en.cppreference.com/w/cpp/container/priority_queue
// Note: there is also a pre-defined heap type, but it is only a max heap
// (I couldn't find how you'd create a min heap using this method)

template <class T>
class runningMedian{
    private:
        // A priority queue by default is a max heap, but I'll be explicit here
        priority_queue<T, vector<T>, less<T>> max_heap;

        // A priority queue with the following parameters creates a min heap
        // (A user-provided Compare can be supplied to change the ordering, 
        // e.g. using std::greater<T> would cause the smallest element to appear as the top(). 
        priority_queue<T, vector<T>, greater<T>> min_heap;

        private:
           void rebalance(){
               // If the size of either heap differs by more than one, push from the larger
               // heap to the smaller heap
               if(max_heap.size() > min_heap.size() + 1){
                   min_heap.push(max_heap.top());
                   max_heap.pop();
               }else if(min_heap.size() > max_heap.size() + 1){
                   max_heap.push(min_heap.top());
                   min_heap.pop();
               }
           }
    public:
        runningMedian() {}
        // Adds a number, returns the current running median
        void addNumber(T number)
        {
            // If no elements in either, push to max heap for no particular reason. 
            if (min_heap.size() + max_heap.size() < 1) {
                max_heap.push(number);
                return;
            }
            
            // Numbers larger than the top of the max heap go to the min heap 
            if(number >= max_heap.top()) {
                min_heap.push(number);
            }else{
                max_heap.push(number);
            }

            rebalance();
        }

        float get_median()
        {
            // Get the value of the larger heap if different size, else average if
            // heaps are of the same size.
            if (max_heap.size() > min_heap.size()){
                return max_heap.top();
            }
            else if (max_heap.size() < min_heap.size()){
                return min_heap.top();
            }
            else{
                return (min_heap.top() + max_heap.top()) / 2.0;
            }
        }
};

int main(){
    // Test driver
    runningMedian<int> test;
    test.addNumber(2);
    cout << test.get_median() << endl;
    
    test.addNumber(1);
    cout << test.get_median() << endl;

    test.addNumber(5);
    cout << test.get_median() << endl;

    test.addNumber(7);
    cout << test.get_median() << endl;

    test.addNumber(20);
    cout << test.get_median() << endl;

    test.addNumber(6);
    cout << test.get_median() << endl;

    test.addNumber(7);
    cout << test.get_median() << endl;
}