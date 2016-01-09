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

        root = NULL;
        numberOfDescendants = 0;
    }
    
    GeneralTree(size_t value){
        
        root = new Node<T>(value);
    }
    
    ~GeneralTree(){
        
        delTree(root);
    }
    
    void addChild(size_t value){
        
        Node<T>* temp = new Node<T>(value);
        root->children.addElement(temp);
    }
    
    void moveToChildAtIndex(int index){
        
        root = root->children.getElementAtIndex(index);
    }
    
    void printAll(){
        
        privatePrint(root);
        std::cout<<"\n";
    }
    
    void generateTree(char*& ptr){
        
        privateGenerateTree(ptr, 0);
    }
    
    bool isIsomorph(GeneralTree const & other){
    
        if(numberOfDescendants == other.numberOfDescendants){
            Node<T>* treeOne = root;
            Node<T>* treeTwo = other.root;
          return check(treeOne , treeTwo);
        }
       
        return false;

    }
    
    private:
    
    Node<T>* root;
    int numberOfDescendants;
    
    bool check(Node<T>*& r, Node<T>*& r1){
    
        static bool match = false;
        
        if(r->children.getLength() != r1->children.getLength()){

            return false;
        }
        
        
        size_t treeOneLength = r->children.getLength();
        size_t treeTwoLength = r1->children.getLength();
        for(int index = 0; index < treeOneLength; ++index){
            for(int elem = 0; elem < treeTwoLength; ++elem){
                
                Node<T>* temp = r->children.getElementAtIndex(index);
                Node<T>* temp1 = r1->children.getElementAtIndex(elem);
             
                check(temp,temp1);
            }
        }
        
        if(r->children.getLength() == r1->children.getLength()){
            
            return match = true;
        }
        return match;
    }
    
    void privateGenerateTree(char*& ptr, int data){
        
        int keeper = 0;
        int nodeValue = 0;
        Node<T>* currentState;
        numberOfDescendants++;
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
                if(root){
                   
                    ptr++;
                    addChild(nodeValue);
                    currentState = root;
                    moveToChildAtIndex(keeper);
                    privateGenerateTree(ptr, nodeValue);
                    root = currentState;
                }
                else{
                  
                    root = new Node<T>(nodeValue);
                }
                
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
    
    void delTree(Node<T>* r){
        
        if(r){
           
            size_t length = r->children.getLength();
            for(size_t index = 0; index < length; ++index){
                
                delTree(r->children.getElementAtIndex(index));
            }
            
            delete r;
        }
    }
};
#endif /* GeneralTree_hpp */
