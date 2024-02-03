//
// Created by Wade Withers on 1/27/24.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "position.h"
#include "uiDraw.h"
#include "move.h"

class Piece {
public:
    // Default Constructor
    Piece();

    // Non-Default Constructor
    Piece(int row, int col, bool white);

    // Move piece to new position.
    void assign();

    // Change pawn to queen
    void assignPiece(Piece piece);

    //Get color of piece.
    bool isWhite();

    // Check if colors turn.
    bool isMove();

    // Getters.
    int getNumMoves();
    Position getPosition();

    bool justMoved();

    virtual char getLetter();

    virtual void display(ogstream gout);

    virtual Move getMoves();

    // Set number of moves.
    void incrementNumMoves();




private:
    Position position;
    bool fWhite;
    int nMoves;
    int lastMove;
    ogstream gout;

};


#endif //CHESS_PIECE_H
