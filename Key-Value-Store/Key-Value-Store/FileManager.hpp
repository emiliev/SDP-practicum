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
#include "Pair.hpp"
template <typename K, typename V>
class FileManager{
    
    public:
    
    static void writeToFile(K _key, V _value){
        
        long index = Hash::stringHash(_key) % 1000;
        char fileName[256];
        sprintf(fileName,"%ld", index);
        strcat(fileName, ".dat");
        std::ofstream output(fileName, std::ios::binary);
        if(output){
            
            int keyLength = strlen(_key);
            output.write((char*)&keyLength, sizeof(keyLength));
            output.write(_key, keyLength);
            output.write((char*)&_value, sizeof(_value));
        }
        
        output.close();
    }
    
    LinkedList<Pair<K,V>>& readFromFile(K _key){
        
        long index = Hash::stringHash(_key) % 1000;
        char fileName[256];
        sprintf(fileName,"%ld", index);
        strcat(fileName, ".dat");
        std::ifstream input(fileName, std::ios::binary);
        K nKey;
        V nValue;
        LinkedList<Pair<K, V>>* temp;
        if(input){
        
            while (!input.eof()) {
                
                Pair<K,V> pair;
                input>>nKey>>nValue;
                pair.key = nKey;
                pair.value = nValue;
                temp->addElement(pair);
                std::cout<<pair.key<<" "<<pair.value<<std::endl;
            }
        }
        
        input.close();
        return *temp;
    }
};
#endif /* FileManager_hpp */
