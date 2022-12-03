#include <iostream>
#include <vector>
#include "graph.h"
#include "traversal.h"
#include "../src/graph.h"
#include "../src/algorithms.h"

using namespace std;

int main()
{
    // cout << "MAIN FILE REACHED" << endl;

    Airport_data test("../data/airports.dat");
    vector<airport> tmpdata = test.getdata();

    Route_data test2("../data/routes_subset.dat");
    vector<route> tmp2data = test2.getdata();
    Graph gph(test, test2);

    Traversal trav;
    trav.printgraph(gph);

    Airport_data test_airport1_3("../data/airports.dat");
    Route_data test_routes1_3("../data/routes_subset.dat");
    Graph test_graph_2(test_airport1_3, test_routes1_3);
    Algorithms test_algorithms;
    test_algorithms.Floyd_Warshall(test_graph_2);
    vector<string> path = test_algorithms.Path(test_graph_2, "Goroka Airport", "Mount Hagen Kagamuga Airport");
    std::cout << path[0] << std::endl;

    return 0;
}