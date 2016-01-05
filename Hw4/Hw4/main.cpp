//
//  main.cpp
//  Hw4
//
//  Created by Emil Iliev on 1/4/16.
//  Copyright © 2016 Emil Iliev. All rights reserved.
//

#include <iostream>
#include "GeneralTree.hpp"

using namespace std;


void moveTo(char*& ptr, int data){
    
    int keeper = 0;
    int nodeValue = 0;
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
            moveTo(ptr, nodeValue);
        }
        
        else if (*ptr == '}'){
            cout<<"End with looking for descendats of this element "<<data<<"\n";
           
            return;
        }
    
            ptr++;
    
    }
}

void moveToNext(char*& ptr){
    
    int numberOfNodes = 0;
    moveTo(ptr, 0);
}

int main(int argc, const char * argv[]) {
    
//    GeneralTree<int> tree(51);
//    
//    for(int index = 0; index < 10; ++index){
//        if(index != 0 && index % 5 == 0){
//            tree.moveToIndex(0);
//        }
//        tree.addChild(index);
//    }
//    
//    tree.printAll();
//    

    char text[] = "(5{(9{})(1{(4{})(12{})(42{})})})";
    char* ptr = text;
    
    moveToNext(ptr);
    return 0;
}
