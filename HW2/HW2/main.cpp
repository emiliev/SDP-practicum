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
    
//    cout<<isPassable(lab, curRow, curCol, 3, 3)<<"\n";
    
    
    newQueue.push(lab[curRow][curCol]);
    Table table(3,3);
    table.populateTable(lab);
    table.showTable();
  
    while (!newQueue.empty()) {
        
        char curSym = newQueue.front();
        newQueue.pop();
        
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
  //  int sameLab[3][3] = {0,};
    
    
    return 0;
}
