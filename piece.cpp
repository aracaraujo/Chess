//
// Created by Wade Withers on 1/27/24.
//

#include "piece.h"

Piece::Piece() {

}

Piece::Piece(int row, int col, bool white) {

}

void Piece::assign() {

}

bool Piece::isWhite() {
    return false;
}

bool Piece::isMove() {
    return false;
}

int Piece::getNumMoves() {
    return nMoves;
}

Position Piece::getPosition() {
    return Position();
}

char Piece::getLetter() {
    return 0;
}

void Piece::assignPiece(Piece piece) {

}

void Piece::display(ogstream gout) {

}

Move Piece::getMoves() {
    return Move();
}

bool Piece::justMoved() {
    return false;
}

void Piece::incrementNumMoves() {
    nMoves += 1;
}

