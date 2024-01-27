//
// Created by Wade Withers on 1/27/24.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "position.h"


class Piece {
public:
    // Default Constructor
    Piece();

    // Non-Default Constructor
    Piece(char type);

    char getType();

    Position getPosition();
protected:
    char type;
    Position pos;

};


#endif //CHESS_PIECE_H
