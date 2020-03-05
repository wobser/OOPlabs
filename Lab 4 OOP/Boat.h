/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Boat.h
 * Author: thojoh171
 *
 * Created on March 2, 2018, 11:19 AM
 */

#ifndef BOAT_H
#define BOAT_H
#include "Vehicle.h"
#include <iostream>

class Boat:public virtual Vehicle {
public:
    Boat();
    Boat(const Boat& orig);
    virtual ~Boat();
    void print(){
        std::cout<<"Boat"<<std::endl;
    }
private:

};

#endif /* BOAT_H */

