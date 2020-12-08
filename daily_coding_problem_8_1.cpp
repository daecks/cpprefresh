#include <iostream>

using namespace std;

// assumption: lowercase alphabetic characters only
static const int NUM_CHARS = 26; 

struct Trie{
    bool isleaf = false;
    Trie* character[NUM_CHARS] = {}; // should init to nullptr
    void insert(string);
    bool search(string);
};

void Trie::insert(string key){
    Trie* current = this;
    for(auto letter:key){
        // if the current key doesn't exist, create a new node
        if(current->character[key[letter]] == nullptr){
            current->character[key[letter]] = new Trie();
        }

        // Advance to the next node
        current = current->character[key[letter]]; 
    }

}

int main(){
    Trie* head = new Trie();
    head->insert("hello");
    head->insert("world");
}