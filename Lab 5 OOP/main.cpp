/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: thojoh171
 *
 * Created on March 7, 2018, 10:19 AM
 */

#include <cstdlib>
#include "functions.h"
#include "Container.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    
//  Exercise 1: Variable Template (2 pt)
    inPiRange(2);
    inPiRange(4);
    
//  Exercise 2
    Container<int>* c = new Container<int>;
    c->insert(0,0);
    c->insert(1,1);
    c->insert(2,1);
    c->insert(3,2);
    c->insert(4,0);
    c->insert(5,2);
    c->insert(6,6);
//    c->push_back(4);
//    c->push_back(5);
//    c->push_front(6);
//    c->push_back(7);
    c->size();
    c->printlist();
    
    
    
    return 0;
}

