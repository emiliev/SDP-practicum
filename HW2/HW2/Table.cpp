//
//  Table.cpp
//  HW2
//
//  Created by Emil Iliev on 11/18/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include "Table.hpp"

Table::Table(int numOfRows, int numOfCols){
    
    this->rows = numOfRows;
    this->cols = numOfCols;

    this->makeTable();
}

Table::~Table(){
    
    this->releaseTable();
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
            
            this->table[row][col].setSymbol(matrix[row][col]);
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
