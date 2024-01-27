//
// Created by Wade Withers on 1/27/24.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include <list>
#include "piece.h"
#include "move.h"


class King : protected Piece{
public:
    // Default Constructor
    King();

    // Non-Default Constructor.
    King(Piece type);

    // Add distance of move to moves list.
    void addMove(int move);

    // Get the distance for the last move in moves list.
    int getLastMove();

    // Returns the length of moves list.
    int getNumOfMoves();

    // Checks if king has moved already.
    bool canCastle();

private:
    //List to store distance of each move.
    std::list<int> moves;
};


#endif //CHESS_KING_H
