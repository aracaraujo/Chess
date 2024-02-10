//
// Created by Ara Cantanhede Araujo on 1/26/24.
//

#include "board.h"
#include "piece.h"
#include "uiDraw.h"

Board::Board() {

    // Filling the spaces in the middle of the board.
    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            board[r][c] = new Space(r,c);
        }
    }

    // White pawns.
    for (int c = 0; c < 8; c++) {
        board[1][c] = new Pawn(1,c,true);
    }
    // White pieces.
    board[0][0] = new Rook(0,0,true);
    board[0][1] = new Knight(0,1,true);
    board[0][2] = new Bishop(0,2,true);
    board[0][3] = new Queen(0,3,true);
    board[0][4] = new King(0,4,true);
    board[0][5] = new Bishop(0,5,true);
    board[0][6] = new Knight(0,6,true);
    board[0][7] = new Rook(0,7,true);

    // Black pawns.
    for (int c = 0; c < 8; c++) {
        board[6][c] = new Pawn(6,c,false);
    }
    // Black pieces.
    board[7][0] = new Rook(7,0,false);
    board[7][1] = new Knight(7,1,false);
    board[7][2] = new Bishop(7,2,false);
    board[7][3] = new Queen(7,3,false);
    board[7][4] = new King(7,4,false);
    board[7][5] = new Bishop(7,5,false);
    board[7][6] = new Knight(7,6,false);
    board[7][7] = new Rook(7,7,false);

    this->currentMove = 1;
}

void Board::display(Position posHover, Position PosSel) {

    ogstream gout;
    // draw the checkerboard
    gout.drawBoard();

    // draw any selections
    gout.drawHover(posHover.getLocation());
    gout.drawSelected(PosSel.getLocation());

    // draw the possible moves
//    set <int> :: iterator it;
//    for (it = possible.begin(); it != possible.end(); ++it)
//        gout.drawPossible(*it);

    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            board[r][c]->display(&gout);
        }
    }

}

void Board::reset() {

    this->currentMove = 1;
}

Piece *Board::operator[](Position &pos) const {
    return board[pos.getRow()][pos.getCol()];
}

Piece *Board::operator[](Position &pos){
    return board[pos.getRow()][pos.getCol()];
}

void Board::move(Move move) {
    std::swap(board[move.getSrc().getRow()][move.getSrc().getCol()], board[move.getDes().getRow()][move.getDes().getCol()]);

}

