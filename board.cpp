//
// Created by Ara Cantanhede Araujo on 1/26/24.
//

#include "board.h"

Board::Board() {
    board = {
            ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK,
            PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
            ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK
    };
}

void Board::display(Position posHover, Position PosSel) {}

Piece Board::get(Position pos){

}

void Board::reset() {}

void Board::move(Move move) {}

void Board::assign(Piece piece) {}

void Board::swap(Position pos1, Position pos2) {}


