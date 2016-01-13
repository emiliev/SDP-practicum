//
//  main.cpp
//  Hw5
//
//  Created by Emil Iliev on 1/10/16.
//  Copyright © 2016 Emil Iliev. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "string.h"
#include "myString.hpp"
using namespace std;

//file path: /Users/Emo/FMI/SDP-practicum/Hw5/PaulRevereAppD.csv
size_t numberOfCols(string path){

    ifstream reader(path);
    string row;
    if(reader){
        
        getline(reader,row);
        cout<<row<<endl;
    }
    
    reader.close();
    
    size_t numberOfWords = 0;
    for(int index = 0; index < row.length(); ++index){
        if(row[index] == ','){
            numberOfWords++;
        }
    }
    
    return numberOfWords;
}

void allocate(size_t**& matrix, size_t rows, size_t cols){
    
    matrix = new size_t*[rows];
    for(size_t index = 0; index < rows; ++index){
    
        
        matrix[index] = new size_t[cols];
    }
}

void release(size_t**& matrix, size_t rows){
    
    for(size_t index = 0; index < rows; ++index){
    
        
        delete matrix[index];
    }
    
        delete [] matrix;
}

void populateGroup(ifstream& reader, MyString*& group){
    
    int currentCol = 0;
    if(reader){
        
        char symbol;
        char buffer[256] = {0};
        int index = 0;
        while (reader.read(&symbol, sizeof(symbol))) {
            
            if(symbol == ','){
                
                group[currentCol].setData(buffer);
                memset(buffer, 0, 256);
                currentCol++;
                index = 0;
                
                
                continue;
            }
            else if (symbol == '\n'){
                break;
            }
            else{
                buffer[index] = symbol;
                index++;
            }
            
            
        }
    }
}

void populateMembers(ifstream& reader, MyString*& members, size_t**& matrix){

    int currentRow = 0;
    int currentCol = 0;
    if(reader){
       
        char symbol;
        char buffer[256] = {0};
        int index = 0;
        bool isFirst = true;
        while (reader.read(&symbol, sizeof(symbol))) {
            
            if(symbol == ',' &&  isFirst){
                
                members[currentRow].setData(buffer);
                cout<<members[currentRow].getData()<<" ";
                memset(buffer, 0, 256);
                index = 0;
                isFirst = false;
                continue;
            }
//            else if(symbol == ',' && !isFirst){
//
//                size_t value = 0;
//                reader>>value;
//                matrix[currentRow][currentCol] = value;
//                currentCol++;
//                    
//            }
//            else if(symbol == '\n'){
//                    
//                currentRow++;
//                currentCol = 0;
//                isFirst = true;
//            }
            
            if(!isFirst){
                
                if (symbol == '0' || symbol == '1'){
                    
                    size_t value = symbol - '0';
                    matrix[currentRow][currentCol] = value;
                    cout<<matrix[currentRow][currentCol]<<" ";
                    currentCol++;
                }
                
                else if (symbol == '\n'){
                    isFirst = true;
                    currentRow++;
                    currentCol = 0;
                    cout<<endl;
                }
            }
            
            else{
                
                buffer[index] = symbol;
                index++;
            }
        }
    }
}

int main(int argc, const char * argv[]) {

    char path[256];
    cin.getline(path, 256);
    
    ifstream input(path);
    size_t numberOfCommas = 0;
    size_t numberOfRows = 0;
    if(input){
        
        bool firstLine = true;
        char word;
        while (input.read(&word, 1)) {

            if(word == '\n'){
                
                numberOfRows++;
                firstLine = false;
            }
            
            if(firstLine && word == ','){
                numberOfCommas++;
            }
        }
        cout<<endl;
    }
    
    input.close();
    
    cout<<numberOfCommas<<" "<<numberOfRows + 1<<endl;
    size_t **matrix;
    allocate(matrix, numberOfRows, numberOfCommas);
    MyString* groupList = new MyString[numberOfCommas + 1];
    MyString* nameList = new MyString[numberOfRows];
    
    ifstream reader(path);
    if(reader){
        
        populateGroup(reader, groupList);
        for(int index = 0; index < numberOfCommas; ++index){
            
            cout<<groupList[index].getData()<<" ";
            cout<<endl;
        }
        populateMembers(reader, nameList, matrix);
    }
    
    
    reader.close();
    release(matrix, numberOfRows);
    
    return 0;
}
