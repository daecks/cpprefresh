#include <chrono>

using std::chrono::steady_clock;
using std::chrono::seconds;
using std::chrono::milliseconds;
using std::chrono::microseconds;
using std::chrono::duration_cast;

// Here a template is used to time how 
// much time a function takes to complete
template <typename Func>
long long TimeFunc(Func f){

    auto start = std::chrono::high_resolution_clock::now();
    f();
    auto finish = std::chrono::high_resolution_clock::now();

    return duration_cast<microseconds>(finish - start).count();
}

