#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <string>

using namespace std;
#include "../src/graph.h"
// There are subset data files created for small test : routes_subset

Airport_data test_airport1("../data/airports.dat");
vector<airport> tmpairport1 = test_airport1.getdata();

// Airline_data test_data1("../data/airlines.dat");
// vector<airline> tmpdata1 = test_data.getdata();

Route_data test_routes1("../data/routes_subset.dat");
vector<route> tmproutes1 = test_routes1.getdata();

Graph test_graph(test_airport1, test_routes1);

TEST_CASE("Graph Creation Small", "[graph]") {
    REQUIRE(test_graph.getVertices().size() == 5);
    REQUIRE(test_graph.getEdges().size() == 4);
    REQUIRE(test_graph.isDirected());
}

TEST_CASE("Node Adjacency Small", "[graph]") {
    vector<string> Goroka_adjacent{"Mount Hagen Kagamuga Airport", "Nadzab Airport", "Madang Airport", "Port Moresby Jacksons International Airport"};
    vector<Vertex> adj = test_graph.getAdjacentDir("Goroka Airport", 1);
    for (size_t i = 0; i < adj.size(); i++) {
        REQUIRE(adj[i] == Goroka_adjacent[i]);
    }
}

TEST_CASE("Edge Weights and Labels Small", "[graph]") {
    vector<Edge> edges = test_graph.getEdges();
    vector<float> weights = {distance(-6.081689834590001, 145.391998291, -5.826789855957031, 144.29600524902344), 
                            distance(-6.081689834590001, 145.391998291, -6.569803, 146.725977), 
                            distance(-6.081689834590001, 145.391998291, -5.20707988739, 145.789001465), 
                            distance(-6.081689834590001, 145.391998291, -9.443380355834961, 147.22000122070312)};
    vector<string> labels = {"CG", "CG", "CG", "CG"};
    for (size_t i = 0; i < edges.size(); i++) {
        REQUIRE(edges[i].weight == weights[i]);
    }
    for (size_t i = 0; i < edges.size(); i++) {
        REQUIRE(edges[i].edge_label == labels[i]);
    }
}

// Cleaned Dataset for overall graph testing : routes_cleaned.csv
// More elaborate tests