#include "graph.h"
#include <stdexcept>

// Node Implementation
Graph::Node::Node(const std::string& name) : name(name) {}

// Graph Implementation
void Graph::add_node(const std::string& name) {
    if (nodes.find(name) == nodes.end()) {
        nodes[name] = std::make_unique<Node>(name);
    }
}

void Graph::add_edge(const std::string& from, const std::string& to) {
    if (!has_node(from) || !has_node(to)) {
        throw std::invalid_argument("Both nodes must exist to add an edge.");
    }
    nodes[from]->edges.insert(nodes[to].get());
    nodes[to]->edges.insert(nodes[from].get());
}

void Graph::remove_node(const std::string& name) {
    auto it = nodes.find(name);
    if (it == nodes.end()) return;

    // Remove all edges connected to this node
    for (auto& [nodeName, nodePtr] : nodes) {
        nodePtr->edges.erase(it->second.get());
    }

    // Remove the node itself
    nodes.erase(it);
}

void Graph::remove_edge(const std::string& from, const std::string& to) {
    if (!has_node(from) || !has_node(to)) {
        throw std::invalid_argument("Both nodes must exist to remove an edge.");
    }
    nodes[from]->edges.erase(nodes[to].get());
    nodes[to]->edges.erase(nodes[from].get());
}

void Graph::print_graph() const {
    for (const auto& [nodeName, nodePtr] : nodes) {
        std::cout << nodeName << ": ";
        for (const auto* edge : nodePtr->edges) {
            std::cout << edge->name << " ";
        }
        std::cout << std::endl;
    }
}

bool Graph::has_node(const std::string& name) const {
    return nodes.find(name) != nodes.end();
}

bool Graph::has_edge(const std::string& from, const std::string& to) const {
    if (!has_node(from) || !has_node(to)) return false;

    // if there's an edge from 'from' to 'to'
    auto from_node = nodes.at(from).get();
    auto to_node = nodes.at(to).get();
    
    return from_node->edges.find(to_node) != from_node->edges.end() ||
           to_node->edges.find(from_node) != to_node->edges.end();
}