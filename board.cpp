//
// Created by Ara Cantanhede Araujo on 1/26/24.
//

#include "board.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "space.h"
#include "piece.h"
#include "uiDraw.h"

Board::Board() {

    // Setting up spaces.
    for (int i = 16; i < 48; ++i) {
        this->board[i] = Space(i); // Assuming Space is a class for an empty space
    }


    // Setting up black pieces
    this->board[0] = Rook(0, false);
    this->board[1] = Knight(1, false);
    this->board[2] = Bishop(2, false);
    this->board[3] = Queen(3, false);
    this->board[4] = King(4, false);
    this->board[5] = Bishop(5, false);
    this->board[6] = Knight(6, false);
    this->board[7] = Rook(7, false);
    for (int i = 8; i < 16; ++i) {
        this->board[i] = Pawn(i,false);
    }


    // Setting up white pieces
    this->board[56] = Rook(56, true);
    this->board[57] = Knight(57, true);
    this->board[58] = Bishop(58, true);
    this->board[59] = Queen(59, true);
    this->board[60] = King(60, true);
    this->board[61] = Bishop(61, true);
    this->board[62] = Knight(62, true);
    this->board[63] = Rook(63, true);
    for (int i = 48; i < 56; ++i) {
        this->board[i] = Pawn(i,true);
    }

    this->currentMove = 1;
}

void Board::display(Position posHover, Position PosSel) {

//    ogstream gout;
//    // draw the checkerboard
//    gout.drawBoard();
//
//    // draw any selections
//    gout.drawHover(posHover.getLocation());
//    gout.drawSelected(PosSel.getLocation());
//
//    // draw the possible moves
//    set <int> :: iterator it;
//    for (it = possible.begin(); it != possible.end(); ++it)
//        gout.drawPossible(*it);
//
//    // draw the pieces
//    for (int i = 0; i < 64; i++)
//        switch (board[i])
//        {
//            case 'P':
//                gout.drawPawn(i, true);
//                break;
//            case 'p':
//                gout.drawPawn(i, false);
//                break;
//            case 'K':
//                gout.drawKing(i, true);
//                break;
//            case 'k':
//                gout.drawKing(i, false);
//                break;
//            case 'Q':
//                gout.drawQueen(i, true);
//                break;
//            case 'q':
//                gout.drawQueen(i, false);
//                break;
//            case 'R':
//                gout.drawRook(i, true);
//                break;
//            case 'r':
//                gout.drawRook(i, false);
//                break;
//            case 'B':
//                gout.drawBishop(i, true);
//                break;
//            case 'b':
//                gout.drawBishop(i, false);
//                break;
//            case 'N':
//                gout.drawKnight(i, true);
//                break;
//            case 'n':
//                gout.drawKnight(i, false);
//                break;
//        }

}

Piece Board::get(Position pos){

    return this->board[pos.getLocation()];

}

void Board::reset() {

    // Setting up spaces.
    for (int i = 16; i < 48; ++i) {
        this->board[i] = Space(i / 8, i % 8); // Assuming Space is a class for an empty space
    }

    // Setting up black pieces
    this->board[0] = Rook(8, 1, false);
    this->board[1] = Knight(8, 2, false);
    this->board[2] = Bishop(8, 3, false);
    this->board[3] = Queen(8, 4, false);
    this->board[4] = King(8, 5, false);
    this->board[5] = Bishop(8, 6, false);
    this->board[6] = Knight(8, 7, false);
    this->board[7] = Rook(8, 8, false);
    for (int i = 8; i < 16; ++i) {
        this->board[i] = Pawn(i / 8, i % 8,false);
    }

    // Setting up white pieces
    this->board[56] = Rook(1, 1, true);
    this->board[57] = Knight(1, 2, true);
    this->board[58] = Bishop(1, 3, true);
    this->board[59] = Queen(1, 4, true);
    this->board[60] = King(1, 5, true);
    this->board[61] = Bishop(1, 6, true);
    this->board[62] = Knight(1, 7, true);
    this->board[63] = Rook(1, 8, true);
    for (int i = 48; i < 56; ++i) {
        this->board[i] = Pawn(i / 8, i % 8,true);
    }

    this->currentMove = 1;
}

void Board::move(Move move) {

    swap(move.getSrc(),move.getDes());

    currentMove++;

}

void Board::assign(Piece piece) {

    this->board[piece.getPosition().getLocation()] = piece;

}

void Board::swap(const Position& pos1, const Position& pos2) {

    Piece piecePlaceHolder = this->board[pos1.getLocation()];

    this->board[pos1.getLocation()] = this->board[pos2.getLocation()];
    this->board[pos2.getLocation()] = piecePlaceHolder;
}