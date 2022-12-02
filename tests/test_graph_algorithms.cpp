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
TEST_CASE("Path Doesn't Exist Small", "[graph]")
{
    test_algorithms.Floyd_Warshall(test_graph_2);
    REQUIRE(test_algorithms.Path(test_graph_2, "Mount Hagen Kagamuga Airport", "Goroka Airport").size() == 0); // Direction Check
    REQUIRE(test_algorithms.Path(test_graph_2, "Madang Airport", "Mount Hagen Kagamuga Airport").size() == 0); // No Edge Check
}

TEST_CASE("Path Single Edge", "[graph]")
{
    test_algorithms.Floyd_Warshall(test_graph_2);
    vector<string> path = test_algorithms.Path(test_graph_2, "Goroka Airport", "Mount Hagen Kagamuga Airport");
    REQUIRE(path.size() == 1);
    REQUIRE(path[0] == "Goroka Airport");
    REQUIRE(path[1] == "Mount Hagen Kagamuga Airport");
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

Route_data test_routes2_3("../data/routes_cleaned.csv");
Graph test_graph_large_2(test_airport1_3, test_routes2_3);
Algorithms test_algorithms1;

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