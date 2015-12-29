//
//  List.hpp
//  Key-Value-Store
//
//  Created by Emil Iliev on 12/29/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#ifndef List_hpp
#define List_hpp

#include <stdio.h>
#include "Node.hpp"

template <typename T>
class LinkedList{

    public:
    
        LinkedList();
        virtual ~LinkedList();
        void addElement(T value);
        void removeElement(int index);
        T& getAt(int index);
        size_t getSize();
    private:
    
        Node<T>* start;
        Node<T>* end;
        size_t listSize;
    
        bool isValidIndex(int index);
    
};

template <typename T>
T& LinkedList<T>::getAt(int index){
    
    if(isValidIndex(index)){
        Node<T> *temp = start;
        for(int elem = 0; elem < index; ++elem){
            
            temp = temp->pNext;
        }
        
        return temp->data;
    }
    
    return end->data;
}

template <typename T>
void LinkedList<T>::addElement(T value){
    
    Node<T>* temp = new Node<T>;
    temp->data = value;
    temp->pNext = NULL;
    
    if(!start){
        
        start = temp;
    }
    else{
        
        end->pNext = temp;
    }
    
    end = temp;
    listSize++;
}

template <typename T>
void LinkedList<T>::removeElement(int index){
    
    if(!isValidIndex(index)){
        return;
    }
    
    Node<T> *temp = start;
    if(index == 0){
        
        start = start->pNext;
    }
    else{
        
        Node<T>* elem = start;
        while (index > 1) {
            
            elem = elem->pNext;
            index--;
        }
    
        temp = elem->pNext;
        elem->pNext = temp->pNext;
        if(!elem->pNext){
            
            end = elem;
        }

    }
    
    delete temp;
    listSize--;
    
    if(listSize == 0){
        
        start = NULL;
        end = NULL;
        
    }
}

template <typename T>
LinkedList<T>::LinkedList(){
    
    start = 0;
    end = 0;
    listSize = 0;
}

template <typename T>
LinkedList<T>::~LinkedList(){
    
    Node<T>* pNode = start;
    while (pNode) {
        
        Node<T>* temp = pNode;
        pNode = pNode->pNext;
        delete temp;
    }
}

template <typename T>
size_t LinkedList<T>::getSize(){
    
    return listSize;
}

template <typename T>
bool LinkedList<T>::isValidIndex(int index){
    
    if(index < 0 || index >= this->listSize){
        
        return false;
    }
    
    return true;
}

#endif /* List_hpp */
