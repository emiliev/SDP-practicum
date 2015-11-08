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
        Node<T>* rare;
        size_t used;
};



template <typename T>
Node<T>::Node(T newData, Box<T>* p = 0){
    this->data = newData;
    this->next = p;
}

template <typename T>
LinkedQueue<T>::LinkedQueue(){
    
    this->used = 0;
    this-front = 0;
    this->rare = 0;
}

template <typename T>
void LinkedQueue<T>::enqueue(T element){
    
    Node<T>* elem = new Node(element,rare);
    front = elem;
    used++;
}


bool LinkedQueue<T>::isEmpty{
    
    if(this->used > 0){
        return false;
    }
    
    return true;
}

void LinkedQueue<T>::dequeue(T& element){
    
    
}

#endif /* Queue_hpp */
