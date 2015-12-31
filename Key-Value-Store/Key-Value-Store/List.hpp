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
        LinkedList(LinkedList const &other);
        LinkedList& operator=(LinkedList const &other);
        void addElement(T value);
        void removeElement(int index);
        T& getAt(int index);
        size_t getSize();
    private:
    
        Node<T>* start;
        Node<T>* end;
        size_t listSize;
    
        bool isValidIndex(int index);
        void copyFrom(LinkedList const &other);
        void del();
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
    
    del();
}

template <typename T>
LinkedList<T>::LinkedList(LinkedList const &other){
    
    copyFrom(other);
}

template <typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> const &other){
    
    if(this != &other){
        del();
        copyFrom(other);
    }
    
    return *this;
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

template <typename T>
void LinkedList<T>::copyFrom(LinkedList<T> const &other){
    
    
    Node<T>* temp = other.start;
    
    if(temp){
        
        start = new Node<T>;
        start->data = temp->data;
        start->pNext = NULL;
        end = start;
        temp = temp->pNext;
        
    }
    
    while (temp) {
        
        Node<T>* node = new Node<T>;
        node->data = temp->data;
        node->pNext = NULL;
        end->pNext = node;
        end = node;
        
        temp = temp->pNext;
    }
    
    listSize = other.listSize;
    
}

template <typename T>
void LinkedList<T>::del(){
    Node<T>* pNode = start;
    while (pNode) {
        
        Node<T>* temp = pNode;
        pNode = pNode->pNext;
        delete temp;
    }
    
    start = NULL;
    end = NULL;
    listSize = 0;
}

#endif /* List_hpp */
