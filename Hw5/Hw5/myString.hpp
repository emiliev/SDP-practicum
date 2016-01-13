//
//  myString.hpp
//  Hw5
//
//  Created by Emil Iliev on 1/13/16.
//  Copyright © 2016 Emil Iliev. All rights reserved.
//

#ifndef myString_hpp
#define myString_hpp

#include <stdio.h>

class MyString{
    
    public:
    
    MyString();
    ~MyString();
    MyString(char* string);
    MyString(MyString const &other);
    MyString& operator=(MyString const &other);
    
    size_t getLength();
    char* getData();
    void setData(char* _data);
    void append(char* symbol);
    private:
    
    char* data;
    size_t length;
    size_t allocatedLength;
    void setLength(size_t _length);
    void resize();
    
    void del();
    void copyFrom(MyString const &other);
    
};

#endif /* myString_hpp */
