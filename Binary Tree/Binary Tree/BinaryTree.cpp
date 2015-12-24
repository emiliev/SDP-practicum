//
//  BinaryTree.cpp
//  Binary Tree
//
//  Created by Emil Iliev on 12/21/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include <stdio.h>
#include "iostream"

template <typename T>
class BinaryTree{

    private:
        struct Node{
        
            T data;
            Node* left;
            Node* right;
        
            Node(int x): data(x), left(0), right(0){};
            ~Node(){
            
                if(left){
                
                    delete left;
                }
            
                if(right){
                
                    delete right;
                }
            }
    };

        Node* root;
        void privateInsert(Node*& r, T _data);
        void privatePrint(Node* r);
        void privateRemove(Node*& r, T _data);
        int removeMin(Node*& r);
    public:
    
        void insert(T _data);
        void print();
        void remove(T _data);
};


template <typename T>
void BinaryTree<T>::privateRemove(Node*& r,T _data){
    
    if(!r){
        
        return;
    }
    
    if(r->data > _data){
        
        privateRemove(r->left, _data);
    }
    else if(r->data < _data){
        
        privateRemove(r->right, _data);
    }
    
    else{
        
        if(!r->left || !r->right){
            
            Node* temp = r->left? r->left : r->right;
            delete r;
            r = temp;
        }
        
        else{
            
            r->data = removeMin(r->right);
        }
    }
}

template <typename T>
int BinaryTree<T>::removeMin(Node*& r){
    
    if(!r->left){
        int x = r->data;
        
        r = r->right;
        delete r;
        return x;
    }
    
    return removeMin(r->left);
}

template <typename T>
void BinaryTree<T>::remove(T _data){
    
    privateRemove(root, _data);
}

template <typename T>
void BinaryTree<T>::print(){
    
    privatePrint(root);
}

template <typename T>
void BinaryTree<T>::privatePrint(Node* r){
    
    if(r){
        
        privatePrint(r->left);
        std::cout<<r->data<<" ";
        privatePrint(r->right);
    }
}

template <typename T>
void BinaryTree<T>::insert(T _data){
    
    privateInsert(root, _data);
}

template <typename T>
void BinaryTree<T>::privateInsert(Node*& r, T _data){
    
    if(!r){
        
        r = new Node(_data);
    }
    else{
        
        if(r->data > _data ){
            
            privateInsert(r->left, _data);
        }
        
        else{
            
            privateInsert(r->right, _data);
        }
    }
}