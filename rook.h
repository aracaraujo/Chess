//
// Created by Ara Cantanhede Araujo on 2/1/24.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "piece.h"

class Rook : public Piece{

public:
    Rook();

    Rook(int loc,bool white) : Piece(loc, white){
        this->letter = 'r';
    }

    Rook(int row, int col, bool white) : Piece(row,col,white){
        this->letter = 'r';
    };

    char getLetter() override { return letter; };

private:
    char letter;
};


#endif //CHESS_ROOK_H
