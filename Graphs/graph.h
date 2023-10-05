#include "iostream"
#include "list"

class Graph{
public:
    Graph(int V);
    void addEdge (int i, int j, bool undir = true);
    void printAdjList();
private:
    int V;
    std::list<int> *l;
};