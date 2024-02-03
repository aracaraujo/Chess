//
// Created by Wade Withers on 1/27/24.
//

#include "king.h"

King::King() {

}

King::King(int row, int col, bool white) : Piece(row, col, white) {

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

char King::getLetter() {
    return letter;
}

void King::display(ogstream gout) {


}

Move King::getMoves() {
    return Piece::getMoves();
}


