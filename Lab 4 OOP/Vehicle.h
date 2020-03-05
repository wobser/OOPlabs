/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Vehicle.h
 * Author: thojoh171
 *
 * Created on March 1, 2018, 3:01 PM
 */

#ifndef VEHICLE_H
#define VEHICLE_H
#include "Color.h"
#include <iostream>


class Vehicle {
public:
    Vehicle();
    Vehicle(const Vehicle& orig);
    virtual ~Vehicle();
    virtual void print(){
        std::cout << "Vehicle" << std::endl;
    }
private:
    int weight;
    Color color;
};

#endif /* VEHICLE_H */

