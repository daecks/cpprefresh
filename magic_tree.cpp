#include <string>
#include <vector>
#include <unordered_map>
#include <list>

struct Node{
  int id;
  std::string data;
  Node *parent;
  std::list<Node*> children;
};

struct Record{
  int id;
  int parent_id;
  std::string data;
};

std::list<Node> createTree(const std::vector<Record>& records){
    
    std::list<Node> nodelist;
    nodelist.insert(new Node(0, "parent", nullptr, children));

    for( const auto& record:records ){


        
    }

    return nodelist;

}

int main(){

    std::vector<Record> records = {
        {1, 0, std::string("One")},
        {2, 0, std::string("Two")},
        {3, 0, std::string("Three")},
        {4, 3, std::string("Four")},
        {5, 4, std::string("Five")}
    };

    std::list<Node> treelist = createTree(records);

}