#include "algorithms.h"
#include "dsets.h"
#include <map>
#include <algorithm>

/// @brief Travellers like to keep their travelling time to a minimum. In most parts of the world,
/// travel time correlates with the distance between the passenger's Point of Departure and Point of Arrival
/// We're using Floyd-Warshall's algorithm to find the minimum distance.
/// @param inputGraph Our graph of airports and routes, implemented using an adjacency matrix.
void Algorithms::Floyd_Warshall(const Graph &inputGraph)
{

    vector<float> tmp(inputGraph.getVertices().size(), 25000);
    vector<vector<float>> d(inputGraph.getVertices().size(), tmp);
    vector<Vertex> tmp2(inputGraph.getVertices().size(), "");
    paths = vector<vector<Vertex>>(inputGraph.getVertices().size(), tmp2);
    for (Vertex v : inputGraph.getVertices())
    {
        d[inputGraph.getVertexIdx(v)][inputGraph.getVertexIdx(v)] = 0;
    }
    for (auto i : inputGraph.getEdges())
    {
        if (i.weight > 0)
            d[inputGraph.getVertexIdx(i.src)][inputGraph.getVertexIdx(i.dest)] = i.weight;
    }
    for (Vertex v : inputGraph.getVertices())
    {
        for (Vertex u : inputGraph.getVertices())
        {
            if (d[inputGraph.getVertexIdx(v)][inputGraph.getVertexIdx(u)] != 25000)
                paths[inputGraph.getVertexIdx(v)][inputGraph.getVertexIdx(u)] = v;
        }
    }
    for (Vertex w : inputGraph.getVertices())
    {
        for (Vertex u : inputGraph.getVertices())
        {
            for (Vertex v : inputGraph.getVertices())
            {
                int u_idx = inputGraph.getVertexIdx(u);
                int v_idx = inputGraph.getVertexIdx(v);
                int w_idx = inputGraph.getVertexIdx(w);
                if (d[u_idx][v_idx] > d[u_idx][w_idx] + d[w_idx][v_idx])
                {
                    d[u_idx][v_idx] = d[u_idx][w_idx] + d[w_idx][v_idx];
                    paths[u_idx][v_idx] = paths[w_idx][v_idx];
                }
            }
        }
    }
}

/// @brief Travelling through airports that are prominent hubs in a region is extremely fun! Bustling energy, duty-free shopping, and more!
/// We're using the Betweenes Centrality algorithm to find the transit hub,
/// i.e. the most densely/well-connected airport between a Passenger's Point of Departure and Point of Arrival!
/// i.e. to a traveller, we're finding the transit hubs!
/// @param inputGraph adjacency graph
/// @param vertices vector obtained from Algorithms::Path
/// @return return vertex
std::string Algorithms::BetweennessCentrality(const Graph &inputGraph, vector<std::string> vertices)
{
    int max_count = 0;
    std::string central;
    for (auto vertex1 : vertices)
    {
        int count = 0;
        for (auto vertex2 : vertices)
        {
            if (inputGraph.edgeExists(vertex1, vertex2))
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
vector<string> Algorithms::Path(const Graph &inputGraph, Vertex source, Vertex destination)
{
    if (paths[inputGraph.getVertexIdx(source)][inputGraph.getVertexIdx(destination)] == "")
        return {};
    vector<string> path = {destination};

    while (source != destination)
    {
        destination = paths[inputGraph.getVertexIdx(source)][inputGraph.getVertexIdx(destination)];
        path.push_back(destination);
    }
    return path; // path goes to source starting from destination; destination -> -> -> ->....-> ->source
}

/// @brief Kruskal's algorithm is one of the ways in which a Minimum Spanning Tree for a graph is commonly built.
// In the context of our Airports and Routes Graph, a Minimum Spanning Tree is basically a backpacker's gudie to the world:
// The cheapest way to cover the world, the cheapest possible next destination from anywhere they are right now!
/// @param inputGraph : Our original graph of airport and routes data, consistsing of all possible edges, etc.
/// @return : Minimum Spanning Tree of out airports and routes graph.
Graph Algorithms::Kruskal(Graph inputGraph)
{
    //  Disjoint Set setup
    DisjointSets forest;
    vector<Vertex> input_graph_vertices = inputGraph.getVertices();
    std::map<Vertex, int> vertex_to_vertex_num;
    int num_vertices = 0;
    for (int vertex_num = 0; vertex_num < int(input_graph_vertices.size()); vertex_num++)
    {
        vertex_to_vertex_num.insert(std::pair<Vertex, int>(input_graph_vertices.at(vertex_num), vertex_num));
        num_vertices++;
    }
    forest.addelements(num_vertices);

    // Building Priority Queue
    vector<Edge> priorityEdges = inputGraph.getEdges();
    std::sort(priorityEdges.begin(), priorityEdges.end());

    Graph output = Graph(true);
    for (auto vertex : input_graph_vertices)
    {
        output.insertVertex(vertex);
    }

    while (output.getEdges().size() < input_graph_vertices.size() - 1)
    {
        Edge min_edge = priorityEdges.at(0);
        priorityEdges.erase(priorityEdges.begin());
        if (forest.find(vertex_to_vertex_num[min_edge.src]) != forest.find(vertex_to_vertex_num[min_edge.dest]))
        {
            output.insertEdge(min_edge.src, min_edge.dest, min_edge.weight, min_edge.edge_label);
            forest.setunion(forest.find(vertex_to_vertex_num[min_edge.src]), forest.find(vertex_to_vertex_num[min_edge.dest]));
        }
    }
    return output;
}

// /// @brief Kruskal's algorithm is one of the ways in which a Minimum Spanning Tree for a graph is commonly built.
// // In the context of our Airports and Routes Graph, a Minimum Spanning Tree is basically a backpacker's gudie to the world:
// // The cheapest way to cover the world, the cheapest possible next destination from anywhere they are right now!
// /// @param inputGraph : Our original graph of airport and routes data, consistsing of all possible edges, etc.
// /// @return : Minimum Spanning Tree of out airports and routes graph.
// Graph Algorithms::Kruskal(Graph inputGraph) {
//     //  Disjoint Set setup
//     DisjointSets forest;
//     vector<Vertex> input_graph_vertices = inputGraph.getVertices();
//     std::map<Vertex, int> vertex_to_vertex_num;
//     int num_vertices = 0;
//     for (int vertex_num = 0; vertex_num < int(input_graph_vertices.size()); vertex_num++) {
//         vertex_to_vertex_num.insert(std::pair<Vertex, int>(input_graph_vertices.at(vertex_num), vertex_num));
//         num_vertices++;
//     }
//     forest.addelements(num_vertices);

//     // Building Priority Queue
//     vector<Edge> priorityEdges = inputGraph.getEdges();
//     std::sort(priorityEdges.begin(), priorityEdges.end());

//     Graph output = Graph(true);
//     for (auto vertex: input_graph_vertices) {
//         output.insertVertex(vertex);
//     }

//     while (output.getEdges().size() < input_graph_vertices.size() - 1) {
//         Edge min_edge = priorityEdges.at(0);
//         priorityEdges.erase(priorityEdges.begin());
//         if (forest.find(vertex_to_vertex_num[min_edge.src]) != forest.find(vertex_to_vertex_num[min_edge.dest])) {
//             output.insertEdge(min_edge.src, min_edge.dest, min_edge.weight, min_edge.edge_label);
//             forest.setunion(forest.find(vertex_to_vertex_num[min_edge.src]), forest.find(vertex_to_vertex_num[min_edge.dest]));
//         }
//     }
//     return output;
// }