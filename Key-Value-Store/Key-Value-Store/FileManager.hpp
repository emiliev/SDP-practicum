//
//  FileManager.hpp
//  Key-Value-Store
//
//  Created by Emil Iliev on 12/30/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#ifndef FileManager_hpp
#define FileManager_hpp

#include <stdio.h>
#include <fstream>
#include <cstring>
#include "Hash.hpp"
template <typename K, typename V>
class FileManager{
    
    public:
    
    static void writeToFile(K _key, V _value){
        
        long index = Hash::stringHash(_key);
        char fileName[256];
        sprintf(fileName,"%ld", index);
        strcat(fileName, ".txt");
        std::ofstream output(fileName, std::ios::app);
        if(output){
            
            output<<_key<<" "<<_value<<std::endl;
        }
        
        output.close();
    }
    
    static V& readFromFile(K _key){
     
  
    }
};
#endif /* FileManager_hpp */
