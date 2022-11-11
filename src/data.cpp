#include "data.h"

Data::Data(string filename) {
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
            store.push_back(l);
            line l;
        }
    } else {
        cout << "Error opening file" << endl;
    }
    makestdata(store);
}


void Data::makestdata(vector<line> st) {
    // cout << st[116].Source << endl;
    // cout << i << endl;
    //     if (i == 6981) cout << "XXXXX =  " << st[i].id << " = " << st[i].Timezone  << endl;
    for (size_t i = 0; i < st.size(); i++) {
        stdata tmp;
        tmp.id = stoi(st[i].id);

        tmp.Name = st[i].Name.substr(1, st[i].Name.size() - 2);
        tmp.City = st[i].City.substr(1, st[i].City.size() - 2);
        tmp.Country = st[i].Country.substr(1, st[i].Country.size() - 2);
        tmp.IATA = st[i].IATA.substr(1, st[i].IATA.size() - 2);
        tmp.ICAO = st[i].ICAO.substr(1, st[i].ICAO.size() - 2);

        tmp.Latitude = stof(st[i].Latitude);
        tmp.Longitude = stof(st[i].Longitude);
        tmp.Altitude = stoi(st[i].Altitude);
        if (st[i].Timezone != "\\N"){
            tmp.Timezone = stof(st[i].Timezone);
        } else tmp.Timezone = -100;

        tmp.DST = st[i].DST.substr(1, st[i].DST.size() - 2);
        tmp.database = st[i].database.substr(1, st[i].database.size() - 2);
        tmp.Type = st[i].Type.substr(1, st[i].Type.size() - 2);
        tmp.Source = st[i].Source.substr(1, st[i].Source.size() - 2);

        mainstore.push_back(tmp);
    }
}