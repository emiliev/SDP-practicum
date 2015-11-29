//
//  Queue.hpp
//  Queue
//
//  Created by Emil Iliev on 11/8/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#ifndef Queue_hpp
#define Queue_hpp

#include <stdio.h>
#include "iostream"

template <typename T>
class Node{
    
    public:
    Node<T>* next;
    T data;
    Node(T, Node<T>* = 0);
};

template <typename T>
class LinkedQueue{
    
    public:
   
        LinkedQueue();
        ~LinkedQueue();
        void enqueue(T element);
        void dequeue(T& element);
        bool isEmpty();
        T peek();

    private:
    
        Node<T>* front;
        Node<T>* rear;
        size_t used;
};



template <typename T>
Node<T>::Node(T newData, Node<T>* p){
    this->data = newData;
    this->next = p;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(){
    
    this->used = 0;
    this->front = 0;
    this->rear = 0;
}

template <typename T>
void LinkedQueue<T>::enqueue(T element){
    
    Node<T>* elem = new Node<T>(element,rear);
    elem->next = NULL;
    if(front == NULL){
        
        front = elem;
    }
    else{
        
        rear->next = elem;
    }
    
    rear = elem;
    used++;

}

template <typename T>
LinkedQueue<T>::~LinkedQueue(){

}

template <typename T>
bool LinkedQueue<T>::isEmpty(){
    
    if(this->used  < 1){
        return true;
    }
    
    return false;
}

template <typename T>
void LinkedQueue<T>::dequeue(T& element){
    
    if(!isEmpty()){
        
        Node<T>* elem = front;
        front = front->next;
        element = elem->data;
        delete elem;
        used--;
    }
}

template <typename T>
T LinkedQueue<T>::peek(){
    if(used != 0){
        
        return front->data;
    }
    
    return NULL;
}

#endif /* Queue_hpp */
