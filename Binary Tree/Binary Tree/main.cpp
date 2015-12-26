//
//  main.cpp
//  Binary Tree
//
//  Created by Emil Iliev on 12/21/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include "BinaryTree.cpp"
#include <iostream>

int main(int argc, const char * argv[]) {

    
    BinaryTree<int> bTree;
    
    bTree.insert(5);
    bTree.insert(10);
    bTree.insert(2);
    bTree.insert(1);
    bTree.insert(12);
    bTree.insert(5);
    bTree.insert(10);
    bTree.insert(2);
    bTree.insert(1);
    bTree.insert(12);
    bTree.insert(5);
    bTree.insert(10);
    bTree.insert(2);
    bTree.insert(1);
    bTree.insert(12);
    
    
    bTree.print();
    bTree.remove(1);
    std::cout<<'\n';
    bTree.print();
    
    return 0;
}
