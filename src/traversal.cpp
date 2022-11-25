#include "traversal.h"
#include <iostream>

void Traversal::BFS(const Graph& graph) {
    for (Vertex vert : graph.getVertices()) {
        label_vertices_[vert] = "UNEXPLORED";
    }
    for (Edge edg : graph.getEdges()) {
        label_edges_[edg] = "UNEXPLORED";
    }
    for (Vertex v : graph.getVertices()) {
        if (label_vertices_[v] == "UNEXPLORED") BFS(graph, v);
    }
}

void Traversal::BFS(const Graph& graph, const Vertex& vertex) {
    queue<Vertex> q;
    label_vertices_[vertex] = "VISITED";
    q.push(vertex);
    while (!q.empty()) {
        Vertex v = q.front();
        q.pop();
        bfs_traversed_.push_back(v);
        for (Vertex w : graph.getAdjacentDir(v, 1)) {
            if (label_vertices_[w] == "UNEXPLORED") {
                label_edges_[graph.getEdge(v, w)] = true;
                label_vertices_[w] = true;
                q.push(w);
            } else if (label_edges_[graph.getEdge(v, w)] == "UNEXPLORED") {
                label_edges_[graph.getEdge(v, w)] = "CROSS";
            }
        }
    }
}

void Traversal::printgraph(const Graph& graph) {
    this->BFS(graph); //incase someone only calls the printgraph function
    cout << "This function prints out the Airports in order of a BFS traversal" << endl;
    for (Vertex v : bfs_traversed_) {
        cout << v << std::endl;
    }
    // Note: This function can later be developed to provide a animated updation of how a BFS traversal looks on a large graph
}