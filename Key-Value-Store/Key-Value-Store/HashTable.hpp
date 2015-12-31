//
//  HashTable.hpp
//  Key-Value-Store
//
//  Created by Emil Iliev on 12/29/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#ifndef HashTable_hpp
#define HashTable_hpp

#include <stdio.h>
#include "List.hpp"
#include "Pair.hpp"
#include "Hash.hpp"
#include "FileManager.hpp"
#include <iostream>

template <typename K, typename V>
class HashTable{

    public:
    
        HashTable(size_t _capacity){
            
            setCapacity(_capacity);
            hashTable = new LinkedList<Pair<K, V>>[capacity];

        }
        virtual~HashTable(){
            
            delete [] hashTable;
        }
    
        size_t getCapacity(){
            
            return this->capacity;
        }
    
        bool Erase(K _key){
            
            long index = Hash::stringHash(_key) % capacity;
            LinkedList<Pair<K, V>>& row = hashTable[index];
            for(int index = 0; index < row.getSize(); ++index){
                
                if(row.getAt(index).key == _key){
                   
                    std::cout<<row.getAt(index).value<<std::endl;
                    row.removeElement(index);
                    return true;
                    
                }
            }
            
            return false;
        }
  
    bool searchInFile(Pair<K, V> &temp){
        
        K _key = temp.key;
        long index = Hash::stringHash(_key) % capacity;
        char fileName[256];
        char keyBuffer[100];
        sprintf(fileName,"%ld", index);
        strcat(fileName, ".dat");
        std::ifstream input(fileName, std::ios::binary);
        bool isFound = false;
        

        if(input){
            
            while (!input.eof()) {

                K newKey;
                V newValue;
                int lengthOfKey;
                input.read((char*)&lengthOfKey, sizeof(lengthOfKey));
                input.read(keyBuffer, lengthOfKey);
                newKey = reinterpret_cast<K>(keyBuffer);
                input.read((char*)&newValue, sizeof(newValue));
               
                std::cout<<newKey<<" "<<newValue<<std::endl;
                if(strcmp(newKey,_key) == 0){
                    
                    temp.value = newValue;
                    isFound = true;
                    break;
                }
            }
        }
        
        input.close();
        return isFound;
    }
    
       Pair<K,V>* Load(K _key){
//            
//            Pair<K,V> temp;
//            temp.key = _key;
//            searchInFile(temp.key, temp.value);
//            long index = Hash::stringHash(_key) % capacity;
//            char fileName[256];
//            char keyBuffer[100];
//            sprintf(fileName,"%ld", index);
//            strcat(fileName, ".dat");
//            std::ifstream input(fileName, std::ios::binary);
//            LinkedList<Pair<K,V>>* row;
//            
//
//            if(input){
//
//                while (!input.eof()) {
//                    Pair<K,V> pair;
//                    K newKey;
//                    V newValue;
//                    int lengthOfKey;
//                    input.read((char*)&lengthOfKey, sizeof(lengthOfKey));
//                    input.read(keyBuffer, lengthOfKey);
//                    newKey = reinterpret_cast<K>(keyBuffer);
//                    input.read((char*)&newValue, sizeof(newValue));
//                    std::cout<<newKey<<" "<<newValue<<std::endl;
//                    pair.key = newKey;
//                    pair.value = newValue;
//                    row->addElement(pair);
//                }
//            }
//            
//            hashTable[index] = *row;
//            std::cout<<"row "<< index<<" size: "<<row->getSize()<<std::endl;
//            for(int index = 0; index < row->getSize(); ++index){
//                std::cout<<row->getAt(index).key<<" "<<_key<<'\n';
//                if(strcmp(row->getAt(index).key,_key) == 0){
//                    
//                    std::cout<<"vrushtam\n";
//                    return &row->getAt(index);
//                }
//            }
            
            return NULL;

        }
    
        void Store(K _key, V _value){
            
            long index = Hash::stringHash(_key) % capacity;
            LinkedList<Pair<K, V>>& row = hashTable[index];
            Pair<K,V> pair;
            pair.key = _key;
            pair.value = _value;
            row.addElement(pair);

            FileManager<K, V>::writeToFile(_key, _value);
        }
    private:
    
        LinkedList<Pair<K,V>>* hashTable;
        size_t capacity;
        void setCapacity(size_t _capacity){
            
            if(_capacity > 0){
                
                this->capacity = _capacity;
            }
            
            else{
                
                this->capacity = 1;
            }
        }
};
#endif /* HashTable_hpp */
