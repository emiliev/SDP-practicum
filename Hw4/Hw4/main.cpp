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
const size_t kMaxLength = 256;
int main(int argc, const char * argv[]) {
    
    
                    //Test strings//
    
//    char text[]  = "(5{(9{})(1{(4{})(12{})(42{})})})";
//    char text1[] = "(7{(15{(7{})(10{})(8{})})(3{})})";
    
    char text[kMaxLength];
    std::cout<<"Enter 1st text: ";
    cin.getline(text, kMaxLength);
    
    char text1[kMaxLength];
    std::cout<<"Enter 2nd text: ";
    cin.getline(text1, kMaxLength);

    char* ptr = text;
    GeneralTree<int> tree;
    tree.generateTree(ptr);
    tree.printAll();

    cout<<std::endl;
    
    char* ptr1 = text1;
    GeneralTree<int> other;
    other.generateTree(ptr1);
    other.printAll();
    cout<<std::endl;
    
    if(tree.isIsomorph(other)){
        
        cout<<"YES\n";
    }
    
    else{
        
        cout<<"NO\n";
    }
    return 0;
}
