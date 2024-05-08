#include "Graph.h"

Graph::Graph(int num_vertices) : num_vertices(num_vertices), num_edges(0) {
    adj_list.reset(new std::vector<int>[num_vertices]);
}

Graph::~Graph() {
}

// Adds an edge to the graph
void Graph::add_edge(int u, int v, bool undirected) {
    if (u < num_vertices && v < num_vertices) {
        adj_list[u].push_back(v);
        if (undirected) {
            adj_list[v].push_back(u);
        }
        num_edges += undirected ? 2 : 1;
    }
}

// Prints the adjacency list of the graph
void Graph::print_adj_list() const {
    for (int i = 0; i < num_vertices; ++i) {
        std::cout << i << ": ";
        for (int neighbor : adj_list[i]) {
            std::cout << neighbor << " ";
        }
        std::cout << std::endl;
    }
}

// Checks if there is an edge between u and v
bool Graph::has_edge(int u, int v) const {
    if (u < num_vertices && v < num_vertices) {
        for (int neighbor : adj_list[u]) {
            if (neighbor == v) {
                return true;
            }
        }
    }
    return false;
}

// Returns the number of vertices in the graph
int Graph::get_num_vertices() const {
    return num_vertices;
}

// Returns the number of edges in the graph
int Graph::get_num_edges() const {
    return num_edges;
}

// Returns a vector of neighbors for a given vertex
std::vector<int> Graph::get_neighbors(int vertex) const {
    if (vertex < num_vertices) {
        return adj_list[vertex];
    }
    // Empty vector if vertex is out of bounds
    return {};  
}
