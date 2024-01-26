//
// Created by Ara Cantanhede Araujo on 1/26/24.
//

#ifndef CHESS_POSITION_H
#define CHESS_POSITION_H
#include "testPosition.h"
#include <string>
#pragma once

using std::string;

class Position {
    friend PositionTest;
public:
    // Constructors
    Position() : location(0) {}
    Position(int row, int col) : location(0) {};

    // Getters
    int getRow() { return 0; }
    int getCol() { return 0; }
    bool isValid() {return true; }
    bool isInvalid() { return false; }

    // Setters
    void setRow(int row) { location = row; }
    void setCol(int col) { location = col; }
    void set(int row, int col) {location = row+col; } ;

    // Overload
    Position& operator=(string position);
    Position& operator+=(Position increment);
    bool operator==(const Position& other) { return true; };


private:
    int location;

};


#endif //CHESS_POSITION_H
