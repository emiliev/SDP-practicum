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
#include <cmath>
#include "List.hpp"
#include "Pair.hpp"
#include "Hash.hpp"
#include "IOManager.hpp"
#include <iostream>

template <typename K, typename V>
class HashTable{

    public:

        //
        //constructor
        //
        HashTable(size_t _capacity){
            
            setCapacity(_capacity);
            hashTable = new LinkedList<Pair<K, V>>[capacity];

        }
    
        //
        //desructor
        //
        virtual~HashTable(){
            
            delete [] hashTable;
        }
    
        //
        //returns the size of the hash table
        //
        size_t getCapacity(){
            
            return this->capacity;
        }
    
        //
        //Erases the given key & value from the memory & file if exists
        //
        bool Erase(K _key){
            
            
            IOManager.deleteFromFile(_key);
            char* stringKey = Hash::toString(_key);
            long index = Hash::stringHash(stringKey) % capacity;
            LinkedList<Pair<K, V>>& row = hashTable[index];
            for(int index = 0; index < row.getSize(); ++index){
                
                if(row.getAt(index).key == _key){
                
                    row.removeElement(index);
                    delete [] stringKey;
                    return true;
                    
                }
            }
            
            delete [] stringKey;
            return false;
        }
  
        //
        //Loades the Pair in memory
        //
        bool Load(Pair<K, V> &temp){
            
            if(checkInMemory(temp.key, temp.value)){

                return true;
            }
            else if(IOManager.readFromFile(temp.key,temp.value)){
                
                return true;
            }
        
            return false;
        }
    
        //
        //Generates key for given value
        //
        size_t Store(V _value){
            
            size_t key = Hash::rot_hash(_value);
            cout<<key<<endl;
            Pair<K,V> temp;
            temp.key = key;
            if(!Load(temp)){
                
                cout<<"Stroing in file\n";
                privateStore(key, _value);
            }
            return key;
        }
    
    private:
    
        LinkedList<Pair<K,V>>* hashTable;
        IOManager<K, V> IOManager;
        size_t capacity;
    
        //
        //Saves the pair on the disk & memory
        //
        void privateStore(K _key, V _value){
            
            //convert key to char*
            int sizeOfKey = (int)log10(_key) + 2;
            char* keyString = new char[sizeOfKey];
            keyString[sizeOfKey - 1] = '\0';
            sprintf(keyString, "%ld", _key);
            
            
            //place in hashtable
            long index = Hash::stringHash(keyString) % 1000;
            LinkedList<Pair<K, V>>& row = hashTable[index];
            Pair<K,V> pair;
            pair.key = _key;
            pair.value = _value;
            row.addElement(pair);
            IOManager.writeToFile(_key , _value);
            
            delete [] keyString;
        }
    
        //
        //set capacity of the hashTable
        //
        void setCapacity(size_t _capacity){
            
            if(_capacity > 0){
                
                this->capacity = _capacity;
            }
            
            else{
                
                this->capacity = 1;
            }
        }
    
        //
        //Searches the given key if it's loaded in the memory of the table
        //if it is, than returns the value.
        //
        bool checkInMemory(K _key, V& _value){
            
            char* stringKey = Hash::toString(_key);
            long index = Hash::stringHash(stringKey) % capacity;
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
