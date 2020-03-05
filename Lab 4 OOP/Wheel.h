/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Wheel.h
 * Author: thojoh171
 *
 * Created on March 1, 2018, 3:18 PM
 */

#ifndef WHEEL_H
#define WHEEL_H

class Wheel {
public:
    Wheel();
    Wheel(const Wheel& orig);
    virtual ~Wheel();
private:
    int radius;
    int RPM;
    int angle;
};

#endif /* WHEEL_H */

