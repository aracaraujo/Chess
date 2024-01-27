//
// Created by Wade Withers on 1/27/24.
//

#include "king.h"

King::King() {

}

King::King(int row, int col, bool white) : Piece(row, col, white) {

}

bool King::canCastle() {
    return false;
}

char King::getLetter() {
    return 'x';
}

void King::display() {

    Piece::display();
}

Move King::getMoves() {
    return Piece::getMoves();
}

