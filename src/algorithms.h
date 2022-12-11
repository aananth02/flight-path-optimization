#pragma once
#include "graph.h"

struct betweeness
{
    std::string central;
    int maxCount;
};

class Algorithms
{
public:
    void Floyd_Warshall(const Graph &inputGraph);
    vector<string> Path(const Graph &inputGraph, Vertex source, Vertex destination);
    betweeness BetweennessCentrality(const Graph &g, vector<std::string> vert);
    Graph Kruskal(Graph inputGraph);
    vector<vector<Vertex>> getPaths();

private:
    vector<vector<Vertex>> paths;
};