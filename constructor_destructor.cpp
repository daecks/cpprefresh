#include <iostream>
#include <stdexcept>

using namespace std;

class B{
    public:
    B(){ cout << "B constructor\n";
   //     throw invalid_argument("42"); 
    }
    ~B() {cout << "B destructor\n";}
};

class C{
    public:
    C(){ cout << "C constructor\n";}
    ~C() {cout << "C destructor\n";}
};

class D{
    public:
    D(){ cout << "D constructor\n";}
    ~D(){ cout << "D destructor\n";}
};

class A: public B, public C{
    D d;
    public:
    A(){ cout << "A constructor\n";}
    ~A() {cout << "A destructor\n";}
};

int main(){
    try{
        A a;
    }catch(const invalid_argument &e){
        cout << e.what() << endl;
    }
}
