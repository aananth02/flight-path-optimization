#include "algorithms.h"

void Algorithms::Floyd_Warshall(const Graph& g) {

    vector<float> tmp(g.getVertices().size(), 25000);
    vector<vector<float>> d(g.getVertices().size(), tmp);
    vector<Vertex> tmp2(g.getVertices().size(), "");
    p = vector<vector<Vertex>>(g.getVertices().size(), tmp2);
    for (Vertex v : g.getVertices()) {
        d[g.getVertexIdx(v)][g.getVertexIdx(v)] = 0;
    }
    for (auto i : g.getEdges()) {
        if (i.weight > 0)
            d[g.getVertexIdx(i.src)][g.getVertexIdx(i.dest)] = i.weight;
    }
    for (Vertex v : g.getVertices()) {
        for (Vertex u : g.getVertices()) {
            if (d[g.getVertexIdx(v)][g.getVertexIdx(u)] != 25000)
                p[g.getVertexIdx(v)][g.getVertexIdx(u)] = v;
        }
    }
    for (Vertex w : g.getVertices()) {
        for (Vertex u : g.getVertices()) {
            for (Vertex v : g.getVertices()) {
                int u_idx = g.getVertexIdx(u);
                int v_idx = g.getVertexIdx(v);
                int w_idx = g.getVertexIdx(w);
                if (d[u_idx][v_idx] > d[u_idx][w_idx] + d[w_idx][v_idx]) {
                    d[u_idx][v_idx] = d[u_idx][w_idx] + d[w_idx][v_idx];
                    p[u_idx][v_idx] = p[w_idx][v_idx];
                }
            }
        }
    }
}

vector<string> Algorithms::Path(const Graph& g, Vertex source, Vertex destination) {
    if (p[g.getVertexIdx(source)][g.getVertexIdx(destination)] == "")
        return {};
    vector<string> path = { destination };

    while (source != destination) {
        destination = p[g.getVertexIdx(source)][g.getVertexIdx(destination)];       // Can add airline names on the required path by calling getEdge
        path.push_back(destination);
    }
    return path;        // path goes to source starting from destination; destination -> -> -> ->....-> ->source
}