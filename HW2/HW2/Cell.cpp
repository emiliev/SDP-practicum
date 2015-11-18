//
//  Cell.cpp
//  HW2
//
//  Created by Emil Iliev on 11/18/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include "Cell.hpp"

Cell::Cell(){
    
    this->symbol = '.';
    this->row = 0;
    this->col = 0;
}

Cell::Cell(char _symbol){
    
    this->setSymbol(_symbol);
}

Cell::~Cell(){

}

void Cell::setCol(int _col){
    
    this->col = _col;
}

void Cell::setRow(int _row){
    
    this->row = _row;
}

void Cell::setSymbol(char _symbol){
    
    this->symbol = _symbol;
}

int Cell::getCol(){
    
    return this->col;
}

int Cell::getRow(){
    
    return this->row;
}

char Cell::getSymbol(){
    
    return this->symbol;
}