/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: thojoh171
 *
 * Created on March 1, 2018, 12:54 PM
 */

#include <cstdlib>
#include "Bike.h"
#include "Car.h"
#include "Vehicle.h"
#include "Boat.h"
#include "Amphicar.h"
#include <fstream>
#include <string>


using namespace std;


/*
 * 
 */
int main(int argc, char** argv) {

    Vehicle * v1 = new Car();
    Vehicle * v2 = new Bike();
    Vehicle * v3 = new Boat();
    Vehicle * v4 = new Amphicar();
    
    v1->print();
    v2->print();
    v3->print();
    v4->print();
    
    ifstream inFile("test.txt");
    
    
    
    while (!inFile.eof()){
        string str = "";
        Vehicle * v;
        getline (inFile, str);
        if (str == "car"){
            v = new Car();
        }
        else if (str == "bike"){
            v = new Bike();
        }
        else if (str == "Boat"){
            v = new Boat();
        }
        else if (str == "amphicar"){
            v = new Amphicar();
        }
        v->print();
    }
    
    delete v1, v2, v3, v4;
    return 0;
}

