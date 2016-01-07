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
    
    GeneralTree(){
        root = new Node<T>;
        root->size = 0;
        start = root;
    }
    
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
    
    void moveToNext(char*& ptr){
        
        moveTo(ptr, 0);
    }
    
    private:

    void moveTo(char*& ptr, int data){
        
        int keeper = 0;
        int nodeValue = 0;
        Node<T>* currentState;
        while (*ptr) {
        
        
            if(*ptr == '('){
                ptr++;
                nodeValue = atoi(ptr);
                cout<<"entering node with  value: "<<nodeValue<<" this node is at place "<<keeper<<" in parrent array"<<"\n";
            }
        
            else if(*ptr == ')'){
    
                cout<<"exiting node at index : "<<keeper++<<"\n";
            }
        
            else if(*ptr == '{'){
                cout<<"Start looking for descendants of "<<nodeValue<<'\n';
                ptr++;
                Node<T>* temp =new Node<T>(nodeValue);
                root->children.addElement(temp);
                currentState = root;
                moveToIndex(keeper);
                moveTo(ptr, nodeValue);
                root = currentState;
                
            }
        
            else if (*ptr == '}'){
                cout<<"End with looking for descendats of this element "<<data<<"\n";
                   
                return;
            }
            
            ptr++;
            
        }
    }
    
    void privatePrint(Node<T>* r){
        
        if(r){
             cout<<r->data<<" ";
            size_t length = r->children.getLength();
            for(size_t index = 0; index < length; ++index){
                
                Node<T>* temp = r->children.getElementAtIndex(index);
                privatePrint(temp);
            }
            
        }
    }
    
};
#endif /* GeneralTree_hpp */
