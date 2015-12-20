//
//  DinamicArray.hpp
//  HW2
//
//  Created by Emil Iliev on 11/20/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#ifndef DinamicArray_hpp
#define DinamicArray_hpp

#include <stdio.h>

template <typename T>
class DinamicArray{

    public:
    
        DinamicArray();
        ~DinamicArray();
        DinamicArray(DinamicArray const &other);
        DinamicArray& operator=(DinamicArray const &other);
    
        void addElement(T element);
        void removeLastElement();
        size_t getLength();
        T getElementAtIndex(size_t index);
        void reallocate(int newSize);
    private:
    
        T* data;
        int length;
        int allocatedSize;
        void resize();
        void copyFrom(DinamicArray const &other);
        void destroy();
};

template <typename T>
DinamicArray<T>::DinamicArray(){
    
    length = 0;
    allocatedSize = 1;
    data = new T[allocatedSize];
}

template <typename T>
DinamicArray<T>::~DinamicArray(){

    destroy();
}

template <typename T>
DinamicArray<T>::DinamicArray(DinamicArray<T> const &other){
    
    copyFrom(other);
}

template <typename T>
DinamicArray<T>& DinamicArray<T>::operator=(DinamicArray<T> const &other){
    
    if(this != &other){
        
        destroy();
        copyFrom(other);
    }
    
    return *this;
}

template <typename T>
void DinamicArray<T>::addElement(T element){
    
    if(this->length >= this->allocatedSize){
        
        resize();
    }
    
    data[length] = element;
    ++length;
}

template <typename T>
void DinamicArray<T>::resize(){
    
    allocatedSize = allocatedSize * 2;
    T* newData = new T[allocatedSize];
    for(int index = 0; index < length; ++index){
        
        newData[index] = data[index];
    }
    
    delete [] data;
    data = newData;
    
}

template <typename T>
size_t DinamicArray<T>::getLength(){
    
    return this->length;
}

template <typename T>
T DinamicArray<T>::getElementAtIndex(size_t index){
    
    if(index > this->length){
        return NULL;
    }
    
    return data[index];
}

template <typename T>
void DinamicArray<T>::removeLastElement(){
    
    data[length] = NULL;
    length--;
}

template <typename T>
void DinamicArray<T>::copyFrom(DinamicArray<T> const &other){
    
    length = other.length;
    allocatedSize = other.allocatedSize;
    data = new T[allocatedSize];
    for(int index = 0; index < length; ++index){
        
        data[index] = other.data[index];
    }
}

template <typename T>
void DinamicArray<T>::destroy(){
    
    delete [] data;
    data = NULL;
    length = 0;
    allocatedSize = 0;
}

template <typename T>
void DinamicArray<T>::reallocate(int removedSize){

    int newSize = length - removedSize;
    T* newData = new T[newSize];
    for(int index = 0; index < newSize; ++index){
    
        newData[index] = data[index];
    }
   
    delete [] data;
    
    data = newData;
    length = newSize;
    allocatedSize = newSize;
}

#endif /* DinamicArray_hpp */
