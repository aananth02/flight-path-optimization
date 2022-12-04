#pragma once

#include <queue>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#include "graph.h"

using namespace std;

// Implementing a BFS traversal

// Class implemented in a manner that we can later implement DFS as well hence chose the genric name of traversal

class Traversal {
    public:
        void BFS(const Graph& graph); // no need to call this, but still implemented in public so it can be called if needed
        void printgraph(const Graph& graph);
        map<Vertex, string> getVertexLabels();
        map<Edge, string> getEdgeLabels();
    private:
        void BFS(const Graph& graph, const Vertex& vertex);
        vector<Vertex> bfs_traversed_;
        map<Vertex, string> label_vertices_;
        map<Edge, string> label_edges_;
};