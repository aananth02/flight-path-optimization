#include <catch2/catch_test_macros.hpp>

using namespace std;
#include "../src/traversal.h"

// There are subset data files created for small test : routes_subset

Airport_data test_airport1_2("../data/airports.dat");
Route_data test_routes1_2("../data/routes_subset.dat");
Graph test_graph_1(test_airport1_2, test_routes1_2);

TEST_CASE("Small BFS Traversal", "[traversal][edge-label-check]") {
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
    REQUIRE(edge_labels[Edge("Goroka Airport", "Madang Airport")] == "DISCOVERY");
    REQUIRE(edge_labels[Edge("Goroka Airport", "Mount Hagen Kagamuga Airport")] == "DISCOVERY");
    REQUIRE(edge_labels[Edge("Goroka Airport", "Nadzab Airport")] == "DISCOVERY");
    REQUIRE(edge_labels[Edge("Goroka Airport", "Port Moresby Jacksons International Airport")] == "DISCOVERY");
    REQUIRE(edge_labels[Edge("Madang Airport", "Wewak International Airport")] == "DISCOVERY");
    
    REQUIRE(edge_labels[Edge("Mount Hagen Kagamuga Airport", "Nadzab Airport")] == "CROSS");
    REQUIRE(edge_labels[Edge("Nadzab Airport", "Madang Airport")] == "CROSS");
    REQUIRE(edge_labels[Edge("Port Moresby Jacksons International Airport", "Mount Hagen Kagamuga Airportt")] == "CROSS");
    REQUIRE(edge_labels[Edge("Port Moresby Jacksons International Airport", "Nadzab Airport")] == "CROSS");

}

TEST_CASE("BFS on a Tree", "[graph][bfs][no-cross-edges]") {
    // Initial set-up
    Airport_data test_airport("../data/airports.dat");
    Route_data test_routes("../data/routes_subset_as_tree.dat");
    Graph test_graph(test_airport1_2, test_routes1_2);

    // Traversal set-up
    Traversal traversal;
    traversal.BFS(test_graph);
    map<Vertex, string> vertex_labels = traversal.getVertexLabels();
    map<Edge, string> edge_labels = traversal.getEdgeLabels();

    // Assertions
    for (Edge edge: test_graph.getEdges()) {
        REQUIRE(edge_labels[edge] != "CROSS");
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
