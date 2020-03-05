/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Car.cpp
 * Author: thojoh171
 * 
 * Created on March 1, 2018, 3:10 PM
 */

#include "Car.h"

Car::Car() {
}

Car::Car(const Car& orig) {
}

Car::~Car() {
    delete flWheel, frWheel, rlWheel, rrWheel;
}

