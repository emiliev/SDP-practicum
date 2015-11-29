//
//  Solver.hpp
//  HW2
//
//  Created by Emil Iliev on 11/28/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#ifndef Solver_hpp
#define Solver_hpp

#include "iostream"
#include "Solver.hpp"
#include "Table.hpp"
#include "Cell.hpp"
#include "LinkedQueue.hpp"
#include "DinamicArray.hpp"

class Solver{
    
public:
    Solver();
    ~Solver();
    void getAllCells(Table matrix, Cell* startingCell);
    void showPaths(Table &matrix);
    void showCells();
    void showCurrentPath();
private:
    
    DinamicArray<Cell*> dArray; 
    DinamicArray<Cell*> currentPath;
    Cell* firstCell;
    int numberOfPaths;
    
    void showAllPaths(Cell* startCell, Cell* endCell, Table &matrix);
    void addIfPossibleAndNotVissited(LinkedQueue<Cell*>& queue, Cell* pCell);
    void resize();
};
#endif /* Solver_hpp */
