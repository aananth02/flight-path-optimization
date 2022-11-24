#include <iostream>
#include <vector>
#include "graph.h"
using namespace std;

int main() {
    // cout << "MAIN FILE REACHED" << endl;

    Airport_data test("../data/airports.dat");
    vector<airport> tmpdata = test.getdata();

    Route_data test2("../data/routes_cleaned.csv");
    vector<route> tmp2data = test2.getdata();
    Graph gph(test, test2);
    
    vector<Vertex> t = gph.getAdjacentDir("Rankin Inlet Airport", 1);
    for (size_t i = 0; i < t.size(); i++) cout << t[i] << endl;


    return 0;
}