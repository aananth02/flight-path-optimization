#include <catch2/catch_test_macros.hpp>

using namespace std;
#include "../src/traversal.h"

// There are subset data files created for small test : routes_subset

Airport_data test_airport1("../data/airports.dat");
Route_data test_routes1("../data/routes_subset.dat");
Graph test_graph(test_airport1, test_routes1);

TEST_CASE("Small BFS Traversal", "[traversal]") {
    Traversal trav;
    // Need to implement this test case
    REQUIRE(true);
}

// Cleaned Dataset for overall graph testing : routes_cleaned.csv
// Tests on Larger Dataset
// Note: These tests take a long time to compile and run

Route_data test_routes2("../data/routes_cleaned.csv");
Graph test_graph_large(test_airport1, test_routes2);

TEST_CASE("Large BFS Traversal", "[traversal]") {
    Traversal trav;
    // Need to implement this test case
    REQUIRE(true);
}
