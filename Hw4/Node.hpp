//
//  Node.hpp
//  Key-Value-Store
//
//  Created by Emil Iliev on 12/29/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#ifndef Node_hpp
#define Node_hpp

#include <stdio.h>
#include "DinamicArray.hpp"

template <typename T>
class Node{
  
    public:
    
        size_t data;
        DinamicArray<Node*> children;
        size_t size;
        Node(size_t _data){
            
            data = _data;
            size = 0;
        }
    
    
        Node(){
            
            size = 0;
        }
    
};

#endif /* Node_hpp */
