//
//  Pair.hpp
//  Key-Value-Store
//
//  Created by Emil Iliev on 12/29/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#ifndef Pair_hpp
#define Pair_hpp

#include <stdio.h>
#include <cstring>
template <typename K, typename V>
class Pair{
    
    public:
        K key;
        V value;

    void setValue(K type){
        
        key = type;
    }

};



#endif /* Pair_hpp */
