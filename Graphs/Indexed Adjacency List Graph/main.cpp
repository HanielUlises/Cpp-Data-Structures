#include "graph.h"
#include <iostream>

int main() {
    // Directed graph with 5 vertices
    Graph directedGraph(5);

    directedGraph.add_edge(0, 1, false); // Directed edge from 0 to 1
    directedGraph.add_edge(0, 4, false); // Directed edge from 0 to 4
    directedGraph.add_edge(1, 2, false); // Directed edge from 1 to 2
    directedGraph.add_edge(1, 3, false); // Directed edge from 1 to 3
    directedGraph.add_edge(2, 3, false); // Directed edge from 2 to 3

    std::cout << "Directed Graph Adjacency List:" << std::endl;
    directedGraph.print_adj_list();

    // Undirected graph with 5 vertices
    Graph undirectedGraph(5);

    undirectedGraph.add_edge(0, 1, true); // Undirected edge between 0 and 1
    undirectedGraph.add_edge(0, 4, true); // Undirected edge between 0 and 4
    undirectedGraph.add_edge(1, 2, true); // Undirected edge between 1 and 2
    undirectedGraph.add_edge(1, 3, true); // Undirected edge between 1 and 3
    undirectedGraph.add_edge(2, 3, true); // Undirected edge between 2 and 3

    // Print the adjacency list
    std::cout << "Undirected Graph Adjacency List:" << std::endl;
    undirectedGraph.print_adj_list();

    // Edge presence in the directed graph
    std::cout << "Checking for edge between 1 and 3 in directed graph: "
              << (directedGraph.has_edge(1, 3) ? "Exists" : "Does not exist") << std::endl;

    std::cout << "Checking for edge between 1 and 0 in directed graph: "
              << (directedGraph.has_edge(1, 0) ? "Exists" : "Does not exist") << std::endl;

    std::cout << "Checking for edge between 1 and 3 in undirected graph: "
              << (undirectedGraph.has_edge(1, 3) ? "Exists" : "Does not exist") << std::endl;

    // Fetching neighbors
    std::vector<int> neighbors = directedGraph.get_neighbors(1);
    std::cout << "Neighbors of vertex 1 in directed graph: ";
    for (int neighbor : neighbors) {
        std::cout << neighbor << " ";
    }
    std::cout << std::endl;

    return 0;
}
