//
//  main.cpp
//  HW2
//
//  Created by Emil Iliev on 11/17/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include <iostream>
#include "Cell.hpp"
#include "Table.hpp"
#include "Solver.hpp"

using namespace std;
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
    dfs.showPaths(table);
    
    for(int index = 0; index < numberOfRows; ++index){
        
        delete [] lab[index];
    }
    
    delete []lab;
    return 0;
}
