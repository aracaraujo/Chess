//
// Created by Ara Cantanhede Araujo on 1/26/24.
//

#ifndef CHESS_BOARD_H
#define CHESS_BOARD_H
#include "uiDraw.h"
#include "position.h"
#include "move.h"
#include "piece.h"


class Board {

public:

    Board();

    int getCurentMove() { return currentMove; };
    bool whiteTurn() {return currentMove % 2 != 0; };
    void display(Position posHover, Position PosSel);
    Piece* (&getBoard())[8][8]
    {
        return board;
    }

    void reset();

//    void assign(Piece piece);
private:

    // Attributes
    Piece * board[8][8];

    int currentMove;

    // Methods

};


#endif //CHESS_BOARD_H
