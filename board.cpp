//
// Created by Ara Cantanhede Araujo on 1/26/24.
//

#include "board.h"
#include "piece.h"
#include "uiDraw.h"
#include "cassert"

Board::Board(ogstream* pgout) {

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
    this->pgout = pgout;
}

void Board::display(const Position& posHover, const Position& posSel) { // added possible as parameter

    // draw the checkerboard
    pgout->drawBoard();

    // draw any selections
    pgout->drawHover(posHover.getLocation());
    pgout->drawSelected(posSel.getLocation());

    // draw the possible moves
    if (posSel.isValid())
    {
        set <Move> possible;
        board[posSel.getRow()][posSel.getCol()]->getMoves(possible,*this);
        set<Move>::iterator it;
        for (it = possible.begin(); it != possible.end(); it++)
            pgout->drawPossible(it->getDes().getLocation());
    }

    for (int r = 0; r < 8; r++) {
        for (int c = 0; c < 8; c++) {
            board[r][c]->display(pgout);
        }
    }

}

void Board::reset() {

    this->currentMove = 1;
}

void Board::remove(const Position &pos) {
    if (pos.isInvalid()){
        return;
    }
    delete board[pos.getRow()][pos.getCol()];
    board[pos.getRow()][pos.getCol()] = NULL;
}

void Board::operator-=(const Position &pos) {
    if (pos.isInvalid())
        return;
    delete board[pos.getRow()][pos.getCol()];
    board[pos.getRow()][pos.getCol()] = new Space(pos.getRow(),pos.getCol());
}

const Piece * Board::operator=(Piece* pRhs) {
    delete board[pRhs->getPosition().getRow()][pRhs->getPosition().getCol()];
    board[pRhs->getPosition().getRow()][pRhs->getPosition().getCol()] = pRhs;
    return pRhs;
}


void Board::move(const Move& move) {
    Position src = move.getSrc();
    Position des = move.getDes();

    if(move.getCastleK())
    {
        int row = (move.getWhiteMove() ? 0 : 7);

        // Move king
        src.set(row,6);
        des.set(row,4);
        swap(src,des);

        // Move rook
        src.set(row,5);
        des.set(row,7);
        swap(src,des);
    }
        // Castle Queen side
    else if (move.getCastleQ())
    {
        int row = (move.getWhiteMove() ? 0 : 7);

        // Move king
        src.set(row,2);
        des.set(row,4);
        swap(src,des);

        // Move rook
        src.set(row,3);
        des.set(row,0);
        swap(src,des);
    }
        // en-passant
    else if (move.getEnPassant())
    {
        // move the pawn
        swap(src,des);

        // kill oponent
        Position  posKill(src.getRow(),des.getCol());
        *this -= posKill;
    }

        // promotion
    else if (move.getPromotion() != PIECE_EMPTY)
    {
        *this -= src;
        remove(des);

        switch (move.getPromotion()) {
            case QUEEN:
                *this = new Queen(des.getRow(),des.getCol(),move.getWhiteMove());
                break;
            case ROOK:
                *this = new Rook(des.getRow(),des.getCol(),move.getWhiteMove());
                break;
            case BISHOP:
                *this = new Bishop(des.getRow(),des.getCol(),move.getWhiteMove());
                break;
            case KNIGHT:
                *this = new Knight(des.getRow(),des.getCol(),move.getWhiteMove());
                break;
            default:
                *this = new Pawn(des.getRow(),des.getCol(),move.getWhiteMove());
                break;
        }
    }
        // capture?
    else if (move.getCapture() != PIECE_EMPTY)
    {
        *this -= des;

        swap(src,des);
    }

        // normal piece move
    else{
        swap(src,des);
    }

    currentMove++;
}

void Board::swap(Position &pos1,Position &pos2) {

    assert(pos1.isValid());
    assert(pos2.isValid());

    Piece *p = board[pos1.getRow()][pos2.getCol()];
    board[pos1.getRow()][pos2.getCol()] = board[pos2.getRow()][pos2.getCol()];
    board[pos2.getRow()][pos2.getCol()] = p;

    (*this)[pos1] = pos1;
    (*this)[pos2] = pos2;

    (*this)[pos1].setLastMove(currentMove);
    (*this)[pos2].setLastMove(currentMove);

}

