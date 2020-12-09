#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <queue>

// Contains examples for depth-first search (DFS) and 
// breadth-first search (BFS). DFS uses a stack, BFS uses a queue.

using namespace std;

class Graph{
    private:
    int numVertices;
    list<int>* adjLists;

    public:
    Graph(int numVertices);
    void addEdge(int src, int dest);
    bool DFS(int startVertex); // This will be used to solve the problem
    void BFS(int startVertex);
};

Graph::Graph(int vertices) : numVertices(vertices){
    adjLists = new list<int>[vertices];
}

void Graph::addEdge(int src, int dest){
    adjLists[src].push_back(dest);
    //adjLists[dest].push_back(src); // uncomment to make non-directed
}

bool Graph::DFS(int startVertex){
    cout << "\nUsing DFS" << endl;
    vector<bool> visited(numVertices, false);
    stack<int> stack;

    visited[startVertex] = true;
    stack.push(startVertex);
    
    while(!stack.empty()){
        int currVertex = stack.top();
        cout << "Visited " << currVertex << endl;
        stack.pop();

        // For the current node/vertex, find any adjacent nodes
        // and check if they have not been visited yet. If so,
        // mark them as visited and add them to the adjacent vertex queue 
        for(auto adjVertex:adjLists[currVertex]){
            if(!visited[adjVertex]){
                visited[adjVertex] = true;
                stack.push(adjVertex);
             }
             else{
                // The same node was visited twice, so a cycle exists 
                return true;
             }
        }
    }
    // We didn't visit a node twice, so no cycle exists
    return false;
}

void Graph::BFS(int startVertex){
    cout << "\nUsing BFS" << endl;
    vector<bool> visited(numVertices, false);
    queue<int> queue;

    visited[startVertex] = true;
    queue.push(startVertex);
    
    while(!queue.empty()){
        int currVertex = queue.front();
        cout << "Visited " << currVertex << endl;
        queue.pop();

        // For the current node/vertex, find any adjacent nodes
        // and check if they have not been visited yet. If so,
        // mark them as visited and add them to the adjacent vertex queue 
        for(auto adjVertex:adjLists[currVertex]){
            if(!visited[adjVertex]){
                visited[adjVertex] = true;
                queue.push(adjVertex);
            }
        }
    }
}

int main(){

    //
    //  4 - 5 - 7
    //  | 
    //  0 - 1 - 7 
    //  | / 
    //  2 - 3 
    //

    Graph graph(8);
    graph.addEdge(0,1);
    graph.addEdge(0,2);
    graph.addEdge(2,0);
    graph.addEdge(1,2);
    graph.addEdge(2,3);
    graph.addEdge(0,4);
    graph.addEdge(4,5);
    graph.addEdge(5,6);
    graph.addEdge(1,7);

    (graph.DFS(2) == 1)?cout<<"Cycle detected!\n":cout<<"No cycle detected\n";
    graph.BFS(2);
}