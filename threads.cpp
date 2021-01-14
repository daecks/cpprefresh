// Some examples on threading
#include <iostream>
#include <thread>

static bool testing_completed = false;

void test_function(){

    using namespace std::chrono_literals;
    while(!testing_completed){
        std::cout << "Running test in thread" << std::this_thread::get_id << '\n';
        std::this_thread::sleep_for(500ms);
    }

}

int main(){
    std::cout << "In main thread" << std::this_thread::get_id << '\n';

    std::thread test_thread(test_function);

    // This holds the current thread
    std::cin.get();
    testing_completed = true;

    test_thread.join();
    std::cout << "Test completed\n";
}
