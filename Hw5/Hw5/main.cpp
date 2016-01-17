//
//  main.cpp
//  Hw5
//
//  Created by Emil Iliev on 1/10/16.
//  Copyright © 2016 Emil Iliev. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string.h>
#include "myString.hpp"
#include "DinamicArray.hpp"
#include <iomanip>
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
                group[currentCol].setData(buffer);
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
        char buffer[256] = {};
        int index = 0;
        bool isFirst = true;
        while (reader.read(&symbol, sizeof(symbol))) {
            
            if(symbol == ',' &&  isFirst){
                
                members[currentRow].setData(buffer);
                memset(buffer, 0, 256);
                index = 0;
                isFirst = false;
                continue;
            }

            if(!isFirst){
                
                if (symbol == '0' || symbol == '1'){
                    
                    size_t value = symbol - '0';
                    matrix[currentRow][currentCol] = value;
                    currentCol++;
                }
                
                else if (symbol == '\n'){
                    isFirst = true;
                    currentRow++;
                    currentCol = 0;
                }
            }
            
            else{
                
                buffer[index] = symbol;
                index++;
            }
        }
    }
}

size_t** transpose(size_t** matrix, size_t rows, size_t cols){
    
    size_t** transposeMatrix = new size_t*[cols];
    for(size_t index = 0; index < cols; ++index){
        
        transposeMatrix[index] = new size_t[rows];
        for(size_t elem = 0; elem < rows; ++elem){
            
            transposeMatrix[index][elem] = matrix[elem][index];
        }
    }
    
    return transposeMatrix;
}

size_t** muliplyMatrix(size_t** firstMatrix, size_t** secondMatrix, size_t firstRows, size_t firstCols, size_t secondRows, size_t secondCols){
    
    if(firstCols != secondRows){
        
        return NULL;
    }
    
    size_t** newMatrix = new size_t*[firstRows];
    for(size_t index = 0; index < firstRows; ++index){
        
        newMatrix[index] = new size_t[secondCols];
        for(size_t elem = 0; elem < secondCols ;++elem){
            
            newMatrix[index][elem] = 0;
            if(elem == index){
                continue;
            }
            
            for(size_t num = 0; num < firstCols; ++num){
                
                newMatrix[index][elem] += firstMatrix[index][num] * secondMatrix[num][elem];
            }
        }
    }
    
    return newMatrix;
}

void mostConenctions(size_t** matrix, size_t rows, size_t cols, DinamicArray<int>& dArray){
    
    size_t number = 0;
    for(int index = 0; index < rows; ++index){
        
        for(int elem = index; elem < cols; ++elem){
            
            if (number == matrix[index][elem]) {

                dArray.addElement(index);
                dArray.addElement(elem);
            }
        
            if(number  < matrix[index][elem]){

                dArray.clear();
                number = matrix[index][elem];
                dArray.addElement(index);
                dArray.addElement(elem);
            }
        }
    }
    cout<<number<<'\n';
}

float** FloydWarshall(size_t**& matrix, size_t digit){

    float** dist = new float*[digit];
    for(int index = 0; index < digit; ++index){
        
        dist[index] = new float[digit];
        for(int elem = 0; elem < digit; ++elem){
            
            dist[index][elem] = matrix[index][elem];
        }
    }

    for(int k = 0; k < digit; ++k){
        
        for(int i = 0; i < digit; ++i){
            
            for(int j = 0; j < digit; ++j){
                
                if(dist[i][k] > dist[i][k] + dist[k][j]){
                    
                    dist[i][j] = dist[k][j] + dist[i][k];
                }
            }
        }
    }
    
    return dist;
}

float heighest(float** dist, size_t digit){
    
    float temp = 0;
    float  num = 0;
    for(int i = 0; i < digit; ++i){
        
        for(int j = 0; j < digit; ++j){
            
            temp +=dist[i][j];
        }
        temp = 1 / temp;
        if(temp > num){
            num = temp;
        }
    }
    
    return num;
}

int main(int argc, const char * argv[]) {

    string path;
    getline(cin,path);
    
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
        };
    }
    
    input.close();
    size_t **matrix;
    allocate(matrix, numberOfRows, numberOfCommas);
    MyString* groupList = new MyString[numberOfCommas + 1];
    MyString* nameList = new MyString[numberOfRows];
    
    ifstream reader(path);
    if(reader){
        
        populateGroup(reader, groupList);
        populateMembers(reader, nameList, matrix);
    }
    reader.close();
    
    size_t** transposedMatrix = transpose(matrix, numberOfRows , numberOfCommas);
    size_t** groupToGroup = muliplyMatrix(transposedMatrix, matrix, numberOfCommas, numberOfRows, numberOfRows , numberOfCommas);
    size_t** PersonToPerson = muliplyMatrix(matrix, transposedMatrix, numberOfRows, numberOfCommas, numberOfCommas, numberOfRows);
    
    DinamicArray<int> connectionArray;
   
    //Group to Group - table
    for(int i = 0; i < numberOfCommas + 1; ++i){
        
        cout<<setw(15)<<groupList[i].getData()<<"\t";
    }
    cout<<endl;
    for(int i = 0; i < numberOfCommas; ++i){
        
        cout<<setw(15)<<groupList[i + 1].getData();
        for(int j = 0; j < numberOfCommas; ++j){
            cout<<setw(10)<<groupToGroup[i][j]<<"\t\t";
        }
        cout<<endl;
    }
   
//    Group to group  - results
    cout<<"\n\tGroups with most common people: ";
    mostConenctions(groupToGroup, numberOfCommas, numberOfCommas, connectionArray);
    size_t groupLen = connectionArray.getLength();
    for(int i = 0; i < groupLen; i+= 2){
        int fp = connectionArray.getElementAtIndex(i);
        int sp = connectionArray.getElementAtIndex(i + 1);
        cout<<groupList[fp + 1].getData()<<" - "<<groupList[sp + 1].getData()<<endl;
    }
 
//    Person to Person - results
    connectionArray.clear();
    cout<<endl<<"\tPeople with most common memberships: ";
    mostConenctions(PersonToPerson, numberOfRows, numberOfRows, connectionArray);
    size_t pLen = connectionArray.getLength();
    for(int i = 0; i < pLen; i+= 2){
        int fp = connectionArray.getElementAtIndex(i);
        int sp = connectionArray.getElementAtIndex(i + 1);
        cout<<nameList[fp].getData()<<" - "<<nameList[sp].getData()<<endl;
    }
    
   float** fw =  FloydWarshall(PersonToPerson, numberOfRows);
    
    float a = heighest(fw, numberOfRows);
    cout<<"closeness: "<<a<<endl;
    

    //    Release Memory
    delete [] groupList;
    delete [] nameList;
    for(int index = 0; index < numberOfRows; ++index){
        
        delete fw[index];
    }
    
    delete [] fw;
    
    release(PersonToPerson, numberOfRows);
    release(groupToGroup, numberOfCommas);
    release(transposedMatrix, numberOfCommas);
    release(matrix, numberOfRows);

    return 0;
}
