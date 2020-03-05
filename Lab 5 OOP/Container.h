/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Container.h
 * Author: thojoh171
 *
 * Created on March 7, 2018, 11:46 AM
 */

#ifndef CONTAINER_H
#define CONTAINER_H
#include <iostream>



template <typename T>
struct Node{
    T info;
    Node<T>* next;
    Node<T>* previous;
};

template <typename T>
class Container {
public:
    Node<T>* head;
    Node<T>* tail;
    Node<T> dummy;
    int cSize = 0;
    
    Container(){
        head = &dummy;
        tail = &dummy;
    };
    Container(const Container& orig);
    virtual ~Container(){
        
    };
    
    //member functions down below
    void clear();                       //clear the list
    int size(){                 //returns current size of the list (int number)
        std::cout<<"size: "<<cSize<<std::endl;
        return cSize;
    }                         
    bool empty(){               //returns true if list is empty
        if (size() == 0){
            return true;
        }
        else{
            return false;
        }
    }                       
    Node<T>* back(){                        //returns a reference to the last element
        return &tail;
    }                           
    Node<T>* front(){                       //returns a reference to the first element
        return &head;
    }                          
    void erase(){                       //remove an element at a given position
        
    }                       
    bool insert(T newElement, int pos){          //insert an element at a given position
        if (pos > size()){
            return false;
        }
        Node<T>* temp = new Node<T>;
        temp->info = newElement;
        Node<T>* current = head;
        Node<T>* before;
        //temp.previous = nullptr;
        for(int i = 0; i < pos; i++){
            current = current->next;
        }
        if(pos == 0){
            head = temp;
            head->next = &dummy;
            temp->next = current;
            temp->previous = nullptr;
            ++cSize;
            std::cout<<"insert function pos 0 called"<<std::endl;
            return true;
        }
        else if(cSize == 1){
            head = temp;
            temp->previous = nullptr;
            temp->next = current;
            temp->next->previous = temp;
            ++cSize;
            std::cout<<"insert function pos 1 called"<<std::endl;
            return true;
        }
        before = current->previous;
        temp->previous = before;
        temp->next = current;
        temp->previous->next = temp;
        //current->previous = temp;
        ++cSize;
        std::cout<<"insert function called"<<std::endl;
    }        
    void push_front(T newElement){      //add element to the beginning
        Node<T> temp;
       // temp = tail;
        temp.info = newElement;
        ++cSize;
        std::cout<<"push_front called"<<std::endl;
    }    
    void push_back(T newElement){       //add element to the end
        Node<T> temp;
       // temp = head;
        temp.info = newElement;
        ++cSize;
        std::cout<<"push_back called"<<std::endl;
    }
    void pop_front(){                   //remove element from the beginning
        
    }                   
    void pop_back(){                    //remove element from the end
        
    }
    void printlist(){
        Node<T>* current = head;
        for(int i = 0; i<= cSize; i++){
            std::cout<<"Element: "<<current->info<<std::endl;
            current = current->next;
        }
    }
    
    
};

#endif /* CONTAINER_H */

