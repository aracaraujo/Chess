//
// Created by Ara Cantanhede Araujo on 2/1/24.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "piece.h"


class Pawn : public Piece {

public:
    Pawn() : Piece(){};

    Pawn(int row, int col, bool white) : Piece(row, col, white){};

private:
    Position position;
    bool fWhite;

};


#endif //CHESS_PAWN_H
