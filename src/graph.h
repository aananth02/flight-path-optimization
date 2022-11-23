#pragma once

#include <algorithm>
#include <string>
#include <iostream>
#include <vector>
#include <math.h>
#include "edge.h"
#include "data.h"

using namespace std;

class Graph {
public:

    Graph(bool weighted);
    Graph(bool weighted, bool directed);
    Graph(Airport_data& ad, Route_data& rd);

    // dir = 1 is when v acts as source, dir = -1 when v acts as destination, dir = 0 when we only care about adjacency
    vector<Vertex> getAdjacentDir(Vertex v, int dir) const;      
    
    vector<Vertex> getVertices() const;
    Edge getEdge(Vertex source, Vertex destination) const;
    vector<Edge> getEdges() const;

    bool vertexExists (Vertex v) const;
    bool edgeExists(Vertex source, Vertex destination) const;

    void setEdgeLabel(Vertex source, Vertex destination, string label);
    string getEdgeLabel(Vertex source, Vertex destination) const;
    float getEdgeWeight(Vertex source, Vertex destination) const;

    void insertVertex(Vertex v);
    Vertex removeVertex(Vertex v);
    bool insertEdge(Vertex source, Vertex destination, float weight, string label);
    Edge removeEdge(Vertex source, Vertex destination);
    bool isDirected() const;
    void clear();

private:
    vector<vector<pair<float, string>>> adjacency_matrix;
    vector<pair<float, string>> empty_edges;
    vector<Vertex> ver_index;
    bool weighted;

    // if the graph is directed, then the weight of an edge is determined by the order of row and column for source and destination
    // adjacency_matrix[src][dest] > 0; adjacency_matrix[dest][src] < 0; 0 for no edge
    bool directed;      

    int getVertexIdx(Vertex x) const;
};
