#include <vector>
#include <fstream>
#include <iostream>
#include <string>


using std::ifstream;
using namespace std;

struct airport {
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

class Airport_data {
    
    public:
        Airport_data(string filename);
        vector<airport> getdata() {return airport_data;};
    private:
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
        vector<airport> airport_data;
        airport conv_line(line& st);
        // void makedata(vector<line> st);

};

struct airline {
    int id;
    string Name;
    string Alias;
    string IATA;
    string ICAO;
    string Callsign;
    string Country;
    string Active;
};

class Airline_data {
    public:
        Airline_data(string filename);
        vector<airline> getdata() {return airline_data;};
    private:
        vector<airline> airline_data;
        airline conv_line(airline& l);

};

struct route {
    string airline_code;
    int id;
    string source_code;
    int source_id;
    string dest_code;
    int dest_id;
    string Codeshare;
    int Stops;
    string Equipment;
};

class Route_data {
    public:
        Route_data(string filename);
        vector<route> getdata() {return route_data;};
    private:
        vector<route> route_data;
        // route conv_line(route& l);
};