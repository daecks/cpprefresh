#include <iostream>
#include <cstring>

void* operator new(const size_t num_bytes){
    void* address = malloc(num_bytes);
    std::cout << "Allocating " << num_bytes << " bytes at address: " << address << std::endl;
    return(address);
}

void operator delete(void* memory){
    std::cout << "Freeing memory at address: " << memory << std::endl;
    free(memory);
}

template<typename T>
class StupidVector{
public:

    StupidVector(){
        std::cout << "entered constructor\n";
    }
    
    StupidVector(int size):element_count(size){
        std::cout << "Entered constructor with size: " << element_count << std::endl;
        data = new T[element_count];
    }

    void push_back(T&& elem){
        std::cout << "pushed back element: " << elem << std::endl;
        T *temp_data = new T[element_count + 1];
        //memcpy(temp_data, data, element_count); // doesn't work for non-primitive types
        for(int i = 0; i < element_count; i++){
            temp_data[i] = std::move(data[i]);
        }
        temp_data[element_count] = std::move(elem);
        element_count++;
        delete[] data;
        data = temp_data;
    }
    
    void push_back(T& elem){
        std::cout << "pushed back element: " << elem << std::endl;
        T *temp_data = new T[element_count + 1];
        //memcpy(temp_data, data, element_count); // doesn't work for non-primitive types
        for(int i = 0; i < element_count; i++){
            temp_data[i] = std::move(data[i]);
        }
        temp_data[element_count] = std::move(elem);
        element_count++;
        delete[] data;
        data = temp_data;
    }


    //friend std::ostream& operator<<(std::ostream &os, const Vector& vec);

    T operator[](int index){
        return data[index];
    }

    size_t size(){
        return element_count;
    }

    ~StupidVector(){
        std::cout << "entered destructor\n";
        delete[] data;
    }

private:
    size_t element_count = 0;
    T *data = nullptr;
};

//std::ostream& operator<<(std::ostream &os, const Vector& vec){
//    int i;
//    for(i = 0; i < vec.data_size - 1; i++){
//        os << vec.data[i] << ", ";
//    }
//    os << vec.data[i];
//    return os;
//}

int main(){

    // Int type
    {
        std::cout << "Int test\n";
        StupidVector<int> v;
        v.push_back(1);
        v.push_back(2);
        for(int i = 0; i < v.size(); i++){
           std::cout << "data[" << i << "] = " << v[i] << std::endl;
        }
    }

    // Char type
    {
        std::cout << "Char test\n";
        StupidVector<char> v;
        v.push_back('a');
        v.push_back('b');
        for(int i = 0; i < v.size(); i++){
           std::cout << "data[" << i << "] = " << v[i] << std::endl;
        }
    }

    // Char type with lvalue
    {
        std::cout << "Char test with lvalue\n";
        char one = 'a';
        char two = 'b';
        StupidVector<char> v;
        v.push_back(one);
        v.push_back(two);
        for(int i = 0; i < v.size(); i++){
           std::cout << "data[" << i << "] = " << v[i] << std::endl;
        }
    }


    // Init with size
    {
        std::cout << "Init with size\n";
        StupidVector<char> v(5);
        v.push_back('a');
        v.push_back('b');
        for(int i = 0; i < v.size(); i++){
           std::cout << "data[" << i << "] = " << v[i] << std::endl;
        }
    }

    // String type
    {
        std::cout << "String test\n";
        StupidVector<std::string> v;
        v.push_back("This");
        v.push_back("is");
        v.push_back("stupid");
        for(int i = 0; i < v.size(); i++){
           std::cout << "data[" << i << "] = " << v[i] << std::endl;
        }
    }
}