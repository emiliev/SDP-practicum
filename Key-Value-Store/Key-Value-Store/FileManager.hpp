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
#include <iostream>
template <typename K, typename V>
class FileManager{
    
    public:
    
    static void writeToFile(K _key, V _value){
        
        long index = Hash::stringHash(_key) % 1000;
        char fileName[256];
        sprintf(fileName,"%ld", index);
        strcat(fileName, ".dat");
        std::ofstream output(fileName, std::ios::binary | std::ios::app);
        if(output){
            
            int keyLength = strlen(_key);
            output.write((char*)&keyLength, sizeof(keyLength));
            output.write(_key, keyLength);
            output.write((char*)&_value, sizeof(_value));
        }
        
        output.close();
    }
    
    static bool readFromFile(K _key, V& _value){
        
        long index = Hash::stringHash(_key) % 1000;
        char fileName[256];
        char keyBuffer[100];
        sprintf(fileName,"%ld", index);
        strcat(fileName, ".dat");
        std::ifstream input(fileName, std::ios::binary);
        bool isFound = false;
        
        
        if(input){
            
            while (!input.eof()) {
                
                memset(keyBuffer, 0, sizeof(keyBuffer));
                std::cout<<keyBuffer<<'\n';
                K tempKey;
                V newValue;
                int lengthOfKey;
                input.read((char*)&lengthOfKey, sizeof(lengthOfKey));
                input.read(keyBuffer, lengthOfKey);
                std::cout<<keyBuffer<<std::endl;
                tempKey = reinterpret_cast<K>(keyBuffer);
                input.read((char*)&newValue, sizeof(newValue));
                
                if(strcmp(tempKey,_key) == 0){
                    
                    _value = newValue;
                    isFound = true;
                    break;
                }

            }
        }
        
        input.close();
        return isFound;
    }
};
#endif /* FileManager_hpp */
