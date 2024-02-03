//
// Created by Ara Cantanhede Araujo on 1/26/24.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "uiDraw.h"
#include "position.h"
#include "move.h"
#include "testBoard.h"
#include "piece.h"


class Board {
    friend TestBoard;
public:

    Board();

    int getCurentMove() { return currentMove; };
    bool whiteTurn() {return currentMove % 2 != 0; };
    void display(Position posHover, Position PosSel);

    Piece get(Position pos);
    void reset();
    void move( Move move);
    void assign(Piece piece);

private:

    // Attributes
    Piece board[64];
    int currentMove;

    // Methods
    void swap(const Position& pos1, const Position& pos2);
};


#endif //CHESS_BOARD_H
