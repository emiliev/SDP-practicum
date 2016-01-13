
//
//  myString.cpp
//  Hw5
//
//  Created by Emil Iliev on 1/13/16.
//  Copyright © 2016 Emil Iliev. All rights reserved.
//

#include "myString.hpp"
#include "string.h"
#include <iostream>
MyString::MyString(){
    
    setLength(0);
    allocatedLength = 1;
    this->data = new char[allocatedLength];
    data[0] = '\0';
    

}

MyString::MyString(char* _data){

    setData(_data);
}

MyString::~MyString(){
    
    del();
}


MyString::MyString(MyString const &other){
    
    copyFrom(other);
}

MyString& MyString::operator=(MyString const &other){
    
    if(this != &other){
        
        del();
        copyFrom(other);
    }
    
    return *this;
}


void MyString::setData(char* _data){
    
    del();
    size_t newLength = strlen(_data) + 1;
    setLength(newLength);
    this->data = new char[newLength];
    strcpy(data, _data);
    allocatedLength = newLength;
}

void MyString::setLength(size_t _length){
    
    this->length = _length;
}

size_t MyString::getLength(){
    
    return  this->length;
}

void MyString::append(char* symbol){
    
    
    if(allocatedLength <= length) {
        
        resize();
    }
    data[length++] = *symbol;
    
}

char* MyString::getData(){
    
    return this->data;
}

void MyString::copyFrom(MyString const &other){
    
    setLength(other.length);
    setData(other.data);
}

void MyString::del(){
    
    delete [] data;
    length = 0;
}

void MyString::resize(){
    
    allocatedLength *= 2;
    char* buffer = new char[allocatedLength];
    strcat(buffer, data);

    delete [] data;
    
    data = buffer;
    
}
