#include <iostream>

using namespace std;

class Node{
    public:
    int data;
    Node *leftChild;
    Node *rightChild;
};

Node* createNode(int data){
    Node* node = new Node;
    node->data = data;
    node->leftChild = nullptr;
    node->rightChild = nullptr;

    return node;
}

void addNode(Node *&root, int data)
{
    if (root == nullptr)
    {
        root = createNode(data);
        return;
    }

    // For BST, if the data is less than the parent, it goes on the left branch.
    // If it's more than the parent, it goes on the right branch.
    // If it was the same, we could store a count of the number of that element for the node,
    // but our Node doesn't currently support that.
    if (data < root->data)
    {
        if (root->leftChild == nullptr)
        {
            root->leftChild = createNode(data);
            return;
        }
        addNode(root->leftChild, data);
    }
    else
    {
        if (root->rightChild == nullptr)
        {
            root->rightChild = createNode(data);
            return;
        }
        addNode(root->rightChild, data);
    }
}

bool findFloorCeil(Node* &root, int searchkey, int &floor, int &ceil){
    // How this works: check the current node value against the search key. 
    // If it's the same, we are done, so floor = ceil = node value. 
    // If the search key is less than the node value, the lesser values in a BST are on the left
    // branch, so move there but also update the ceil value - this is the higest number we're expecting
    // (again due to BST structure). Else if the search key is more than the current node value, move to the
    // right branch as the greater values are there, but also update the floor value as it will be the lowest 
    // we'll see from here on.
    while(root != nullptr){
        if(searchkey == root->data){
            floor = root->data;
            ceil = root->data;
            break;
        }else if(searchkey < root->data){
            ceil = root->data;
            root = root->leftChild;
        }else{
            floor = root->data;
            root = root->rightChild;
        }
    }
}

int main(){

    Node* root = nullptr;
    Node* top = nullptr;

    addNode(root, 1);
    top = root; // saving off the top parent node because we don't store knowledge of parent
    addNode(root, 2);
    addNode(root, 3);
    addNode(root, 6);
    addNode(root, 10);
    addNode(root, 12);
    addNode(root, 14);
    addNode(root, 0);

    int searchkey = 1;
    int floor, ceil = 0;
    findFloorCeil(root, searchkey, floor, ceil);
    cout << "searchkey: " << searchkey << ", floor: " << floor << ", ceil: " << ceil << endl;

    searchkey = 3;
    root = top;
    findFloorCeil(root, searchkey, floor, ceil);
    cout << "searchkey: " << searchkey << ", floor: " << floor << ", ceil: " << ceil << endl;

    searchkey = 5;
    root = top;
    findFloorCeil(root, searchkey, floor, ceil);
    cout << "searchkey: " << searchkey << ", floor: " << floor << ", ceil: " << ceil << endl;

    searchkey = 0;
    root = top;
    findFloorCeil(root, searchkey, floor, ceil);
    cout << "searchkey: " << searchkey << ", floor: " << floor << ", ceil: " << ceil << endl;

    searchkey = 11;
    root = top;
    findFloorCeil(root, searchkey, floor, ceil);
    cout << "searchkey: " << searchkey << ", floor: " << floor << ", ceil: " << ceil << endl;

    return 0;
}