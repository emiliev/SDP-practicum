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

    static bool deleteFromFile(K _key){
    
        long index = Hash::stringHash(_key) % 1000;
        char fileName[256];
        char keyBuffer[100];
        sprintf(fileName,"%ld", index);
        strcat(fileName, ".dat");
        std::ifstream input(fileName, std::ios::binary);
        bool foundIt = false;
        if(input){
        
            while (!input.eof()) {
                
//                int wordLength = 0;
//                input.read((char*)&wordLength, sizeof(wordLength));
//                if(!input){
//                    cout<<"krai na inputa \n";
//                    break;
//                }
//                char* word = new char[wordLength];
//                input.read(word,wordLength);

                memset(keyBuffer, 0, sizeof(keyBuffer));
//                std::cout<<keyBuffer<<'\n';
                K tempKey;
                V newValue;
                int lengthOfKey;
                input.read((char*)&lengthOfKey, sizeof(lengthOfKey));
                //char* keyBuffer = new char[lengthOfKey];
                input.read(keyBuffer, lengthOfKey);
               
                std::cout<<keyBuffer<<std::endl;
                tempKey = reinterpret_cast<K>(keyBuffer);
                
                input.read((char*)&newValue, sizeof(newValue));
                
                if(strcmp(tempKey, _key) == 0){
                    
                    foundIt = true;
                    streampos p;
                    p = input.tellg();
                    int remaining = lengthOfKey + sizeof(lengthOfKey) + sizeof(newValue);
                    p -= remaining;
                    
                    ofstream newRecord(fileName, ios::binary | ios::in);
                    newRecord.seekp(p);
                    if(newRecord){
                        
                        while (!input.eof()) {
                            
                            int newWordLength = 0;
                            input.read((char*)&newWordLength, sizeof(newWordLength));
                            if(!input){
                                cout<<"krai na newRecord!\n";
                                break;
                            }
                            char* newWord = new char[newWordLength];
                            input.read(newWord, newWordLength);
                            
                            V tempValue;
                            input.read((char*)&tempValue, sizeof(tempValue));
                            newRecord.write((char*)&newWordLength, sizeof(newWordLength));
                            newRecord.write(newWord, newWordLength);
                            newRecord.write((char*)&tempValue, sizeof(tempValue));
                            
                            cout<<newWordLength<<" "<<newWord<<" "<<tempValue<<endl;
                            delete newWord;
                        }
                        
                        while (remaining != 0) {
                            
                            newRecord<<'\0';
                            remaining--;
                        }
                    }
                    
                    newRecord.close();
                }
                cout<<lengthOfKey<<" "<<keyBuffer<<newValue<<endl;
                //delete keyBuffer;
            }
        }
        
        input.close();
        return foundIt;
    }

};


/*
 ifstream input("example1.dat", ios::binary);
 if(input){
 
 while (!input.eof()) {
 
 int wordLength = 0;
 input.read((char*)&wordLength, sizeof(wordLength));
 if(!input){
 cout<<"krai na inputa \n";
 break;
 }
 char* word = new char[wordLength];
 input.read(word,wordLength);
 
 if(strcmp(word, "guz") == 0){
 streampos p;
 p = input.tellg();
 int remaining = wordLength + sizeof(wordLength);
 p -= remaining;
 
 ofstream newRecord("example1.dat", ios::binary | ios::in);
 newRecord.seekp(p);
 if(newRecord){
 
 while (!input.eof()) {
 
 int newWordLength = 0;
 input.read((char*)&newWordLength, sizeof(newWordLength));
 if(!input){
 cout<<"krai na newRecord!\n";
 break;
 }
 char* newWord = new char[newWordLength];
 input.read(newWord, newWordLength);
 newRecord.write((char*)&newWordLength, sizeof(newWordLength));
 newRecord.write(newWord, newWordLength);
 
 cout<<newWordLength<<" "<<newWord<<endl;
 delete newWord;
 }
 
 while (remaining != 0) {
 
 newRecord<<'\0';
 remaining--;
 }
 }
 
 newRecord.close();
 }
 cout<<wordLength<<" "<<word<<endl;
 delete word;
 }
 }
 
 input.close();
 
 */
#endif /* FileManager_hpp */
