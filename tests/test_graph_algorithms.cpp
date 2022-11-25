#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <string>

using namespace std;
#include "../src/graph.h"
#include "../src/algorithms.h"

// There are subset data files created for small test : routes_subset

Airport_data test_airport1("../data/airports.dat");
Route_data test_routes1("../data/routes_subset.dat");
Graph test_graph(test_airport1, test_routes1);
Algorithms test_algorithms;

test_algorithms.Floyd_Warshall(test_graph);
TEST_CASE("Path Doesn't Exist Small", "[graph]") {
    REQUIRE(test_algorithms.Path(test_graph, "Mount Hagen Kagamuga Airport", "Goroka Airport").size() == 0);        // Direction Check
    REQUIRE(test_algorithms.Path(test_graph, "Madang Airport", "Mount Hagen Kagamuga Airport").size() == 0);        // No Edge Check
}

TEST_CASE("Path Single Edge", "[graph]") {
    vector<string> path = test_algorithms.Path(test_graph, "Goroka Airport", "Mount Hagen Kagamuga Airport");
    REQUIRE(path.size() == 1);
    REQUIRE(path[0] == "Goroka Airport");
    REQUIRE(path[1] == "Mount Hagen Kagamuga Airport");
}

// TEST_CASE("Path Multiple Edges", "[graph]") {
//     vector<string> path = test_algorithms.Path(test_graph, "Goroka Airport", "Mount Hagen Kagamuga Airport");
//     REQUIRE(path.size() == 1);
//     REQUIRE(path[0] == "Goroka Airport");
//     REQUIRE(path[1] == "Mount Hagen Kagamuga Airport");
// }

// Cleaned Dataset for overall graph testing : routes_cleaned.csv
// Tests on Larger Dataset
// Note: These tests take a long time to compile and run

Route_data test_routes2("../data/routes_cleaned.csv");
Graph test_graph_large(test_airport1, test_routes2);
Algorithms test_algorithms1;

test_algorithms1.Floyd_Warshall(test_graph_large);

// TEST_CASE("Path Doesn't Exist Small", "[graph]") {
//     REQUIRE(test_algorithms.Path(test_graph, "Mount Hagen Kagamuga Airport", "Goroka Airport").size() == 0);        // Direction Check
//     REQUIRE(test_algorithms.Path(test_graph, "Madang Airport", "Mount Hagen Kagamuga Airport").size() == 0);        // No Edge Check
// }

// TEST_CASE("Path Single Edge", "[graph]") {
//     vector<string> path = test_algorithms.Path(test_graph, "Goroka Airport", "Mount Hagen Kagamuga Airport");
//     REQUIRE(path.size() == 1);
//     REQUIRE(path[0] == "Goroka Airport");
//     REQUIRE(path[1] == "Mount Hagen Kagamuga Airport");
// }

// TEST_CASE("Path Multiple Edges", "[graph]") {
//     vector<string> path = test_algorithms.Path(test_graph, "Goroka Airport", "Mount Hagen Kagamuga Airport");
//     REQUIRE(path.size() == 1);
//     REQUIRE(path[0] == "Goroka Airport");
//     REQUIRE(path[1] == "Mount Hagen Kagamuga Airport");
// }