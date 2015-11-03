//
//  LinkedStack.hpp
//  Hw1
//
//  Created by Emil Iliev on 10/28/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#ifndef LinkedStack_hpp
#define LinkedStack_hpp

#include <stdio.h>

template <typename T>
class Box{
    
    public:

        Box<T>* next;
        T data;
        Box(T, Box<T>* = 0);
};

template <typename T>
class LinkedStack{
    
    public:
        LinkedStack();
        ~LinkedStack();
        LinkedStack& operator=(LinkedStack const &other);
        LinkedStack(LinkedStack const &other);
    
        void push(T element);
        bool pop(T& element);
        bool isEmpty();
        T peek();
    private:
    
    void init();
    void destroy();
    void copyFrom(LinkedStack const &other);
    Box<T>* pTop;
    size_t used;
};

template <typename T>
Box<T>::Box(T data, Box<T>* p){
    
    this->data = data;
    this->next = p;
}

template <typename T>
LinkedStack<T>::LinkedStack(){
    
    init();
}

template <typename T>
LinkedStack<T>::~LinkedStack(){
    
    destroy();
}

template <typename T>
LinkedStack<T>::LinkedStack(LinkedStack<T> const &other){
    
    init();
    copyFrom(other);
}

template <typename T>
LinkedStack<T>& LinkedStack<T>::operator=(LinkedStack<T> const &other){
 
    if(this != &other){
        destroy();
        copyFrom(other);
    }
    
    return *this;
}

template <typename T>
void LinkedStack<T>::push(T element){
    
    Box<T>* elem = new Box<T>(element, pTop);
    pTop = elem;
    used++;
}

template <typename T>
bool LinkedStack<T>::pop(T& element){
    
    if(used == 0){
        return false;
    }
    
    element = pTop->data;
    
    Box<T>* currentElement = pTop;
    pTop = pTop->next;
    delete currentElement;
    used--;
    
    return true;
}

template <typename T>
T LinkedStack<T>::peek(){
    
    return pTop->Data;
}

template <typename T>
bool LinkedStack<T>::isEmpty(){

    if(used == 0){
        return true;
    }
    
    return false;
}

template <typename T>
void LinkedStack<T>::copyFrom(const LinkedStack<T> &other){
    
    Box<T> *newElem, *oldElem;
    
    pTop = new Box<T>(other.pTop->data);
    newElem = pTop;
    oldElem = other->next;
    
    while (oldElem) {
      
        newElem = new Box<T>(other.pTop->data);
        newElem = newElem->next;
        oldElem = oldElem->next;
    }
    
    used = other.used;
}

template <typename T>
void LinkedStack<T>::destroy(){
    
    Box<T>* p;
    while (pTop) {
        
        p = pTop;
        pTop = pTop->next;
        delete p;
    }
    
    init();
}

template <typename T>
void LinkedStack<T>::init(){
    
    pTop = 0;
    used = 0;
}

#endif /* LinkedStack_hpp */
