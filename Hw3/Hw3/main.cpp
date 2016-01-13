//
//  main.cpp
//  Hw3
//
//  Created by Emil Iliev on 12/12/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include <iostream>
#include "string.h"

const int kLengthOfTask = 6;
const int kMaxLength = 8;
const int kRequestLength = 30;

void allocate(char**& text, int _rows){
    
    text = new char*[_rows];
    for(int index = 0; index < _rows; ++index){
        
        text[index] = new char[kMaxLength];
    
    }
}

void releaseMemory(char**& text, int _rows){
    
    for(int index = 0; index < _rows; ++index){
        
        delete text[index];
    }
    
    delete [] text;
}


void mergeArray(char** leftPart, int leftSize, char** rightPart, int rightSize, char** words){
    
    int aIndex = 0;
    int bIndex = 0;
    int cIndex = 0;
    while (aIndex < leftSize && bIndex < rightSize) {
        
        if(strcmp(leftPart[aIndex], rightPart[bIndex]) < 0){
        
            strcpy(words[cIndex], leftPart[aIndex]);
            aIndex++;
        }
        
        else{
            
            strcpy(words[cIndex], rightPart[bIndex]);
            bIndex++;
        }
        
        cIndex++;
    }
    
    
    if(aIndex == leftSize){
        
        for(; bIndex < rightSize; ++bIndex, ++cIndex){
            
            strcpy(words[cIndex], rightPart[bIndex]);
        }
    }
    
    else{
        
        for(; aIndex < leftSize; ++aIndex, ++cIndex){
        
            strcpy(words[cIndex], leftPart[aIndex]);
        }
    }
}

void merge(char**& words, int startPoint, int endPoint){
    
    if(startPoint == endPoint){
        
        return;
    }
    
    int middle = (startPoint + endPoint) / 2;
    merge(words, startPoint, middle);
    merge(words, middle + 1, endPoint);
    
    char** leftPart, **rightPart, **result;
    
    allocate(leftPart, middle - startPoint + 1);
    allocate(rightPart, endPoint - middle);
    allocate(result, endPoint - startPoint + 1);
    
    for(int index = startPoint; index <= middle; ++index){
        
        strcpy(leftPart[index - startPoint], words[index]);
    }
    
    for(int index = middle + 1; index <= endPoint; ++index){
        
        strcpy(rightPart[index - (middle + 1)], words[index]);
    }
   
    mergeArray(leftPart, middle - startPoint + 1, rightPart, endPoint - middle, result);
    for(int index = startPoint; index <= endPoint; ++index){
        
        strcpy(words[index], result[index - startPoint]);
    }
    
    releaseMemory(leftPart, middle - startPoint + 1);
    releaseMemory(rightPart, endPoint - middle);
    releaseMemory(result, endPoint - startPoint + 1);
}

int lengthOfPrefix(char* word){
    int length = 0;
    while (*word) {
        
        if(*word == ' '){
            
            return length;
        }
        
        length++;
        word++;
    }
    
    return length;
}

void newLimits(char* request, int &newStar, int &newEnd){

        request += kLengthOfTask;
        newStar = std::atoi(request++);
        newEnd = std::atoi(request);
}

void query(char* request, char** words, int newStart, int newEnd){
    
    request += kLengthOfTask;
    int length = lengthOfPrefix(request) + 1;
    char* prefix = new char[length];
    strncpy(prefix, request, length - 1);
    prefix[length - 1] = '\0';
    int counter  = 0;
    
    for(int index = newStart; index <= newEnd; ++index){
        
        if(strncmp(prefix, words[index], length - 1) == 0){
            
            counter++;
        }
    }
    
    std::cout<<"\nQuery: "<<prefix<<" "<<counter<<'\n';
    delete prefix;
}

int main(int argc, const char * argv[]) {

    int numberOfTests;
    std::cout<<"Enter number of tests: ";
    std::cin>>numberOfTests;
    char** words;
    while (numberOfTests != 0) {
       
        int numberOfWords, numberOfRequests;
        std::cout<<"Enter number of words and requests: ";
        std::cin>>numberOfWords>>numberOfRequests;
        int newStart = 0;
        int newEnd = numberOfWords - 1;
        
        allocate(words, numberOfWords);
        std::cin.ignore();
        for(int index  = 0; index < numberOfWords; ++index){
            
            std::cout<<"Enter word: ";
            char word[kMaxLength];
            std::cin.getline(word, kMaxLength);
            strcpy(words[index],word);
        }
        
        merge(words, 0, numberOfWords - 1);
        
        std::cout<<"\n";
        for(int index = 0; index < numberOfWords; ++index){
            
            std::cout<<words[index]<<" ";
        }
        
        std::cout<<"\n";

        while (numberOfRequests != 0) {
        
            char request[kRequestLength];
            std::cout<<"Enter request: ";
            std::cin.getline(request, kRequestLength);
            char text[kLengthOfTask + 1];
            strncpy(text, request, kLengthOfTask - 1);
            text[kLengthOfTask - 1] = '\0';
            
            if(strcmp(text, "QUERY") == 0){
                
                query(request, words, newStart, newEnd);
            }
            else if(strcmp(text, "ENTER") == 0){
                
                newLimits(request,newStart, newEnd);
                if(newEnd > numberOfWords){
                    
                    newEnd = numberOfWords - 1;
                }
                
                if(newStart < 0){
                    
                    newStart = 0;
                }
            }
            
            else{
                
                std::cout<<"INCORECT REQUEST!\n";
            }
            numberOfRequests--;
        }
        
        numberOfTests--;
        releaseMemory(words, numberOfWords);
    }

    return 0;
}
