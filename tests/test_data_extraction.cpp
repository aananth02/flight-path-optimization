#include <catch2/catch_test_macros.hpp>

#include <iostream>
#include <string>

#include "data.h"

using namespace std;

Airport_data test_airport("../data/airports.dat");
vector<airport> tmpairport = test_airport.getdata();

Airline_data test_data("../data/airlines.dat");
vector<airline> tmpdata = test_data.getdata();

Route_data test_routes("../data/routes.dat");
vector<route> tmproutes = test_routes.getdata();

// TEST_CASE("Sample Test Case - Data Extraction", "[data]") {
//     REQUIRE(true);
// }

TEST_CASE("Airport Data Extraction", "[data]") {
    REQUIRE(tmpairport[0].Name == "Goroka Airport");
    REQUIRE(tmpairport[0].Latitude == float(-6.081689834590001));
    REQUIRE(tmpairport[0].Longitude == float(145.391998291));
    // If we reach the final row, then that means we have parsed the data correctly
    REQUIRE(tmpairport[tmpairport.size() - 1].Name == "Melitopol Air Base");
    REQUIRE(tmpairport[tmpairport.size() - 1].Latitude == float(46.880001));
    REQUIRE(tmpairport[tmpairport.size() - 1].Longitude == float(35.305));
}

TEST_CASE("Airlines Data Extraction", "[data]") {
    REQUIRE(tmpdata[0].id == -1);
    REQUIRE(tmpdata[0].Name == "Unknown");
    REQUIRE(tmpdata[0].Alias == ""); // \N gets removed in our implementation to become an empty string
    REQUIRE(tmpdata[1].id == 1);
    REQUIRE(tmpdata[1].Name == "Private flight");
    REQUIRE(tmpdata[1].Alias == "");
    // If we reach the final row, then that means we have parsed the data correctly
    REQUIRE(tmpdata[tmpdata.size() - 1].id == 21317);
    REQUIRE(tmpdata[tmpdata.size() - 1].Name == "Svyaz Rossiya");
    REQUIRE(tmpdata[tmpdata.size() - 1].Alias == "Russian Commuter ");
}

TEST_CASE("Routes Data Extraction", "[data]") {
    REQUIRE(tmproutes[0].airline_code == "2B");
    REQUIRE(tmproutes[0].dest_code == "KZN");
    REQUIRE(tmproutes[0].dest_id == 2990);
    // If we reach the final row, then that means we have parsed the data correctly
    REQUIRE(tmproutes[tmproutes.size() - 1].airline_code == "ZM");
    REQUIRE(tmproutes[tmproutes.size() - 1].dest_code == "FRU");
    REQUIRE(tmproutes[tmproutes.size() - 1].dest_id == 2912);
}