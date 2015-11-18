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

class Cell{
    
    public:
    
        Cell();
        Cell(char, int, int);
        ~Cell();
    
        int getRow();
        int getCol();
        char getSymbol();
    
        bool isEntered();
        void init(char,int, int);
    private:
    
        char symbol;
        int row;
        int col;
    
        void setRow(int );
        void setCol(int );
        void setSymbol(char);
    
};
#endif /* Cell_hpp */
