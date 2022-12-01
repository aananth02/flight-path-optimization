#include "algorithms.h"
#include "dsets.h"
#include <map>
#include <algorithm>

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

// @brief find betweenes centrality in graph, meaning the most dense airport, 
// i.e. to a traveller, we're finding the transit hubs!
/// @param g adjacency graph
/// @param vert vector obtained from Algorithms::Path
/// @return return vertex
std::string between_centrality(const Graph &g, vector<std::string> vert)
{
    int max_count = 0;
    std::string central;
    for (auto vertex1 : vert)
    {
        int count = 0;
        for (auto vertex2 : vert)
        {
            if (g.edgeExists(vertex1, vertex2))
            {
                count++;
            }
        }
        if (count > max_count)
        {
            max_count = count;
            central = vertex1;
        }
    }
    return central;
}

/// @brief 
/// @param g 
/// @param source 
/// @param destination 
/// @return 
vector<string> Algorithms::Path(const Graph& g, Vertex source, Vertex destination) {
    if (p[g.getVertexIdx(source)][g.getVertexIdx(destination)] == "")
        return {};
    vector<string> path = { destination };

    while (source != destination) {
        destination = p[g.getVertexIdx(source)][g.getVertexIdx(destination)];
        path.push_back(destination);
    }
    return path;
}

/// @brief Kruskal's algorithm is one of the ways in which a Minimum Spanning Tree for a graph is commonly built.
// In the context of our Airports and Routes Graph, a Minimum Spanning Tree is basically a backpacker's gudie to the world:
// The cheapest way to cover the world, the cheapest possible next destination from anywhere they are right now!
/// @param inputGraph : Our original graph of airport and routes data, consistsing of all possible edges, etc.
/// @return : Minimum Spanning Tree of
Graph Algorithms::Kruskal(Graph inputGraph) {
    //  Disjoint Set setup   
    DisjointSets forest;
    vector<Vertex> input_graph_vertices = inputGraph.getVertices();
    std::map<Vertex, int> vertex_to_vertex_num;
    int num_vertices = 0;
    for (int vertex_num = 0; vertex_num < int(input_graph_vertices.size()); vertex_num++) {
        vertex_to_vertex_num.insert(std::pair<Vertex, int>(input_graph_vertices.at(vertex_num), vertex_num));
        num_vertices++;
    }
    forest.addelements(num_vertices);

    // Building Priority Queue
    vector<Edge> priorityEdges = inputGraph.getEdges();
    std::sort(priorityEdges.begin(), priorityEdges.end());

    Graph output = Graph(true);
    for (auto vertex: input_graph_vertices) {
        output.insertVertex(vertex);
    }

    while (output.getEdges().size() < input_graph_vertices.size() - 1) {
        Edge min_edge = priorityEdges.at(0);
        priorityEdges.erase(priorityEdges.begin());
        if (forest.find(vertex_to_vertex_num[min_edge.src]) != forest.find(vertex_to_vertex_num[min_edge.dest])) {
            output.insertEdge(min_edge.src, min_edge.dest, min_edge.weight, min_edge.edge_label);
            forest.setunion(forest.find(vertex_to_vertex_num[min_edge.src]), forest.find(vertex_to_vertex_num[min_edge.dest]));
        }
    }
    return output;
}