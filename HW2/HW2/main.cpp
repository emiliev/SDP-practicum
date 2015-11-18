//
//  main.cpp
//  HW2
//
//  Created by Emil Iliev on 11/17/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include <iostream>
#include "queue"
#include "Cell.hpp"
#include "Table.hpp"

using namespace std;

//void BFS(Table matrix, Cell startingCell){
//
//    
//    queue<Cell> newQueue;
//    newQueue.push(startingCell);
//    
//    while (!newQueue.empty()) {
//        
//        Cell newCell = newQueue.front();
//        newQueue.pop();
//        
//        
//    }
//}


void getAllCells(Table matrix, Cell startingCell){

    bool isAdded = false;
    queue<Cell> newQueue;
    newQueue.push(startingCell);
    
    while (!isAdded) {
        
        isAdded = false;
        //get neighbours of current cell
        
        
    }
}

int main(int argc, const char * argv[]) {
   
    int numberOfRows, numberOfCols;
    cout<<"Size of table: ";
    cin>>numberOfRows>>numberOfCols;
    
    char** lab = new char*[numberOfRows];
    for(int index = 0; index < numberOfRows; ++index){
        
        lab[index] = new char[numberOfCols];
    }
    
    cout<<"Populate table: ";
    for(int i = 0; i < numberOfRows; ++i){\
        
        for(int j = 0; j < numberOfCols; ++j){
            
            cin>>lab[i][j];
        }
    }
    
    queue<char> newQueue;
    
    int curRow, curCol;
    cout<<"Enter starting possition: ";
    cin>>curRow>>curCol;
 
    Table table(numberOfRows,numberOfCols);
    table.populateTable(lab);
    table.showTable();
    
    Cell currentCell = table.getElement(curRow, curCol);
   // BFS(table, currentCell);
//    newQ.push(table.getElement(curRow, curCol));
//    while (!newQueue.empty()) {
//        
//        char curSym = newQueue.front();
//        newQueue.pop();
//        
//        
//        
//    }
//    
    
  //  int sameLab[3][3] = {0,};
    
    
    return 0;
}
