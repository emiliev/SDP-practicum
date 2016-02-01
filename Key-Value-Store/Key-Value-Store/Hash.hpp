//
//  Hash.hpp
//  Key-Value-Store
//
//  Created by Emil Iliev on 12/29/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#ifndef Hash_hpp
#define Hash_hpp

#include <stdio.h>
#include <cstring>
class Hash{
   
    public:
    static long stringHash(char* key);
    static long rot_hash(char* key);
    static char* toString(size_t _key);
};
#endif /* Hash_hpp */
