/**
 * @file Flight.h
 * Funções para ler ficheiros
 */

#ifndef AEDPROJETO2_FLIGHT_H
#define AEDPROJETO2_FLIGHT_H

#include "Airport.h"
#include "Airline.h"
#include <iostream>
#include <list>

using namespace std;

class Flight {
private:
    Airport source, target;
    Airline airline;
    float distance;

public:
    Flight(Airport source, Airport target, Airline airline, float distance);
    Airport get_source() {return source;};
    Airport get_target() {return target;};
    Airline get_airline() {return airline;};
};


#endif //AEDPROJETO2_FLIGHT_H
