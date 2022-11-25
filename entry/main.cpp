#include <iostream>
#include <vector>
#include "graph.h"
#include "traversal.h"
using namespace std;

int main() {
    // cout << "MAIN FILE REACHED" << endl;

    Airport_data test("../data/airports.dat");
    vector<airport> tmpdata = test.getdata();

    Route_data test2("../data/routes_subset.dat");
    vector<route> tmp2data = test2.getdata();
    Graph gph(test, test2);
    
    Traversal trav;
    trav.printgraph(gph);



    return 0;
}