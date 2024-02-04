//
// Created by Wade Withers on 1/27/24.
//

#include "piece.h"

Piece::Piece() {

}

Piece::Piece(int loc, bool white){
    position = Position(loc);
    fWhite = white;
    nMoves = 0;
}

Piece::Piece(int row, int col, bool white) {
    position = Position(row,col);
    fWhite = white;
    nMoves = 0;
}

void Piece::assign() {
}

bool Piece::isWhite() {
    return fWhite;
}

bool Piece::isMove() {
    return false;
}

int Piece::getNumMoves() {
    return nMoves;
}

Position Piece::getPosition() {
    return position;
}

char Piece::getLetter() {
    return letter;
}

void Piece::assignPiece(Piece piece) {

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

