#include "data.h"

Airport_data::Airport_data(string filename) {
    vector<line> store;
    ifstream wordsFile(filename);
    if (wordsFile.is_open()) {
        line l;
        while (getline(wordsFile, l.id, ',')) {
            getline(wordsFile, l.Name, ',');
            if (l.Name[l.Name.size() - 1] != '"') {
                string t;
                getline(wordsFile, t, ',');
                l.Name += ',' + t;
            }

            getline(wordsFile, l.City, ',');
            if (l.City[l.City.size() - 1] != '"') {
                string t;
                getline(wordsFile, t, ',');
                l.City += ',' + t;
            }

            getline(wordsFile, l.Country, ',');
            getline(wordsFile, l.IATA, ',');
            getline(wordsFile, l.ICAO, ',');
            getline(wordsFile, l.Latitude, ',');
            getline(wordsFile, l.Longitude, ',');
            getline(wordsFile, l.Altitude, ',');
            getline(wordsFile, l.Timezone, ',');
            getline(wordsFile, l.DST, ',');
            getline(wordsFile, l.database, ',');
            getline(wordsFile, l.Type, ',');
            getline(wordsFile, l.Source, '\n');
            airport x = conv_line(l);
            airport_data.push_back(x);
            line l;
        }
    } else {
        cout << "Error opening file" << endl;
    }
}

airport Airport_data::conv_line(line& st) {
    airport tmp;
    tmp.id = stoi(st.id);

    tmp.Name = st.Name.substr(1, st.Name.size() - 2);
    tmp.City = st.City.substr(1, st.City.size() - 2);
    tmp.Country = st.Country.substr(1, st.Country.size() - 2);
    tmp.IATA = st.IATA.substr(1, st.IATA.size() - 2);
    tmp.ICAO = st.ICAO.substr(1, st.ICAO.size() - 2);

    tmp.Latitude = stof(st.Latitude);
    tmp.Longitude = stof(st.Longitude);
    tmp.Altitude = stoi(st.Altitude);
    if (st.Timezone != "\\N"){
        tmp.Timezone = stof(st.Timezone);
    } else tmp.Timezone = -100;

    tmp.DST = st.DST.substr(1, st.DST.size() - 2);
    tmp.database = st.database.substr(1, st.database.size() - 2);
    tmp.Type = st.Type.substr(1, st.Type.size() - 2);
    tmp.Source = st.Source.substr(1, st.Source.size() - 2);
    return tmp;
}

float Airport_data::getLatitude(int id) {
    for (auto i : airport_data) {
        if (i.id == id) return i.Latitude;
    }
    return -1;
}
float Airport_data::getLatitude(string Name) {
    for (auto i : airport_data) {
        if (i.Name == Name) return i.Latitude;
    }
    return -1;
}
float Airport_data::getLongitude(int id) {
    for (auto i : airport_data) {
        if (i.id == id) return i.Longitude;
    }
    return -1;
}
float Airport_data::getLongitude(string Name) {
    for (auto i : airport_data) {
        if (i.Name == Name) return i.Longitude;
    }
    return -1;
}

string Airport_data::getName(int id) {
    for (auto i : airport_data) {
        if (i.id == id) return i.Name;
    }
    return "";
}


// AIRLINE

Airline_data::Airline_data(string filename) {
    ifstream wordsFile(filename);
    if (wordsFile.is_open()) {
        airline l;
        string id;
        while (getline(wordsFile, id, ',')) {
            l.id = stoi(id);
            getline(wordsFile, l.Name, ',');
            if (l.Name[l.Name.size() - 1] != '"') {
                string t;
                getline(wordsFile, t, ',');
                l.Name += ',' + t;
            }

            getline(wordsFile, l.Alias, ',');
            getline(wordsFile, l.IATA, ',');
            getline(wordsFile, l.ICAO, ',');
            getline(wordsFile, l.Callsign, ',');
            getline(wordsFile, l.Country, ',');
            getline(wordsFile, l.Active, '\n');
            airline x = conv_line(l);
            airline_data.push_back(x);
            airline l;
        }
    } else {
        cout << "Error opening file" << endl;
    }
}

airline Airline_data::conv_line(airline& l) {
    airline x;
    x.id = l.id;
    x.Name = l.Name.substr(1, l.Name.size() - 2);
    x.Alias = l.Alias.substr(1, l.Alias.size() - 2);
    if (l.IATA == "") {
        x.IATA = l.IATA;
    } else x.IATA = l.IATA.substr(1, l.IATA.size() - 2);
    if (x.ICAO == "") {
        x.ICAO = l.ICAO;
    } else x.ICAO = l.ICAO.substr(1, l.ICAO.size() - 2);
    if (l.Callsign == "") {
        x.Callsign = l.Callsign;
    } else x.Callsign = l.Callsign.substr(1, l.Callsign.size() - 2);
    if (l.Country == "") {
        x.Country = l.Country;
    } else x.Country = l.Country.substr(1, l.Country.size() - 2);
    x.Active = l.Active.substr(1, l.Active.size() - 2);

    return x;
}

Route_data::Route_data(string filename) {
    ifstream wordsFile(filename);
    if (wordsFile.is_open()) {
        route l;
        while (getline(wordsFile, l.airline_code, ',')) {
            string id;
            getline(wordsFile, id, ',');
            if (id == "\\N") {
                l.id = -100;
            } else l.id = stoi(id);
            
            getline(wordsFile, l.source_code, ',');
            string s_id;
            getline(wordsFile, s_id, ',');
            if (s_id == "\\N") {
                l.source_id = -100;
            } else l.source_id = stoi(s_id);
            getline(wordsFile, l.dest_code, ',');
            string d_id;
            getline(wordsFile, d_id, ',');
            if (d_id == "\\N") {
                l.dest_id = -100;
            } else l.dest_id = stoi(d_id);
            getline(wordsFile, l.Codeshare, ',');
            string s;
            getline(wordsFile, s, ',');
            l.Stops = stoi(s);
            getline(wordsFile, l.Equipment, '\n');
            route_data.push_back(l);
            route l;
        }
    } else {
        cout << "Error opening file" << endl;
    }
}

// route Route_data::conv_line(route& l) {
//     route x;
//     x.airline_code = l.airline_code.substr(1, l.airline_code.size() - 2);
//     x.id = l.id;
//     x.source_code = l.source_code.substr(1, l.source_code.size() - 2);
//     x.source_id = l.source_id;
//     x.dest_code = l.dest_code.substr(1, l.dest_code.size() - 2);
//     x.dest_id = l.dest_id;
//     if (l.Codeshare == "") {
//         x.Codeshare = l.Codeshare;
//     } else x.Codeshare = l.Codeshare.substr(1, l.Codeshare.size() - 2);
//     x.Stops = l.Stops;
//     x.Equipment = l.Equipment.substr(1, l.Equipment.size() - 2);
//     return x;
// }
