/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bike.cpp
 * Author: thojoh171
 * 
 * Created on March 1, 2018, 3:15 PM
 */

#include "Bike.h"

Bike::Bike() {
}

Bike::Bike(const Bike& orig) {
}

Bike::~Bike() {
    delete fWheel, rWheel;
}

