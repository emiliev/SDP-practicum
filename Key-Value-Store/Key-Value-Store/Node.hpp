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

template <typename T>
class Node{
  
    public:
        Node<T>* pNext;
      //  Node<T>* pPrev;
        T data;
};

#endif /* Node_hpp */
