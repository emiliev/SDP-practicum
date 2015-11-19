//
//  Cell.hpp
//  HW2
//
//  Created by Emil Iliev on 11/18/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#ifndef Cell_hpp
#define Cell_hpp

#include <stdio.h>
#include "iostream"
class Cell{
    
    public:
    
        Cell();
        Cell(char, int, int);
        ~Cell();
    
        int getRow();
        int getCol();
        char getSymbol();
    
        void mark();
        void unmark();
        void print();
        bool isVisited();
        bool isWall();
        void init(char,int, int);
    private:
    
        char symbol;
        int row;
        int col;
    
        bool visit;
        void setRow(int );
        void setCol(int );
        void setSymbol(char);
    
};
#endif /* Cell_hpp */
