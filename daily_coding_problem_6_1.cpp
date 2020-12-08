#include <iostream>

using namespace std;

struct Node{
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

    // For BST, if the data is less than the parent, it goes on the left, else right
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

bool find(Node* & root, int data){
    if(root == nullptr) return false; // BST is empty
}

int main(){

    Node* root = nullptr;

    addNode(root, 1);
    addNode(root, 2);
    addNode(root, 3);
    addNode(root, 6);

    return 0;

}