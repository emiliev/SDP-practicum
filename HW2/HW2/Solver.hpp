//
//  Solver.hpp
//  HW2
//
//  Created by Emil Iliev on 11/28/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#ifndef Solver_hpp
#define Solver_hpp


#include "Solver.hpp"
#include "Table.hpp"
#include "Cell.hpp"
#include "queue"
#include "DinamicArray.hpp"

class Solver{
    
public:
    Solver();
    
    void getAllCells(Table matrix, Cell* startingCell);
    void showAllPaths(Cell* startCell, Cell* endCell);
    void showCells();
private:
    
    DinamicArray<Cell*> dArray;
    void addIfPossibleAndNotVissited(std::queue<Cell*>& queue, Cell* pCell);
    
};
#endif /* Solver_hpp */
