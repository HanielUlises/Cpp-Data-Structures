#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <memory>

class Graph {
public:
    explicit Graph(int num_vertices); 
    ~Graph();

    // Adds an edge to the graph
    void add_edge(int u, int v, bool undirected = true); 
    // Prints the adjacency list of the graph
    void print_adj_list() const;  
    // Checks if there is an edge between u and v
    bool has_edge(int u, int v) const; 
    // Returns the number of vertices in the graph 
    int get_num_vertices() const;
    // Returns the number of edges in the graph  
    int get_num_edges() const;  
    // Returns a vector of neighbors for a given vertex
    std::vector<int> get_neighbors(int vertex) const;  

private:
    int num_vertices;  // Number of vertices
    int num_edges;     // Number of edges (for quick retrieval)
    std::unique_ptr<std::vector<int>[]> adj_list;  // Adjacency list using smart pointer
};

#endif // GRAPH_H
