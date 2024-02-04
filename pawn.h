//
// Created by Ara Cantanhede Araujo on 2/1/24.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "piece.h"


class Pawn : public Piece {

public:
    Pawn() : Piece(){};

    Pawn(int loc,bool white) : Piece(loc, white){
        this->letter = 'p';
    }

    Pawn(int row, int col, bool white) : Piece(row, col, white){
        this->letter = 'p';
    };

    char getLetter() override { return this->letter; };

private:
    char letter;
};


#endif //CHESS_PAWN_H
