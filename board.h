//
// Created by Ara Cantanhede Araujo on 1/26/24.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "uiDraw.h"
#include "position.h"
#include "move.h"
#include "piece.h"

#pragma once


class Board {

public:

    Board();

    int getCurrentMove() const { return currentMove; };
    bool whiteTurn() {return currentMove % 2 != 0; };
    void display(Position posHover, Position PosSel);

    Piece* operator[](Position& pos) const;

    void reset();

//    void assign(Piece piece);
private:

    // Attributes
    Piece * board[8][8];

    int currentMove;

    // Methods

};


#endif //CHESS_BOARD_H
