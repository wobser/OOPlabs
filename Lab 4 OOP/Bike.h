/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bike.h
 * Author: thojoh171
 *
 * Created on March 1, 2018, 3:15 PM
 */

#ifndef BIKE_H
#define BIKE_H
#include <iostream>
#include "Vehicle.h"
#include "Wheel.h"

class Bike:public Vehicle {
public:
    Bike();
    Bike(const Bike& orig);
    virtual ~Bike();
    void print(){
        std::cout<<"Bike"<<std::endl;
    }
private:
    Wheel *fWheel;
    Wheel *rWheel;
};

#endif /* BIKE_H */

