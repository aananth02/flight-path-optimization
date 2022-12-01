#pragma once
#include "graph.h"

class Algorithms {
    public:
        void Floyd_Warshall(const Graph& g);
        vector<string> Path(const Graph& g, Vertex source, Vertex destination);
        void BetweennessCentrality();
        Graph Kruskal(Graph inputGraph);
    private:
        vector<vector<Vertex>> p;
};