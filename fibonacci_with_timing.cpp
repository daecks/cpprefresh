#include <iostream>
#include <chrono>

using namespace std;
using std::chrono::steady_clock;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::duration_cast;

// Here a template is used to time how 
// much time a function takes to complete
template <typename Func>
long long TimeFunc(Func f){

    auto start = chrono::high_resolution_clock::now();
    f();
    auto finish = chrono::high_resolution_clock::now();

    return duration_cast<milliseconds>(finish - start).count();
}

long fibonacci(unsigned int n){
    // Returns the 'nth' fibonacci number
    // 0, 1, 1, 2, 3, 5, 8, ...
    if(n < 2) return n; 
    return(fibonacci(n-2) + fibonacci(n-1));
};

int main(){
    cout << fibonacci(0) << endl;
    cout << fibonacci(1) << endl;
    cout << fibonacci(2) << endl;
    cout << fibonacci(3) << endl;
    cout << fibonacci(4) << endl;
    cout << fibonacci(5) << endl;
    cout << fibonacci(6) << endl;
    cout << fibonacci(7) << endl;

    int fib_result;
    auto milliseconds = TimeFunc([&](){ fib_result = fibonacci(41); });
    cout << "fib result = " << fib_result << ", time taken = " << milliseconds << " milliseconds" << endl;
}
