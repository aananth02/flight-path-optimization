#include <iostream>
#include "graph.h"
using namespace std;

int main() {
    // cout << "MAIN FILE REACHED" << endl;

    Airport_data test("../data/airport_subset.dat");
    // vector<airport> tmpdata = test.getdata();
    // cout << tmpdata.size() << endl;
    // cout << tmpdata[tmpdata.size() - 1].Name << endl;

    Airline_data test1("../data/airlines.dat");
    // vector<airline> tmp1data = test1.getdata();
    // cout << tmp1data.size() << endl;
    // cout << tmp1data[tmp1data.size() - 1].Name << endl;

    Route_data test2("../data/routes_subset.dat");
    // vector<route> tmp2data = test2.getdata();
    // cout << tmp2data.size() << endl;
    // cout << tmp2data[tmp2data.size() - 1].airline_code << endl;
    Graph gph(test, test2);
    
    vector<Vertex> t = gph.getAdjacentDir("Goroka Airport", 1);
    for (size_t i = 0; i < t.size(); i++) cout << t[i] << endl;
    return 0;
}