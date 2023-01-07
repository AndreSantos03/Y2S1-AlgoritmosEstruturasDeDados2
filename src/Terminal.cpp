//
// Created by ftmlo on 07/01/2023.
//

#include "Terminal.h"

Terminal::Terminal(unordered_map<string, Airline> airlines, unordered_map<string, Airport> airports, Graph flights) {
    this->algorithms = Algorithms(airlines,airports,flights);
}

void Terminal::IO() {
    cout << "-----Choose an option!-----\n" << endl;
    cout << "1: Get best flight pass." << endl;

    cin >> choice;

    if(choice == "1"){
        getBestFlightPath();
    }
}

void Terminal::getBestFlightPath() {
    string sourceCode;
    string targetCode;
    cout << "-----Choose an option!-----\n" << endl;

    cout << "1: Choose from airport codes." << endl;
    cout << "2: Choose from city name." << endl;
    cout << "3: Choose from latitude and longitude." << endl;
    cin >> choice;
    if(choice == "1") {
        while (true) {
            cout << "Enter source airport code: ";
            cin >> choice;
            if (algorithms.isValidAirportCode(choice)) {
                sourceCode = choice;
                break;
            } else {
                cout << "You entered an invalid airport code!" << endl;
            }
        }
        while (true) {
            cout << "Enter destination airport code: ";
            cin >> choice;
            if (algorithms.isValidAirportCode(choice)) {
                targetCode = choice;
                break;
            } else {
                cout << "You entered an invalid airport code!" << endl;
            }
        }
    }
    else if(choice == "2") {
        while (true) {
            cout << "Enter source city name: ";
            cin >> choice;
            choice = algorithms.convertCity(choice);
            if (choice != "NONE") {
                sourceCode = choice;
                break;
            } else {
                cout << "You entered an invalid city name!" << endl;
            }
        }
        while (true) {
            cout << "Enter destination city name: ";
            cin >> choice;
            choice = algorithms.convertCity(choice);
            if (choice != "NONE") {
                targetCode = choice;
                break;
            } else {
                cout << "You entered an invalid airport code!" << endl;
            }
        }
    }
    else if(choice == "3"){
        float lat;
        float lon;
        while (true) {
            cout << "Enter source latitude: ";
            cin >> choice;
            lat = stof(choice);
            if(!(lat >= -180 && lat <=180)){
                cout << "You entered an invalid latitude!" << endl;
            } else {
                break;
            }
        }
        while (true) {
            cout << "Enter source longitude: ";
            cin >> choice;
            lon = stof(choice);
            if(!(lat >= -90 && lat <=90)){
                cout << "YYou entered an invalid longitude!" << endl;
            } else {
                sourceCode = algorithms.convertCoordinates(lat,lon);
                cout << sourceCode << endl;
                break;
            }
        }
        while (true) {
            cout << "Enter destiny latitude: ";
            cin >> choice;
            lat = stof(choice);
            if(!(lat >= -180 && lat <=180)){
                cout << "You entered an invalid latitude!" << endl;
            } else {
                break;
            }
        }
        while (true) {
            cout << "Enter destiny longitude: ";
            cin >> choice;
            lon = stof(choice);
            if(!(lat >= -90 && lat <=90)){
                cout << "YYou entered an invalid longitude!" << endl;
            } else {
                targetCode = algorithms.convertCoordinates(lat,lon);
                cout << targetCode << endl;
                break;
            }
        }
    }
    cout << "The fastest flight path is : \n" << endl;
    vector<pair<string,string>> results = algorithms.bestPath(sourceCode,targetCode);
    for(auto it = results.begin() + 1; it != results.end();it++){
        cout << "You take a flight to the Airport in " << algorithms.getCityFromCode(it->first) <<  " through the airline " << it->second << "." << endl;
    }
    IO();
}
