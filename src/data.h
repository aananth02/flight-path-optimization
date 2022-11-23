#pragma once
#include <vector>
#include <fstream>
#include <iostream>
#include <string>


using std::ifstream;
using namespace std;

// Airports are the nodes in the graph

struct airport {
    // This struct is how every airport's data is read
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
    // Used to fetch data for airport data
    
    public:
        Airport_data(string filename);
        vector<airport> getdata() {return airport_data;};

        float getLatitude(int id);
        float getLatitude(string Name);
        float getLongitude(int id);
        float getLongitude(string Name);
        string getName(int id);
    private:
        struct line {
            // This is a placeholder for the above struct to simply the extraction process
            // In the contructor once processed we create an aiport struct and push it to the vector
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


// The main purpose of airlines is for the user, so while printing out results we can provide airline information as well
// We can use the id, name for finding the airline while printing

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

// The routes are the edges of the graph

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