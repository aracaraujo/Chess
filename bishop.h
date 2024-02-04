//
// Created by Ara Cantanhede Araujo on 2/1/24.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H
#include "piece.h"

class Bishop : public Piece{

public:
    Bishop() : Piece(){};

    Bishop(int loc,bool white) : Piece(loc, white){
        this->letter = 'b';
    }

    Bishop(int row, int col, bool white) : Piece(row, col, white){
        this->letter = 'b';
    };

    char getLetter() override { return letter; };

private:
    char letter;
};


#endif //CHESS_BISHOP_H
