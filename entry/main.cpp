#include <iostream>
#include "data.h"
using namespace std;

int main() {
    // cout << "MAIN FILE REACHED" << endl;

    Data test("../data/airports.dat");
    vector<stdata> tmpdata = test.getdata();
    cout << tmpdata.size() << endl;

    cout << tmpdata[tmpdata.size() - 1].Name << endl;
    return 0;
}