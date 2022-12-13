#include <catch2/catch_test_macros.hpp>

using namespace std;
#include "../src/traversal.h"

// There are subset data files created for small test : routes_subset

Airport_data test_airport1_2("../data/airports.dat");
Route_data test_routes1_2("../data/routes_subset.dat");
Graph test_graph_1(test_airport1_2, test_routes1_2);

TEST_CASE("BFS Traversal Edge Label Check", "[traversal][edge-label-check]") {
    // Initial set-up
    Airport_data test_airport("../data/airports.dat");
    Route_data test_routes("../data/routes_subset.dat");
    Graph test_graph(test_airport1_2, test_routes1_2);

    // Traversal set-up
    Traversal traversal;
    traversal.BFS(test_graph);
    map<Vertex, string> vertex_labels = traversal.getVertexLabels();
    map<Edge, string> edge_labels = traversal.getEdgeLabels();
    
    // Assertions
    for (Edge edge: test_graph.getEdges()) {
        if (edge.src == "Goroka Airport" && edge.dest == "Madang Airport") REQUIRE(edge_labels[edge] == "DISCOVERY");
        if (edge.src == "Goroka Airport" && edge.dest == "Mount Hagen Kagamuga Airport") REQUIRE(edge_labels[edge] == "DISCOVERY");
        if (edge.src == "Goroka Airport" && edge.dest == "Nadzab Airport") REQUIRE(edge_labels[edge] == "DISCOVERY");
        if (edge.src == "Goroka Airport" && edge.dest == "Port Moresby Jacksons International Airport") REQUIRE(edge_labels[edge] == "DISCOVERY");
        if (edge.src == "Madang Airport" && edge.dest == "Wewak International Airport") REQUIRE(edge_labels[edge] == "DISCOVERY");

        if (edge.src == "Mount Hagen Kagamuga Airport" && edge.dest == "Nadzab Airport") REQUIRE(edge_labels[edge] == "CROSS");
        if (edge.src == "Nadzab Airport" && edge.dest == "Madang Airport") REQUIRE(edge_labels[edge] == "CROSS");
        if (edge.src == "Port Moresby Jacksons International Airport" && edge.dest == "Mount Hagen Kagamuga Airport") REQUIRE(edge_labels[Edge(edge)] == "CROSS");
        if (edge.src == "Port Moresby Jacksons International Airport" && edge.dest == "Nadzab Airport") REQUIRE(edge_labels[Edge(edge)] == "CROSS");
    }

}

TEST_CASE("BFS on a Tree", "[graph][bfs][no-cross-edges]") {
    // Initial set-up
    Airport_data test_airport("../data/airports.dat");
    Route_data test_routes("../data/routes_subset_as_tree.dat");
    Graph test_graph(test_airport, test_routes);

    // Traversal set-up
    Traversal traversal;
    traversal.BFS(test_graph);
    map<Vertex, string> vertex_labels = traversal.getVertexLabels();
    map<Edge, string> edge_labels = traversal.getEdgeLabels();

    // Assertions
    int counter = 1;

    for (Edge edge: test_graph.getEdges()) {
        if (edge_labels[edge] == "CROSS") std::cout << "BFS " << std::to_string(counter) << ". " << edge.edge_as_string() << " | BFS Label: " << edge_labels[edge] << std::endl;
        REQUIRE(edge_labels[edge] != "CROSS");
        counter++;
    }
}


// Cleaned Dataset for overall graph testing : routes_cleaned.csv
// Tests on Larger Dataset
// Note: These tests take a long time to compile and run

// TEST_CASE("Large BFS Traversal", "[traversal]") {
//     Traversal trav;
//     Route_data test_routes2_2("../data/routes_cleaned.csv");
//     Graph test_graph_large_1(test_airport1_2, test_routes2_2);
//     // Need to implement this test case
//     REQUIRE(true);
// }
