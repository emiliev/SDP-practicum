//
//  GeneralTree.hpp
//  Hw4
//
//  Created by Emil Iliev on 1/5/16.
//  Copyright © 2016 Emil Iliev. All rights reserved.
//

#ifndef GeneralTree_hpp
#define GeneralTree_hpp

#include <stdio.h>
#include "Node.hpp"
#include <iostream>
template <typename T>
class GeneralTree{
    
    public:
    
    GeneralTree(size_t value){
    
        root = new Node<T>(value);
        start = root;
    }
    
    ~GeneralTree(){
    
    }
    Node<T>* root;
    Node<T>* start;
    void addChild(size_t value){
        
        Node<T>* temp = new Node<T>(value);
        root->size++;
        root->children.addElement(temp);
    }
    
    void moveToIndex(int index){
        
        root = root->children.getElementAtIndex(index);
    }
    
    void printAll(){
        
        privatePrint(start);
    }
    
    void privatePrint(Node<T>* r){
        
        if(r){
            for(size_t index = 0; index < r->size; ++index){
                
                Node<T>* temp = r->children.getElementAtIndex(index);
                privatePrint(temp);
            }
            cout<<r->data<<" ";
        }
    }
    
};
#endif /* GeneralTree_hpp */
