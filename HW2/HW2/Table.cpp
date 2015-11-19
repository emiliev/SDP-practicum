//
//  Table.cpp
//  HW2
//
//  Created by Emil Iliev on 11/18/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include "Table.hpp"


Table::Table(){

}

Table::Table(int numOfRows, int numOfCols){
    
    this->rows = numOfRows;
    this->cols = numOfCols;

    this->makeTable();
}

Table::~Table(){
    
    this->releaseTable();
}

Table::Table(Table const &other){
    
    copyFrom(other);
}

Table& Table::operator=(Table const &other){
    
    if(this != &other){
        releaseTable();
        copyFrom(other);
    }
    
    return *this;
}

void Table::makeTable(){
    
    this->table = new Cell*[rows];
    for(int index = 0; index < rows; ++index){
        
        table[index] = new Cell[cols];
    }
}

void Table::releaseTable(){

    for(int i = 0; i < rows; ++i){
       
        delete[] table[i];
    }
    
    delete[] table;
    table = NULL;
}

void Table::populateTable(char** matrix){
    
    for(int row = 0; row < this->rows; ++row){
        
        for(int col = 0; col < this->cols; ++col){
            
           this->table[row][col].init(matrix[row][col], row, col);
        }
    }
}

void Table::showTable(){
    
    for(int index = 0; index < rows; ++index){
        
        for(int  cell = 0; cell < cols; ++cell){
            
            std::cout<<table[index][cell].getSymbol()<<" ";
        }
        
        std::cout<<"\n";
    }
}

Cell* Table::getElement(int _row, int _col){
    
    return &table[_row][_col];
}

int Table::getRows(){
    
    return this->rows;
}

int Table::getCols(){
    
    return this->cols;
}

void Table::copyFrom(Table const &other){
    
    this->rows = other.rows;
    this->cols = other.cols;
    this->makeTable();
    for(int row = 0; row < rows; ++row){
        
        for(int col = 0; col < cols; ++col){
            
            table[row][col] = other.table[row][col];
        }
    }
}
