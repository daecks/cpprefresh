#include <iostream>
#include <memory>

using namespace std;

class A{
    public:
    A(){
        cout << "Class A constructor\n";
    };
    void do_something(string what){ cout << "Doing something with " << what << endl;}
    ~A(){
        cout << "Class A destructor\n";
    };
};

int main(){

    {
        // Creation of a unique_ptr
        unique_ptr<A> test_unique_ptr = make_unique<A>();
        test_unique_ptr->do_something("unique");
        cout << "Address: " << test_unique_ptr.get() << endl;
        // We can't assign it to something else (the next line fails)
        //unique_ptr<A> test_ptr_2 = test_ptr;
        // However, we can transfer ownership:
        unique_ptr<A> moved_unique_ptr{move(test_unique_ptr)};
        cout << "Address old: " << test_unique_ptr.get() << endl;
        cout << "Address moved: " << moved_unique_ptr.get() << endl;
    }
        // Creation of a shared_ptr
        shared_ptr<A> test_shared_ptr = make_shared<A>();
        test_shared_ptr->do_something("shared");
        cout << test_shared_ptr.use_count() << endl;
    {
        shared_ptr<A> another_shared_ptr = test_shared_ptr;
        another_shared_ptr->do_something("another shared");
        cout << test_shared_ptr.use_count() << endl;
    }
        cout << test_shared_ptr.use_count() << endl;

        weak_ptr<A> test_weak_ptr = test_shared_ptr;
        cout << test_shared_ptr.use_count() << endl;
    return 0;
};
