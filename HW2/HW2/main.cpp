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


int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

void addIfPossibleAndNotVissited(queue<Cell*>& queue, Cell* pCell){
    
    if(pCell && !pCell->isVisited() && !pCell->isWall()){
        
        pCell->mark();
        queue.push(pCell);
        
    }
}

void getAllCells(Table matrix, Cell*& startingCell){

    queue<Cell*> newQueue;
    newQueue.push(startingCell);
    
    int maxRow = matrix.getRows();
    int maxCol = matrix.getCols();
    
    Cell* newCell = NULL;
    while (!newQueue.empty()) {
        
        Cell* curCell = newQueue.front();
        newQueue.pop();
        curCell->mark();
        
        curCell->print();
        for(int index = 0; index < 4; ++index){
          
            if((curCell->getRow() + dx[index] >= 0) && (curCell->getRow() + dx[index] < maxRow) &&
               (curCell->getCol() + dy[index] >= 0) && (curCell->getCol() + dy[index] < maxCol)){
  
                newCell = matrix.getElement(curCell->getRow() + dx[index], curCell->getCol() + dy[index]);
                addIfPossibleAndNotVissited(newQueue, newCell);
            }
        
        }
    }
    
}


int main(int argc, const char * argv[]){
   
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
    Cell* currentCell = table.getElement(curRow, curCol);
    currentCell->mark();
    getAllCells(table, currentCell);
    return 0;
}
