//
// Created by NASA on 06/01/2023.
//

#ifndef AEDPROJETO2_FLIGHTCONTROLLER_H
#define AEDPROJETO2_FLIGHTCONTROLLER_H

#include "Graph.h"
#include "Reader.h"

using namespace std;

class FlightController {
private:
    unordered_map<string, Airline> airlines;
    unordered_map<string, Airport> airports;
    Graph flights;
public:
    FlightController();

    Graph get_flights(){return flights;}
    unordered_map<string, Airline> get_airlines() {return airlines;};
    unordered_map<string, Airport> get_airports() {return airports;};
};


#endif //AEDPROJETO2_FLIGHTCONTROLLER_H