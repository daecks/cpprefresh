#include <iostream>

// basic linked-list implementation

struct Node{
    int data;
    Node* next;
};

struct Node* head = nullptr;

void insert(int data){
    struct Node* newnode = new Node;
    newnode->data = data;
    newnode->next = head;
    head = newnode;
}

void print_middle(){
    if (head == nullptr){
        std::cout << "Empty list! \n";
        return;
    }

    struct Node* temp = head;
    struct Node* mid = head;
    int current_index = 0;

    while(temp != nullptr){
        if(current_index % 2) mid = mid->next;
        current_index++;
        temp = temp->next;
    }
    std::cout << mid->data << std::endl;
}

void clear(){
    struct Node* temp = head;
    struct Node* old;
    while(temp != nullptr){
        old = temp;
        temp = temp->next;
        head = temp;
        delete old;
    }
}

int main(){
    insert(3);
    insert(2);
    insert(1);
    print_middle();
    clear();

    insert(1);
    print_middle();
    clear();

    insert(4);
    insert(3);
    insert(2);
    insert(1);
    print_middle();
    clear();


}

