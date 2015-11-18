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
        Cell(char);
        ~Cell();
    
        int getRow();
        int getCol();
        char getSymbol();
        void setRow(int );
        void setCol(int );
        void setSymbol(char);
    
        bool isEntered();
    
    private:
    
        char symbol;
        int row;
        int col;
    
    
};
#endif /* Cell_hpp */
