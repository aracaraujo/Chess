//
// Created by Wade Withers on 1/27/24.
//

#include "king.h"

King::King() {
    letter = 'k';
}

King::King(int row, int col, bool white) : Piece(row, col, white) {
    this->letter = 'k';
}

bool King::canCastle() {
    if (King::getNumMoves() == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

Move King::getMoves() {
    return Piece::getMoves();
}


