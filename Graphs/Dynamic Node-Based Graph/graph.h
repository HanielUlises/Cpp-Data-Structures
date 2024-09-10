#ifndef GRAPH_H
#define GRAPH_H

#include <memory>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <string>
#include <iostream>

class Graph {
private:
    // Node class for <<representing>> vertices
    class Node {
    public:
        std::string name;
        std::unordered_set<Node*> edges;

        explicit Node(const std::string& name);
    };

    std::unordered_map<std::string, std::unique_ptr<Node>> nodes;

public:
    void add_node(const std::string& name);
    void add_edge(const std::string& from, const std::string& to);
    void remove_node(const std::string& name);
    void remove_edge(const std::string& from, const std::string& to);

    void print_graph() const;

    bool has_node(const std::string& name) const;

     bool has_edge(const std::string& from, const std::string& to) const;
};

#endif // GRAPH_H
