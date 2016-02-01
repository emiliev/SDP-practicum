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
class IOManager{
    
    public:
    
    void writeToFile(K _key, V _value){
        
        char* fileName = makeFileName(_key);
        size_t remaingBytes = 0;
        
        if(!isCreatedFile(fileName)){
            
            std::ifstream input(fileName, std::ios::binary);
            if(input){
            
                input.read((char*)&remaingBytes, sizeof(remaingBytes));
            }
            input.close();
        }

        std::fstream output(fileName, std::ios::binary | ios::in | ios::out | ios::ate);

        streampos currentPosition = output.tellp();
        currentPosition -= remaingBytes;
        if(currentPosition > 0){
            
            output.seekp(currentPosition);
        }
        else{
            
            output.seekp(8, ios::beg);
        }
        
        if(output){
        
            size_t valueLength = strlen(_value);
            output.write((char*)&_key, sizeof(_key));
            output.write((char*)&valueLength, sizeof(valueLength));
            output.write(_value, valueLength);
            
        }
        
        streampos ending = output.tellp();
        currentPosition += remaingBytes;
        if(currentPosition > ending){
            size_t digit = currentPosition - ending;
            writeRemainingBytes(digit, fileName);
        }
        else{
            writeRemainingBytes(0, fileName);
        }
        output.close();
        delete [] fileName;
    }
    
    bool readFromFile(K _key, V& _value){
        
        char* fileName = makeFileName(_key);
        std::ifstream input(fileName, std::ios::binary);
        bool isFound = false;
        
        if(input){
            size_t remain = 0;
            input.read((char*)&remain, sizeof(remain));
            while(!input.eof() && !isFound){
                
                size_t lengthOfValue = 0;
                K newKey;
                input.read((char*)&newKey, sizeof(newKey));
                input.read((char*)&lengthOfValue, sizeof(lengthOfValue));
                char* valueBuffer = new char[lengthOfValue + 1];
                input.read(valueBuffer, lengthOfValue);
                valueBuffer[lengthOfValue] = '\0';
                if( _key == newKey){
                    
                    isFound = true;
                    _value = new char[lengthOfValue];
                    strcpy(_value, valueBuffer);
                }
                
                delete [] valueBuffer;
            }
        }
        
        delete [] fileName;
        return isFound;
    }
    
    bool deleteFromFile(K _key){

        char* fileName = makeFileName(_key);
        std::ifstream input(fileName, std::ios::binary);
        bool foundIt = false;
        if(input){
        
            size_t remaining = 0;
            input.read((char*)&remaining, sizeof(remaining));
            while (!input.eof()) {
                
                K key;
                size_t lengthOfValue = 0;
                input.read((char*)&key, sizeof(key));
                input.read((char*)&lengthOfValue, sizeof(lengthOfValue));
                char* valueBuffer = new char[lengthOfValue];
                input.read(valueBuffer,lengthOfValue);
                
                if(key == _key){
                    
                    foundIt = true;
                    streampos p;
                    p = input.tellg();
                    remaining = sizeof(key) + lengthOfValue + sizeof(lengthOfValue);
                    p -= remaining;
                    
                    ofstream newRecord(fileName, ios::binary | ios::in);
                    newRecord.seekp(p);
                    if(newRecord){
                        
                        while (!input.eof()) {
                            
                            size_t newValueLength = 0;
                            K newKey;
                            input.read((char*)&newKey, sizeof(newKey));
                            if(!input){
                                cout<<"krai na newRecord!\n";
                                break;

                            }
                            input.read((char*)&newValueLength, sizeof(newValueLength));
                            char* newValue = new char[newValueLength];
                            input.read(newValue,newValueLength);
                            
                            newRecord.write((char*)&newKey, sizeof(newKey));
                            newRecord.write((char*)& newValueLength, sizeof(newValueLength));
                            newRecord.write(newValue, newValueLength);
                            
                            cout<<newKey<<" "<<newValue<<endl;
                            delete [] newValue;
                        }
                        
                        
                        cout<<endl<<remaining<<endl;
                        writeRemainingBytes(remaining, fileName);
                    }
                    
                    newRecord.close();
                }
            }
        }
        input.close();
        delete [] fileName;
        return foundIt;
    }

    
    private:
    
    bool isCreatedFile(char* fileName){
        
        bool isCreated;
        ifstream test(fileName, ios::binary);
        
        if(test){
            
            isCreated = false;
            cout<<"file exists!\n";
        }
        
        else{
        
            ofstream record(fileName, ios::binary);
            if(record){
                
                size_t buffer = 0;
                record.write((char*)&buffer, sizeof(buffer));
                isCreated = true;
                cout<<"creating new file\n";
            }
            
            record.close();
        }
        
        test.close();
        return isCreated;
    }
    
    void writeRemainingBytes(size_t bytes,char* fileName){
        
        ofstream record(fileName, ios::binary | ios::in);
        if(record){
            
            record.write((char*)&bytes, sizeof(bytes));
        }
    }
    
    char* makeFileName(K _key){
        
        char* stringKey = Hash::toString(_key);
        long index  = Hash::stringHash(stringKey) % 1000;
        
        size_t lengthOfFile = log10(index) + 6; //fileName + .dat + '\0'
        char* fileName = new char[lengthOfFile];
        sprintf(fileName,"%ld", index);
        strcat(fileName, ".dat");
        
        delete [] stringKey;
        return fileName;
    }
    
};


#endif /* FileManager_hpp */
