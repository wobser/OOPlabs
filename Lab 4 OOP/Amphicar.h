/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Amphicar.h
 * Author: thojoh171
 *
 * Created on March 2, 2018, 11:19 AM
 */

#ifndef AMPHICAR_H
#define AMPHICAR_H
#include "Car.h"
#include "Boat.h"
#include "Wheel.h"
#include <iostream>


class Amphicar:public Car, public Boat{
public:
    Amphicar();
    Amphicar(const Amphicar& orig);
    virtual ~Amphicar();
    void print(){
        std::cout<<"Amphicar"<<std::endl;
    }
private:
    Wheel *flWheel;
    Wheel *frWheel;
    Wheel *rlWheel;
    Wheel *rrWheel;
};

#endif /* AMPHICAR_H */

