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

    Board(ogstream* pgout);

    int getCurrentMove() const { return currentMove; };
    bool whiteTurn() const {return currentMove % 2 != 0; };
    void display(const Position& posHover, const Position& PosSel); // added possible as parameter

    const Piece& operator[](const Position& pos) const{
        return *board[pos.getRow()][pos.getCol()];
    }

    Piece& operator[](Position& pos){
        return *board[pos.getRow()][pos.getCol()];
    }

    void operator -= (const Position & pos);

    const Piece* operator = (Piece *pRhs);

    void reset();

    void remove(const Position& pos);

    void move(const Move& move);

    void swap(Position & pos1,Position & pos2);

protected:

    // Attributes
    Piece * board[8][8];
    int currentMove;
    ogstream* pgout;
};


#endif //CHESS_BOARD_H

