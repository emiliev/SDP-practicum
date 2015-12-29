//
//  Hash.cpp
//  Key-Value-Store
//
//  Created by Emil Iliev on 12/29/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include "Hash.hpp"

long Hash::stringHash(char *key){
    
    char *p = key;
    unsigned h = 0;
    size_t length = strlen(key);
    for (size_t index = 0; index < length; index++)
    {
        h = 33 * h + p[index];
    }
    
    return h ;
}