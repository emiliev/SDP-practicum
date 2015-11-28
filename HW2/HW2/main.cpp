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
#include "Solver.hpp"

using namespace std;

//void showAllPaths(Cell* startingCell, Cell* &endCell, Table &matrix, DinamicArray<Cell*> &allPaths){
//    
//    if(startingCell->getCol() == endCell->getCol() && startingCell->getRow() == endCell->getRow()){
//        
//        for(int index = 0; index < allPaths.getLength(); ++index){
//            Cell* a = allPaths.getElementAtIndex(index);
//            a->print();
//        }
//        
//        cout<<"\n";
//        
//        return;
//    }
//    
//    int maxRow = matrix.getRows();
//    int maxCol = matrix.getCols();
//    
//    startingCell->mark();
//    
//    for(int index = 0; index < 4; ++index){
//     
//        if((startingCell->getRow() + dx[index] >= 0) && (startingCell->getRow() + dx[index] < maxRow) &&
//           (startingCell->getCol() + dy[index] >= 0) && (startingCell->getCol() + dy[index] < maxCol)){
//            
//            Cell* newCell = matrix.getElement(startingCell->getRow() + dx[index], startingCell->getCol() + dy[index]);
//            
//            if(newCell->isWall() || newCell->isVisited()){
//                
//                continue;
//            }
//            
//            allPaths.addElement(newCell);
//            showAllPaths(newCell, endCell, matrix, allPaths);
//        }
//    }
//    startingCell->unmark();
//}

int main(int argc, const char * argv[]){
   
    int numberOfRows, numberOfCols;
    cout<<"Size of table: ";
    cin>>numberOfRows>>numberOfCols;
    
    char** lab = new char*[numberOfRows];
    for(int index = 0; index < numberOfRows; ++index){
        
        lab[index] = new char[numberOfCols];
    }
    
    cout<<"Populate table: \n";
    for(int i = 0; i < numberOfRows; ++i){\
        
        for(int j = 0; j < numberOfCols; ++j){
            
            cin>>lab[i][j];
        }
    }

    int curRow, curCol;
    cout<<"Enter starting possition: ";
    cin>>curRow>>curCol;
 
    Table table(numberOfRows,numberOfCols);
    table.populateTable(lab);
    table.showTable();
    Cell* currentCell = table.getElement(curRow, curCol);
    currentCell->mark();
    
    Solver dfs;
    
    if(!currentCell->isWall()){
    
        dfs.getAllCells(table, currentCell);
    }
    
    dfs.showCells();
    table.unMarkCells();
    cout<<"\n";
    dfs.showPaths(currentCell, table);
    
    for(int index = 0; index < numberOfRows; ++index){
        
        delete [] lab[index];
    }
    
    delete []lab;
    return 0;
}
