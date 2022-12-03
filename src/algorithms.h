#pragma once
#include "graph.h"

class Algorithms {
    public:
        void Floyd_Warshall(const Graph& inputGraph);
        vector<string> Path(const Graph& inputGraph, Vertex source, Vertex destination);
        std::string BetweennessCentrality(const Graph &g, vector<std::string> vert);
        Graph Kruskal(Graph inputGraph);
        vector<vector<Vertex>> getPaths();
    private:
        vector<vector<Vertex>> paths;
};