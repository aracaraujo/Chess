//
// Created by Ara Cantanhede Araujo on 1/26/24.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "uiDraw.h"
#include "position.h"
#include "move.h"
#include "testBoard.h"


class Board {
    friend TestBoard;
public:

    Board() : board({}), currentMove(1) {};

    int getCurentMove() { return 0; };
    bool whiteTurn() {return true; };
    void display(Position posHover, Position PosSel);

    Piece get(Position pos);
    void reset();
    void move( Move move);
    void assign(Piece piece);

private:

    // Attributes
    Piece board[64];
    int currentMove;
    ogstream gout;

    // Methods
    void swap(Position pos1, Position pos2);
};


#endif //CHESS_BOARD_H
