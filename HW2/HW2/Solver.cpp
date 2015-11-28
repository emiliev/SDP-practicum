//
//  Solver.cpp
//  HW2
//
//  Created by Emil Iliev on 11/28/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//
#include "Solver.hpp"

int dx[] = {0,-1,0,1};
int dy[] = {-1,0,1,0};

Solver::Solver(){
    
}

void Solver::getAllCells(Table matrix, Cell* startingCell){
    
    std::queue<Cell*> newQueue;
    newQueue.push(startingCell);
    
    int maxRow = matrix.getRows();
    int maxCol = matrix.getCols();
    
    Cell* newCell = NULL;
    while (!newQueue.empty()) {
        
        Cell* curCell = newQueue.front();
        newQueue.pop();
        curCell->mark();
        dArray.addElement(curCell);
        for(int index = 0; index < 4; ++index){
            
            if((curCell->getRow() + dx[index] >= 0) && (curCell->getRow() + dx[index] < maxRow) &&
               (curCell->getCol() + dy[index] >= 0) && (curCell->getCol() + dy[index] < maxCol)){
                
                newCell = matrix.getElement(curCell->getRow() + dx[index], curCell->getCol() + dy[index]);
                addIfPossibleAndNotVissited(newQueue, newCell);
                
            }
        }
    }
}

void Solver::showCells(){
    
    for(int index = 0; index < dArray.getLength(); ++index){
        
        Cell* tempCell = dArray.getElementAtIndex(index);
        tempCell->print();
    }
}

void Solver::addIfPossibleAndNotVissited(std::queue<Cell*>& queue, Cell* pCell){
    
    if(pCell && !pCell->isVisited() && !pCell->isWall()){
        
        pCell->mark();
        queue.push(pCell);
        
    }
}
