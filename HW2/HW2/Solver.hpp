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
#include "queue"
#include "DinamicArray.hpp"

class Solver{
    
public:
    Solver();
    ~Solver();
    void getAllCells(Table matrix, Cell* startingCell);
    void showPaths(Cell* startCell, Table &matrix);
    void showCells();
    void showCurrentPath();
private:
    
    DinamicArray<Cell*> dArray; // масив с достижимите клетки
    void addIfPossibleAndNotVissited(std::queue<Cell*>& queue, Cell* pCell);
    DinamicArray<Cell*> *paths; //всички пътища до дадена клетка
    void showAllPaths(Cell* startCell, Cell* endCell, Table &matrix);
   
    int numberOfPaths;
    void resize();
};
#endif /* Solver_hpp */
