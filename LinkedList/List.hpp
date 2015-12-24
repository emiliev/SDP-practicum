//
//  List.hpp
//  LinkedList
//
//  Created by Emil Iliev on 12/23/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include "Box.hpp"

template <typename T>
class List{
    
    Box<T>* start;
    Box<T>* end;
    size_t size;
    
    bool validIndex(int index){
        
        if(index < 0 || index >= size){
            
            return false;
        }
        
        return true;
    }
    
    public:
    
    List(){
        
        start = 0;
        end = 0;
        size = 0;
    }
    
    virtual ~List(){
        
        Box<T>* temp = start;
        while (temp) {
            
            Box<T>* p = temp;
            temp = temp->pNext;
            delete p;
        }
    }
    
    void add(T value){
        
        Box<T>* newElem = new Box<T>();
        newElem->data = value;
        newElem->pNext = 0;
    
        if(start == 0){
            
            start = newElem;
        }
        else{
            
            end->pNext = newElem;
        }
        
        end = newElem;
        ++size;
    }
    
    void remove(int index){
        
        
        if(!validIndex(index)){
            
            return;
        }
        
        Box<T>* elem = start;
        if(index == 0){
            
            start = start->pNext;
        }
        else{
            
            Box<T>* it = start;
            while (index > 1) {

                it = it->pNext;
                --index;
            }
            
            elem = it->pNext;
            it->pNext = elem->pNext;
            if(!it->pNext){
                
                end = it;
            }
        }
        
        --size;
        delete elem;
        
        if(size == 0){
            
            start = end = NULL;
        }
    }
    
    T& getAt(int index){
        
        if (validIndex(index)) {
        
            Box<T>* temp = start;
            for(int elem = 0; elem < index; ++elem){
            
                temp = temp->pNext;
            }
        
            return temp->data;
        }
        
        return end->data;
    }
    
    size_t getSize(){
        
        return this->size;
    }
    
};

#endif /* List_hpp */
