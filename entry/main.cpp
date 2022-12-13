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

int main()
{

    // Setup: Dataset loading, graph construction, etc.
    Airport_data test_airports("../data/airports.dat");
    Route_data test_routes("../data/routes_subset.dat");
    Graph test_graph(test_airports, test_routes);

    vector<airport> airport_data = test_airports.getdata();
    vector<route> route_data = test_routes.getdata();

    vector<Vertex> vertices = test_graph.getVertices();
    vector<Edge> edges = test_graph.getEdges();

    //---------------------Graph Implementation Potential Demo-----------------------
    // Prints Adjacency Matrix
    // std::vector<Vertex> x = test_graph.getVer();
    // Printing Adjacenecy Matrix
    // for (size_t i = 0; i < x.size(); i++) {
    //     cout << x[i] << " | ";
    // }
    // std::cout << "\n\nAdjacency Matrix" << std::endl;
    // for (size_t i = 0; i < adjacency_matrix.size(); i++)
    // {
    //     for (size_t j = 0; j < adjacency_matrix[i].size(); j++)
    //     {
    //         pair<float, string> point = adjacency_matrix[i][j];
    //         std::cout << std::to_string(point.first) << ", " << point.second << " | ";
    //     }
    //     std::cout << "\n";
    // }

    // Traversal testing
    Traversal traversal;
    std::cout << "BFS Testing: Printing Nodes in BFS Ordering" << std::endl;
    traversal.printgraph(test_graph);
    std::cout << "\n"
              << std::endl;

    // Algorithms testing

    Algorithms test_algorithms;
    vector<Edge> edges_copy_to_sort = test_graph.getEdges();
    vector<vector<pair<float, string>>> adjacency_matrix = test_graph.getAdjacencyMatrix();
    std::sort(edges_copy_to_sort.begin(), edges_copy_to_sort.end());

    // test_algorithms.Floyd_Warshall(test_graph);
    // vector<vector<Vertex>> floyd_output = test_algorithms.getPaths();
    // vector<string> path = test_algorithms.Path(test_graph, "Port Moresby Jacksons International Airport", "Madang Airport");

    // std::cout << "-------------------------------------------------" << std::endl;
    // std::cout << "Path Size: " << int(path.size()) << std::endl;
    // if (path.size() > 0)
    // {
    //     for (auto st : path)
    //     {
    //         std::cout << st << std::endl;
    //     }
    // }

    // for (int path_index = 0; path_index < int(floyd_output.size()); path_index++)
    // {
    //     for (Vertex vertex : floyd_output.at(path_index))
    //     {
    //         std::cout << vertex << "-> ";
    //     }
    //     std::cout << "\n\n\n"
    //               << std::endl;
    //     std::cout << "-----Path Complete-----" << std::endl;
    // }

    // // Kruskal Testing

    // Print Edges in sorted order
    std::cout << "-----MST Demo-----" << std::endl;
    std::cout << std::endl;
    Graph MST = test_algorithms.Kruskal(test_graph);
    vector<Edge> mst_edges = MST.getEdges();

    int counter = 1;
    for (Edge edge : mst_edges)
    {
        std::cout << std::to_string(counter) << ". " << edge.edge_as_string() << std::endl;
        counter++;
    }
    std::cout << std::endl;

    // Airport_data test_airport1_3("../data/airports.dat");
    // Route_data test_routes1_3("../data/routes_subset.dat");
    // Graph test_graph_2(test_airport1_3, test_routes1_3);
    // Algorithms test_algorithms;
    // std::cout << "-----Path2 Complete-----" << std::endl;
    // test_algorithms.Floyd_Warshall(test_graph_2);
    // vector<string> path = test_algorithms.Path(test_graph_2, "Port Moresby Jacksons International Airport", "Madang Airport");
    // vector<string> path2 = test_algorithms.Path(test_graph_2, "Port Moresby Jacksons International Airport", "Wewak International Airport");
    // for (auto airport : path2)
    // {
    //     std::cout << airport << std::endl;
    // }

    // REQUIRE(path.size() == 3);
    // REQUIRE(path[0] == "Port Moresby Jacksons International Airport");
    // REQUIRE(path[1] == "Nadzab Airport");
    // REQUIRE(path[2] == "Madang Airport");
    // std::cout << test_algorithms.BetweennessCentrality(test_graph_2, path2) << std::endl;

    // -----------------------------------------------Demo Code Begins Here----------------------------------------

    // shortest path
    std::cout << "-----Shortest Path Demo-----" << std::endl;
    std::cout << std::endl;
    Airport_data test_airport1_3("../data/airports.dat");
    Route_data test_routes1_3("../data/routes_subset.dat");
    Graph test_graph_2(test_airport1_3, test_routes1_3);
    // Algorithms test_algorithms;
    test_algorithms.Floyd_Warshall(test_graph_2);
    char source[60];
    char dest[60];
    cout << "Enter source airport name: ";

    // Examples airport names (feel free to add more if you want to)
    // Port Moresby Jacksons International Airport
    // Wewak International Airport
    // Goroka Airport

    cin.getline(source, 60);
    cout << "Enter destination airport name: ";
    cin.getline(dest, 60);
    vector<string> path = test_algorithms.Path(test_graph_2, source, dest);
    std::cout << "Shortest path from " << source << " to " << dest << " is " << path.size() << " steps-: " << std::endl;
    if (path.empty())
    {
        std::cout << "Path does not exist" << std::endl;
    }
    else
    {
        for (auto airport : path)
        {
            std::cout << airport << " -> ";
        }
        std::cout << "reached" << std::endl;
    }
    std::cout << std::endl;

    // betweeness centrality
    std::cout << std::endl;
    std::cout << "-----Betweeness Centrality Demo-----" << std::endl;
    std::cout << std::endl;
    std::cout << "The most prominent transit hub is " << test_algorithms.BetweennessCentrality(test_graph_2, path).central << " as it is connected to " << test_algorithms.BetweennessCentrality(test_graph_2, path).maxCount << " ports" << std::endl;

    // minimum spanning tree
    std::cout << std::endl;

    return 0;
}
