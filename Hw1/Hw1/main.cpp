//
//  main.cpp
//  Hw1
//
//  Created by Emil Iliev on 10/28/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include <iostream>
#include "LinkedStack.hpp"

const int kMaxSize = 1000;

struct charStruct{
    
    size_t expression, number, text;
};

void process(char* &word){
    
    char* start = word;
    LinkedStack<charStruct> stack;
    
    while (*start) {
        
        charStruct frame;
        if(*start >= '0' && *start <= '9'){
            
            frame.expression = start - word;
            frame.number = atoi(start);
            
            while (*start && *start != '(') {
                
                start++;
            }
            
            frame.text = ++start - word;
            stack.push(frame);
        }
        
        else if(*start == ')'){
            
            stack.pop(frame);
            size_t lengthOfSubText = start - (word + frame.text);
            size_t newLength = frame.number * lengthOfSubText;
            char* rep = new char[newLength + 1];
            
            for(int index = 0; index < frame.number; ++index){
                
                strncat(rep, word + frame.text, lengthOfSubText);
            }
            
            rep[newLength] = '\0';
            size_t difference = frame.expression;
            char* newWord = new char[difference + newLength + strlen(start)];
            strncpy(newWord, word, difference);
            strcat(newWord, rep);
            strcat(newWord, ++start);
            delete [] word;
            delete [] rep;
            word = newWord;
            start = newWord + difference + newLength;
        }
        else{
            
            ++start;
        }
    }
    
}


bool isPassable(char* word, int row){
    
    if(word[row]){
        
        return true;
    }
    
    return false;
}

int main(int argc, const char * argv[]) {
    
    
    char* word = new char[kMaxSize];
    std::cin.getline(word, kMaxSize);
    
    process(word);
    std::cout<<word<<"\n";
    
    delete [] word;
    return 0;
}
