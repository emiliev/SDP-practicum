//
//  Cell.cpp
//  HW2
//
//  Created by Emil Iliev on 11/18/15.
//  Copyright © 2015 Emil Iliev. All rights reserved.
//

#include "Cell.hpp"

Cell::Cell(){
    
    this->init('.', 0, 0);
}

Cell::Cell(char _symbol, int _row, int _col){
    
    
    this->init(symbol, _row, _col);
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

void Cell::init(char _symb, int _row, int _col){
    
    this->setSymbol(_symb);
    this->setRow(_row);
    this->setCol(_col);
}