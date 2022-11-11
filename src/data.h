#include <vector>
#include <fstream>
#include <iostream>
#include <string>


using std::ifstream;
using namespace std;

struct line {
    string id;
    string Name;
    string City;
    string Country;
    string IATA;
    string ICAO;
    string Latitude;
    string Longitude;
    string Altitude;
    string Timezone;
    string DST;
    string database; 
    string Type;
    string Source;
};

struct stdata {
    int id;
    string Name;
    string City;
    string Country;
    string IATA;
    string ICAO;
    float Latitude;
    float Longitude;
    int Altitude;
    int Timezone;
    string DST;
    string database; 
    string Type;
    string Source;
};

class Data {
    public:
        Data(string filename);
        vector<stdata> getdata() {return mainstore;}
    private:
        vector<line> store;
        vector<stdata> mainstore;
        void makestdata(vector<line> st);
        
};
