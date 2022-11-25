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
        void BFS(const Graph& graph);
        void BFS(const Graph& graph, const Vertex& vertex);
        void printgraph();
    private:
        vector<Vertex> bfs_traversed_;
        map<Vertex, string> label_vertices_;
        map<Edge, string> label_edges_;
};