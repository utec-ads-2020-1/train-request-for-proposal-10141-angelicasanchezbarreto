//
// Created by lica-pc on 3/29/20.
//

#ifndef TRAINREQUEST_FUNCIONES_H
#define TRAINREQUEST_FUNCIONES_H

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct P{
    string name;
    vector<string> requirements_met;
    float price=0;
    int cant_req=0;
    float compliance=0;
};

string max(vector<P> proposals);
void RFP(string nums, int contador);


#endif //TRAINREQUEST_FUNCIONES_H
