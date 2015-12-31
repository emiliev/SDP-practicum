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
  
    bool Load(Pair<K, V> &temp){
        
        if(checkInMemory(temp.key, temp.value)){

            return true;
        }
        else if(FileManager<K, V>::readFromFile(temp.key, temp.value)){
            
            return true;
        }
        
        return false;
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
    
        bool checkInMemory(K _key, V& _value){
            
            long index = Hash::stringHash(_key) % capacity;
            LinkedList<Pair<K, V>>& row = hashTable[index];
            for(int index = 0; index < row.getSize(); ++index){
                
                if(row.getAt(index).key == _key){
                    
                    _value = row.getAt(index).value;
                    return true;
                    
                }
            }
            
            return false;
        }
};
#endif /* HashTable_hpp */