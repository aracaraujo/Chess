//
// Created by Wade Withers on 1/27/24.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include <list>
#include "piece.h"
#include "move.h"

class TestKing;

class King : public Piece{
public:
    friend TestKing;
    // Default Constructor
    King();

    // Non-Default Constructor.
    King(int row, int col, bool white);

    char getLetter() override;

    void display(ogstream gout) override;

    Move getMoves() override;

    // Checks if king has moved already.
    bool canCastle();

private:
    char letter;
};


#endif //CHESS_KING_H
