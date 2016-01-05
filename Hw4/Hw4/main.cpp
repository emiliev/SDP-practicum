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

char text[] = "(5{(9{})(1{(4{})(12{})(42{})})})";
int main(int argc, const char * argv[]) {
    
    
    GeneralTree<int> tree(51);
    
    for(int index = 0; index < 10; ++index){
        if(index != 0 && index % 5 == 0){
            tree.moveToIndex(0);
        }
        tree.addChild(index);
    }
    
    tree.printAll();
    
    return 0;
}
