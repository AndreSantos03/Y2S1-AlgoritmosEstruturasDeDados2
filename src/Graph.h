/**
 * @file Graph.h
 * Funções para ler ficheiros
 */

#ifndef AEDPROJETO2_GRAPH_H
#define AEDPROJETO2_GRAPH_H


#include <iostream>
#include <list>
#include <math.h>
#include <vector>
#include <unordered_map>
#include "Flight.h"
#include "Airport.h"
#include "Airline.h"
#include <set>
#include <climits>
#include <queue>

class Graph {
public:
    //doesn't make sense to add edges, we'll just use flights
    struct Node{
        list<Flight> adj;
        bool visited;
        int dist;
    };
    unordered_map<string, Node> nodes;
    Graph();
    void addEdge(Airport src, Airport dest, Airline line, float weight);
    static float getDistance(float lat1, float lon1, float lat2, float lon2);
};


#endif //AEDPROJETO2_GRAPH_H
