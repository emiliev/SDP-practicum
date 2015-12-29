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
#include <iostream>
template <typename K, typename V>
class HashTable{

    public:
    
        LinkedList<Pair<K,V>>* hashTable;
        HashTable(size_t _capacity){
            
            setCapacity(_capacity);
            hashTable = new LinkedList<Pair<K, V>>[capacity];

        }
        ~HashTable(){
            
            delete [] hashTable;
        }
    
        size_t getCapacity(){
            
            return this->capacity;
        }
    
        bool Erase(K key){
            
            return false;
        }
    
        bool Load(K key, size_t sizeOfLoad, V& value){
    
        }
    
        void Store(K _key, V _value){
            
            long index = Hash::stringHash(_key) % capacity;
            LinkedList<Pair<K, V>> row = hashTable[index];
            Pair<K,V> pair;
            pair.key = _key;
            pair.value = _value;
            row.addElement(pair);
            std::cout<<pair.key<<" for value: "<<pair.value<<" at index: "<<index<<std::endl;
        }
    private:
    
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
