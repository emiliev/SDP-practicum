//
//  Hash.cpp
//  Key-Value-Store
//
//  Created by Emil Iliev on 12/29/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include "Hash.hpp"
#include <iostream>
#include <cmath>


//
//Hash func. Usd for calculating the index, where the key is being stored.
//
long Hash::stringHash(char *key){
    
//    char *p = key;
//    unsigned h = 0;
//    size_t length = strlen(key);
//    for (size_t index = 0; index < length; index++)
//    {
//        h = 33 * h + p[index];
//    }
//    
//    return h ;
    
    ///
    ///testing
    ///

        return 1;
}

//
//Rotation Hash func. Used for key generating
//
//
long Hash::rot_hash(char* text)
{
    char *p = text;
    long h = 0;
    size_t  length = strlen(text);
    for (size_t i = 0; i < length; i++)
    {
        h = (h << 4) ^ (h >> 28) ^ p[i];
    }
    
    return h;
}

//
//
//
char* Hash::toString(size_t _key){

    int sizeOfKey = ceil(log10(_key)) + 2;
    if (sizeOfKey < 0){
        sizeOfKey = 1;
    }
    char* keyString = new char[sizeOfKey];
    keyString[sizeOfKey - 1] = '\0';
    sprintf(keyString, "%ld", _key);
    
    return keyString;
    
}


