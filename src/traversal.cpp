#include "traversal.h"
#include <iostream>

void Traversal::BFS(const Graph& graph) {
    // Initially, we want all our vertices to be set to an unexplored.
    for (Vertex vert : graph.getVertices()) {
        label_vertices_[vert] = "UNEXPLORED";
    }
    // Initially, we want all our edges to be set to an unexplored.
    for (Edge edge : graph.getEdges()) {
        label_edges_[edge] = "UNEXPLORED";
    }

    // Now, we call BFS.
    for (Vertex v : graph.getVertices()) {
        if (label_vertices_[v] == "UNEXPLORED") {
            BFS(graph, v);
        }
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
        for (Vertex neighbor : graph.getAdjacentDir(v, 1)) {
            if (label_vertices_[neighbor] == "UNEXPLORED") {
                label_edges_[graph.getEdge(v, neighbor)] = "DISCOVERY";
                label_vertices_[neighbor] = "VISITED";
                q.push(neighbor);
            } else if (label_edges_[graph.getEdge(v, neighbor)] == "UNEXPLORED") {
                label_edges_[graph.getEdge(v, neighbor)] = "CROSS";
            }
        }
    }
}

void Traversal::printgraph(const Graph& graph) {
    this->BFS(graph); //So that for viewing the graph user only needs to call this function
    cout << "This function prints out the Airports in order of a BFS traversal" << endl;
    for (Vertex v : bfs_traversed_) {
        cout << v << std::endl;
    }
    // Note: This function can later be developed to provide a animated updation of how a BFS traversal looks on a large graph
}

map<Vertex, string> Traversal::getVertexLabels() {
    return this->label_vertices_;
}

map<Edge, string> Traversal::getEdgeLabels() {
    return this->label_edges_;
}