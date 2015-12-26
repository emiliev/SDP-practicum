//
//  main.cpp
//  LinkedList
//
//  Created by Emil Iliev on 12/21/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include <iostream>
#include "List.hpp"

int main(int argc, const char * argv[]) {

    
    List<int> intL;
    for(int index = 0; index < 10; ++index){
        
        intL.add(index);
    }
    
    intL.remove(9);
    intL.remove(5);
    
    std::cout<<"after several deleted intems: \n";
    for(int index = 0; index < intL.getSize(); ++index){
        
        std::cout<<intL.getAt(index)<<" ";
    }

    
    size_t listSize = intL.getSize();
    for(size_t index = 0; index <listSize; ++index){
    
        int p = 0;
        std::cout<<" i'm gonna delete this elements: "<<intL.getAt(p)<<'\n';
        intL.remove(p);
    }

    return 0;
}
