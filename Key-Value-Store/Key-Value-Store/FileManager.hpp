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

using namespace std;
template <typename K, typename V>
class FileManager{
    
    public:
    
    static void writeToFile(char* _key, V _value){
        
        long index = Hash::stringHash(_key) % 1000;
        size_t lengh = log10(index) + 2;
        char* fileName = new char[lengh];
        fileName[lengh - 1] = '\0';
        sprintf(fileName,"%ld", index);
        strcat(fileName, ".dat");
        std::ofstream output(fileName, std::ios::binary | std::ios::app);
        if(output){
            
            size_t keyLength = strlen(_key);
            size_t valueLength = strlen(_value);
            output.write((char*)&keyLength, sizeof(keyLength));
            output.write(_key, keyLength);
            output.write((char*)&valueLength, sizeof(valueLength));
            output.write(_value, valueLength);
            
            cout<<keyLength<<" "<<_key<<" "<<valueLength<<" "<<_value<<endl;
        }
        
        output.close();
        delete [] fileName;
    }
    
    static bool readFromFile(K _key, V& _value){
        
        char* stringKey = Hash::toString(_key);
        long index  = Hash::stringHash(stringKey) % 1000;
        
        size_t lengthOfFile = log10(index) + 6; //fileName + .dat + '\0'
        char* fileName = new char[lengthOfFile];
        sprintf(fileName,"%ld", index);
        strcat(fileName, ".dat");
        
        std::ifstream input(fileName, std::ios::binary);
        bool isFound = false;
        
        if(input){
            
            while(!input.eof() && !isFound){
                
                size_t lengthOfKey = 0;
                size_t lengthOfValue = 0;
                input.read((char*)&lengthOfKey, sizeof(lengthOfKey));
                char* keyBuffer = new char[lengthOfKey];
                input.read(keyBuffer, lengthOfKey);
                input.read((char*)&lengthOfValue, sizeof(lengthOfValue));
                char* valueBuffer = new char[lengthOfValue];
                input.read(valueBuffer, lengthOfValue);
                
                if(strcmp(stringKey, keyBuffer) == 0){
                    
                    isFound = true;
                    _value = new char[lengthOfValue];
                    strcpy(_value, valueBuffer);
                }
                
                delete [] valueBuffer;
                delete [] keyBuffer;
            }
        }
        
        delete [] fileName;
        
        return isFound;
    }
    
    static bool deleteFromFile(K _key){

        char* stringKey = Hash::toString(_key);
        long index = Hash::stringHash(stringKey) % 1000;
        char fileName[256];
        sprintf(fileName,"%ld", index);
        strcat(fileName, ".dat");
        std::ifstream input(fileName, std::ios::binary);
        bool foundIt = false;
        if(input){
        
            while (!input.eof()) {
                
                size_t lengthOfKey = 0;
                size_t lengthOfValue = 0;
                input.read((char*)&lengthOfKey, sizeof(lengthOfKey));
                char* keyBuffer = new char[lengthOfKey];
                input.read(keyBuffer, lengthOfKey);
                input.read((char*)&lengthOfValue, sizeof(lengthOfValue));
                char* valueBuffer = new char[lengthOfValue];
                input.read(valueBuffer,lengthOfValue);
                
                std::cout<<keyBuffer<<std::endl;

                if(strcmp(stringKey, keyBuffer) == 0){
                    
                    foundIt = true;
                    streampos p;
                    p = input.tellg();
                    size_t remaining = lengthOfKey + sizeof(lengthOfKey) + lengthOfValue + sizeof(lengthOfValue);
                    p -= remaining;
                    
                    ofstream newRecord(fileName, ios::binary | ios::in);
                    newRecord.seekp(p);
                    if(newRecord){
                        
                        while (!input.eof()) {
                            
                            size_t newKeyLength = 0;
                            size_t newValueLength = 0;
                            input.read((char*)&newKeyLength, sizeof(newKeyLength));
                            if(!input){
                                cout<<"krai na newRecord!\n";
                                break;
                            }
                            char* newKey = new char[newKeyLength];
                            input.read(newKey, newKeyLength);
                            input.read((char*)&newValueLength, sizeof(newValueLength));
                            char* newValue = new char[newValueLength];
                            input.read(newValue,newValueLength);
                            
                            newRecord.write((char*)&newKeyLength, sizeof(newKeyLength));
                            newRecord.write(newKey, newKeyLength);
                            newRecord.write((char*)& newValueLength, sizeof(newValueLength));
                            newRecord.write(newValue, newValueLength);
                            
                            cout<<newKey<<" "<<newValue<<endl;
                            delete [] newKey;
                            delete [] newValue;
                        }
                        
                        while (remaining != 0) {
                            
                            newRecord<<'\0';
                            remaining--;
                        }
                    }
                    
                    newRecord.close();
                }
            }
        }
        
        input.close();
        delete [] stringKey;
        return foundIt;
    }

};


#endif /* FileManager_hpp */
