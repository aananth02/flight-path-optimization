#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <string>

using namespace std;
#include "../src/graph.h"
#include "../src/algorithms.h"

// There are subset data files created for small test : routes_subset

Airport_data test_airport1_3("../data/airports.dat");
Route_data test_routes1_3("../data/routes_subset.dat");
Graph test_graph_2(test_airport1_3, test_routes1_3);
Algorithms test_algorithms;

// test_algorithms

// FLOYD TESTING
TEST_CASE("Path Doesn't Exist Small", "[graph]")
{
    test_algorithms.Floyd_Warshall(test_graph_2);
    REQUIRE(test_algorithms.Path(test_graph_2, "Mount Hagen Kagamuga Airport", "Goroka Airport").size() == 0); // Direction Check
    REQUIRE(test_algorithms.Path(test_graph_2, "Madang Airport", "Mount Hagen Kagamuga Airport").size() == 0); // No Edge Check
}

TEST_CASE("Path Connected To Itself", "[graph]")
{
    vector<string> path = test_algorithms.Path(test_graph_2, "Goroka Airport", "Geroka Airport");
    REQUIRE(path.size() == 0);
}

TEST_CASE("Path Multiple Edges", "[graph]")
{
    test_algorithms.Floyd_Warshall(test_graph_2);
    vector<string> path = test_algorithms.Path(test_graph_2, "Port Moresby Jacksons International Airport", "Madang Airport");
    REQUIRE(path.size() == 3);
    REQUIRE(path[0] == "Port Moresby Jacksons International Airport");
    REQUIRE(path[1] == "Nadzab Airport");
    REQUIRE(path[2] == "Madang Airport");
}
TEST_CASE("Path More Edges", "[graph]")
{
    test_algorithms.Floyd_Warshall(test_graph_2);
    vector<string> path = test_algorithms.Path(test_graph_2, "Port Moresby Jacksons International Airport", "Wewak International Airport");
    REQUIRE(path.size() == 4);
    REQUIRE(path[0] == "Port Moresby Jacksons International Airport");
    REQUIRE(path[1] == "Nadzab Airport");
    REQUIRE(path[2] == "Madang Airport");
    REQUIRE(path[3] == "Wewak International Airport");
}

TEST_CASE("Single Path Test", "[graph]")
{
    test_algorithms.Floyd_Warshall(test_graph_2);
    vector<string> path = test_algorithms.Path(test_graph_2, "Goroka Airport", "Madang Airport");
    REQUIRE(path.size() == 2);
    REQUIRE(path[0] == "Goroka Airport");
    REQUIRE(path[1] == "Madang Airport");
}

// Kruskal's TESTING

TEST_CASE("Kruskal's", "[kruskal][graph]")
{
    Graph MST = test_algorithms.Kruskal(test_graph_2);
    vector<Edge> mst_edges = MST.getEdges();

    int counter = 1;
    for (Edge edge : mst_edges)
    {
        std::cout << std::to_string(counter) << ". " << edge.edge_as_string() << std::endl;
        counter++;
    }

    REQUIRE(MST.edgeExists("Goroka Airport", "Madang Airport"));
    REQUIRE(MST.edgeExists("Goroka Airport", "Mount Hagen Kagamuga Airport"));
    REQUIRE(MST.edgeExists("Goroka Airport", "Nadzab Airport"));
    REQUIRE(MST.edgeExists("Madang Airport", "Wewak International Airport"));
    REQUIRE(MST.edgeExists("Port Moresby Jacksons International Airport", "Nadzab Airport"));
}

// TEST_CASE("Path Multiple Edges", "[graph]") {
//     vector<string> path = test_algorithms.Path(test_graph_2, "Goroka Airport", "Mount Hagen Kagamuga Airport");
//     REQUIRE(path.size() == 1);
//     REQUIRE(path[0] == "Goroka Airport");
//     REQUIRE(path[1] == "Mount Hagen Kagamuga Airport");
// }

// Cleaned Dataset for overall graph testing : routes_cleaned.csv
// Tests on Larger Dataset
// Note: These tests take a long time to compile and run

// Route_data test_routes2_3("../data/routes_cleaned.csv");
// Graph test_graph_large_2(test_airport1_3, test_routes2_3);
// Algorithms test_algorithms1;

// TEST_CASE("Path Doesn't Exist Small", "[graph]") {
// test_algorithms1.Floyd_Warshall(test_graph_large_2);
//     REQUIRE(test_algorithms.Path(test_graph, "Mount Hagen Kagamuga Airport", "Goroka Airport").size() == 0);        // Direction Check
//     REQUIRE(test_algorithms.Path(test_graph, "Madang Airport", "Mount Hagen Kagamuga Airport").size() == 0);        // No Edge Check
// }

// TEST_CASE("Path Single Edge", "[graph]") {
// test_algorithms1.Floyd_Warshall(test_graph_large_2);
//     vector<string> path = test_algorithms.Path(test_graph, "Goroka Airport", "Mount Hagen Kagamuga Airport");
//     REQUIRE(path.size() == 1);
//     REQUIRE(path[0] == "Goroka Airport");
//     REQUIRE(path[1] == "Mount Hagen Kagamuga Airport");
// }

// TEST_CASE("Path Multiple Edges", "[graph]") {
// test_algorithms1.Floyd_Warshall(test_graph_large_2);
//     vector<string> path = test_algorithms.Path(test_graph, "Goroka Airport", "Mount Hagen Kagamuga Airport");
//     REQUIRE(path.size() == 1);
//     REQUIRE(path[0] == "Goroka Airport");
//     REQUIRE(path[1] == "Mount Hagen Kagamuga Airport");
// }
