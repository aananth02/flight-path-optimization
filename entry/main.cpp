#include <iostream>
#include <vector>
#include "graph.h"
#include "traversal.h"
#include "../src/graph.h"
#include "../src/algorithms.h"
#include <limits.h>
#define V 9
using namespace std;

int main() {

    cout << "MAIN FILE REACHED" << endl;

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
    vector<vector<Vertex>> floyd_output = test_algorithms.getPaths();
    vector<string> path = test_algorithms.Path(test_graph_2, "Goroka Airport", "Nadzab Airport");
    std::cout << "-------------------------------------------------" << std::endl;
    std::cout << "Path Size: " << int(path.size()) << std::endl;
    if (path.size() > 0) {
        for (auto st: path) {
            std::cout << st << std::endl;
        }
    }

    for (int path_index = 0; path_index < int(floyd_output.size()); path_index++) {
        for (Vertex vertex : floyd_output.at(path_index)) {
            std::cout << vertex << "-> ";
        }
        std::cout << "\n\n\n" << std::endl;
        std::cout << "-----Path Complete-----" << std::endl;
    }
    

   
    return 0;
}
