//
//  Solver.cpp
//  HW2
//
//  Created by Emil Iliev on 11/28/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//
#include "Solver.hpp"


static int dx[] = {0,-1,0,1};
static int dy[] = {-1,0,1,0};


Solver::Solver(){
    
    this->numberOfPaths = 1;
    this->paths = new DinamicArray<Cell*>[1];
}


Solver::~Solver(){

    
}


void Solver::getAllCells(Table matrix, Cell* startingCell){
    
    std::queue<Cell*> newQueue;
    newQueue.push(startingCell);
    
    Cell* newCell = NULL;
    while (!newQueue.empty()) {
        
        Cell* curCell = newQueue.front();
        newQueue.pop();
        curCell->mark();
        dArray.addElement(curCell);
        for(int index = 0; index < 4; ++index){
            
            if(matrix.validNextMove(curCell, index)){
                
                newCell = matrix.getElement(curCell->getRow() + dx[index], curCell->getCol() + dy[index]);
                addIfPossibleAndNotVissited(newQueue, newCell);
                
            }
        }
    }
}

void Solver::showCells(){
    
    for(int index = 1; index < dArray.getLength(); ++index){
        
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


void Solver::showPaths(Cell *startCell, Table &matrix){
    
    for(int index = 1; index < dArray.getLength(); ++index){
        
        Cell *endCell = dArray.getElementAtIndex(index);
        endCell->print();
        std::cout<<"\n";
        
        showAllPaths(startCell, endCell, matrix);
        showCurrentPath();
    }
}

void Solver::showAllPaths(Cell* startCell, Cell* endCell, Table &matrix){
    
    if(startCell->getRow() == endCell->getRow() && startCell->getCol() == endCell->getCol()){
        
        resize();
        return;
    }
    
    startCell->mark();
    for(int index = 0; index < 4; ++index){
        
        if(matrix.validNextMove(startCell, index)){
            
            Cell* newCell = matrix.getElement(startCell->getRow() + dx[index], startCell->getCol() + dy[index]);
            if(!(newCell->isVisited() || newCell->isWall())) {
                
                paths[numberOfPaths - 1].addElement(newCell);
                showAllPaths(newCell, endCell, matrix);

            }
            
        }
    }
    
    startCell->unmark();
    
}


void Solver::showCurrentPath(){
    
    for(int index = 0; index < paths[numberOfPaths - 1].getLength(); ++index){
        Cell *temp = paths[numberOfPaths - 1].getElementAtIndex(index);
            temp->print();
    }
    std::cout<<"\n";
    
}

void Solver::resize(){
    
    this->numberOfPaths++;
    DinamicArray<Cell*>* newPaths = new DinamicArray<Cell*>[numberOfPaths];
    for(int index = 0; index < numberOfPaths - 1; ++index){
        
        newPaths[index] = this->paths[index];
    }
    
    delete [] paths;
    
    this->paths = newPaths;
}

