#include <iostream>
#include <vector>
#include <algorithm>
#include "graph.h"
#include "traversal.h"
#include "../src/graph.h"
#include "../src/algorithms.h"
#include <limits.h>
#define V 9
using namespace std;

int main() {

    // Setup: Dataset loading, graph construction, etc.
    Airport_data test_airports("../data/airports.dat");
    Route_data test_routes("../data/routes_subset.dat");
    Graph test_graph(test_airports, test_routes);

    vector<airport> airport_data = test_airports.getdata();
    vector<route> route_data = test_routes.getdata();

    vector<Vertex> vertices = test_graph.getVertices();
    vector<Edge> edges = test_graph.getEdges();
    
    // Traversal testing
    Traversal traversal;
    std::cout << "BFS Ordering: " << std::endl;
    traversal.printgraph(test_graph);

    // Algorithms testing
    Algorithms test_algorithms;
    vector<Edge> edges_copy_to_sort = test_graph.getEdges();
    vector<vector<pair<float, string>>> adjacenecy_matrix = test_graph.getAdjacencyMatrix();
    // std::sort(edges_copy_to_sort.begin(), edges_copy_to_sort.end());

    test_algorithms.Floyd_Warshall(test_graph);
    vector<vector<Vertex>> floyd_output = test_algorithms.getPaths();
    vector<string> path = test_algorithms.Path(test_graph, "Port Moresby Jacksons International Airport", "Madang Airport");
    
    
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Path Size: " << int(path.size()) << std::endl;
    if (path.size() > 0) {
        for (auto st: path) {
            std::cout << st << std::endl;
        }
    }

    for (int path_index = 0; path_index < int(floyd_output.size()); path_index++) {
        for (Vertex vertex : floyd_output.at(path_index)) {
            std::cout << vertex << "-> ";
        }
        std::cout << "\n\n\n" << std::endl;
        std::cout << "-----Path Complete-----" << std::endl;
    }

    // Kruskal Testing

    // Print Edges in sorted order
    std::cout << "\n\nEdges In Sorted Order" << std::endl;
    int counter = 1;
    for (Edge edge: edges_copy_to_sort) {
        std::cout << std::to_string(counter) << ". " << edge.edge_as_string() << std::endl;
        counter++;
    }
    // std::vector<Vertex> x = test_graph.getVer();
    // Printing Adjacenecy Matrix
    // for (size_t i = 0; i < x.size(); i++) {
    //     cout << x[i] << " | ";
    // }
    std::cout << "\n\nAdjacency Matrix" << std::endl;
    for (size_t i = 0; i < adjacenecy_matrix.size(); i++) {
        for (size_t j = 0; j < adjacenecy_matrix[i].size(); j++) {
            pair<float, string> point = adjacenecy_matrix[i][j];
            std::cout << std::to_string(point.first) << ", " << point.second << " | ";
        }
        std::cout << "\n";
    }
    return 0;
}
