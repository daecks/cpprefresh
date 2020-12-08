#include <unordered_map>
#include <memory>
#include <iostream>

using namespace std;

class Tries_pb
{
public:
    Tries_pb();
    void insertWord(string word);
    bool getWord(string word);

private:
    struct Node
    {
        bool end_of_word;
        unordered_map<char, unique_ptr<Node>> children;
        Node() : end_of_word(false) {}
    };

    unique_ptr<Node> root;
};

Tries_pb::Tries_pb()
{
    root = make_unique<Node>();
}

void Tries_pb::insertWord(string word)
{
    if (word.empty())
    {
        return;
    }
    // Iterate over the tree to check if there is a node with the character
    // If not create a new node with the character

    auto it = root.get(); // why does the auto & fail?

    // Because we're not expecting to modify key... don't use &.
    for (const auto key : word)
    {
        if (!it->children.count(key))
        {
            it->children.emplace(key, make_unique<Node>());
        }
        it = it->children[key].get();
    }

    it->end_of_word = true;
}

bool Tries_pb::getWord(string word)
{
    if (word.empty())
    {
        return false;
    }

    auto it = root.get();

    for (auto key : word)
    {
        if (it->children.count(key))
        {
            it = it->children[key].get();
        }
        else
        {
            cout << "Word not found " << endl;
            return false;
        }
    }

    if (it->end_of_word)
    {
        cout << "Found Complete word" << endl;
    }
    else
    {
        cout << "Found prefix word" << endl;
    }
    return true;
}

int main(){
    Tries_pb tries;

    // Some good cases
    tries.insertWord("Hello");
    cout << tries.getWord("Hell") << endl;
    tries.insertWord("codeWorks");
    cout << tries.getWord("code") << endl;

    // Some error cases
    cout << tries.getWord("No") << endl;
}