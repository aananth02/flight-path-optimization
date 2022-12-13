#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <string>

using namespace std;
#include "../src/graph.h"

// There are subset data files created for small test : routes_subset

Airport_data test_airport1("../data/airports.dat");
Route_data test_routes1("../data/routes_subset.dat");
Graph test_graph(test_airport1, test_routes1);

TEST_CASE("Graph Creation Small", "[graph]")
{
    REQUIRE(test_graph.getVertices().size() == 6);
    REQUIRE(test_graph.getEdges().size() == 9);
    REQUIRE(test_graph.isDirected());
}

TEST_CASE("Node Adjacency Small", "[graph]")
{
    vector<string> Goroka_adjacent{"Mount Hagen Kagamuga Airport", "Nadzab Airport", "Madang Airport", "Port Moresby Jacksons International Airport"};
    vector<Vertex> adj = test_graph.getAdjacentDir("Goroka Airport", 1);
    for (size_t i = 0; i < adj.size(); i++)
    {
        REQUIRE(adj[i] == Goroka_adjacent[i]);
    }
}

TEST_CASE("Edge Weights and Labels Small", "[graph]")
{
    vector<Edge> edges = test_graph.getEdges();
    vector<float> weights = {distance(-6.081689834590001, 145.391998291, -5.826789855957031, 144.29600524902344),
                             distance(-6.081689834590001, 145.391998291, -6.569803, 146.725977),
                             distance(-6.081689834590001, 145.391998291, -5.20707988739, 145.789001465),
                             distance(-6.081689834590001, 145.391998291, -9.443380355834961, 147.22000122070312)};
    vector<string> labels = {"CG", "CG", "CG", "CG"};
    for (size_t i = 0; i < edges.size(); i++)
    {
        REQUIRE(edges[i].weight == weights[i]);
    }
    for (size_t i = 0; i < edges.size(); i++)
    {
        REQUIRE(edges[i].edge_label == labels[i]);
    }
}

// Cleaned Dataset for overall graph testing : routes_cleaned.csv
// Tests on Larger Dataset
// Note: These tests take a long time to compile and run

Route_data test_routes2("../data/routes_cleaned.csv");
Graph test_graph_large(test_airport1, test_routes2);

TEST_CASE("Graph Creation Large", "[graph]")
{
    REQUIRE(test_graph_large.getVertices().size() == 1631);
    REQUIRE(test_graph_large.getEdges().size() == 10806);
    REQUIRE(test_graph_large.isDirected());
}

TEST_CASE("Node Adjacency Large", "[graph]")
{
    vector<string> Rankin_Adj_source{"Baker Lake Airport", "Chesterfield Inlet Airport", "Churchill Airport",
                                     "Repulse Bay Airport", "Coral Harbour Airport", "Yellowknife Airport"};
    vector<Vertex> adj = test_graph_large.getAdjacentDir("Rankin Inlet Airport", 1);
    for (size_t i = 0; i < adj.size(); i++)
    {
        REQUIRE(adj[i] == Rankin_Adj_source[i]);
    }
}

TEST_CASE("Edge Weights and Labels Large", "[graph]")
{

    vector<float> weights = {distance(68.78170013427734, 32.75080108642578, 69.68329620361328, 18.918899536132812),
                             distance(-43.48939895629883, 172.53199768066406, -41.298301696777344, 173.2209930419922)};
    vector<string> labels = {"5N", "NZ"};

    Edge MMK_TOS = test_graph_large.getEdge("Murmansk Airport", "Tromsø Airport,");
    Edge CHC_NSN = test_graph_large.getEdge("Christchurch International Airport", "Nelson Airport");
    Edge NO_EXIST = test_graph_large.getEdge("Busselton Regional Airport", "Christchurch International Airport");

    REQUIRE(MMK_TOS.weight == weights[0]);
    REQUIRE(CHC_NSN.weight == weights[1]);
    REQUIRE(int(NO_EXIST.weight) == 0);

    REQUIRE(MMK_TOS.edge_label == labels[0]);
    REQUIRE(CHC_NSN.edge_label == labels[1]);
    REQUIRE(NO_EXIST.edge_label == "");
}
