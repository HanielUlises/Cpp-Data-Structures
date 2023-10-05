#include "graph.h"

Graph::Graph(int V){
    this->V = V;
    l = new std::list<int>[V];
}

void Graph::addEdge (int i, int j, bool undir = true){
    l[i].push_back(j);
    if(undir){
        l[j].push_back(i);
    }
}

void Graph::printAdjList(){
    // Rows
    for(int i = 0; i < V; i++){
        std::cout<<i<<"-->";
        // Every element of the ith linked list
        for(auto node:l[i]){
            std::cout<<node<<",";
        }
        std::cout<<std::endl;
    }
}