/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Amphicar.cpp
 * Author: thojoh171
 * 
 * Created on March 2, 2018, 11:19 AM
 */

#include "Amphicar.h"

Amphicar::Amphicar() {
}

Amphicar::Amphicar(const Amphicar& orig) {
}

Amphicar::~Amphicar() {
    delete flWheel, frWheel, rlWheel, rrWheel;
}

