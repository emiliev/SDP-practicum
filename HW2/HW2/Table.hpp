//
//  Table.hpp
//  HW2
//
//  Created by Emil Iliev on 11/18/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#ifndef Table_hpp
#define Table_hpp

#include <iostream>
#include "Cell.hpp"

static const int dx[] = {0,-1,0,1};
static const int dy[] = {-1,0,1,0};

class Table{
    
    public:

    Table();
    Table(int, int);
    ~Table();
    Table(Table const &);
    Table& operator=(Table const &);
    void populateTable(char**);
    void showTable();
    
    int getRows();
    int getCols();
    Cell* getElement(int, int);
    void unMarkCells();
    
    bool validNextMove(Cell* ,int );
    private:
    
        Cell** table;
        int rows;
        int cols;
    
        void makeTable();
        void releaseTable();
        void copyFrom(Table const &);
};

#endif /* Table_hpp */
