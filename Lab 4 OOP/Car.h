/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Car.h
 * Author: thojoh171
    Car();
    Car(const Car& orig);
    virtual ~Car(){
 *
 * Created on March 1, 2018, 3:10 PM
 */

#ifndef CAR_H
#define CAR_H
#include "Vehicle.h"
#include "Wheel.h"
#include <iostream>


class Car:public virtual Vehicle{
public:
    Car();
    Car(const Car& orig);
    virtual ~Car();
    void print(){
        std::cout<<"Car"<<std::endl;
    }
private:
    Wheel *flWheel;
    Wheel *frWheel;
    Wheel *rlWheel;
    Wheel *rrWheel;
};

#endif /* CAR_H */

