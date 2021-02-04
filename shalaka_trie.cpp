#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>

static const int ALPHABET_SIZE = 26;

struct TrieNode{
    struct TrieNode *children[ALPHABET_SIZE];
    bool isEndOfWord;
};

struct TrieNode *getNewNode(){

   struct TrieNode *node = new TrieNode();
   node->isEndOfWord = false;
   for(int i = 0; i<ALPHABET_SIZE; i++){
       node->children[i] = nullptr;
   }

   return node;
}

void insertNode(struct TrieNode * root, std::string& word){
    struct TrieNode *current = root;

    for(auto &letter:word){
        int index = letter - 'a';
        //std::cout << index << std::endl;
        if(current->children[index] == nullptr) current->children[index] = getNewNode();
        current = current->children[index];
    }
    
    current->isEndOfWord = true;
}

int main(){

    std::vector<std::string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};

    struct TrieNode *root = getNewNode();

    for(auto &word:words){
        insertNode(root, word);
    }

    return 0;
}