//
// Created by Ara Cantanhede Araujo on 2/1/24.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "piece.h"

class Knight : public Piece{

public:
    Knight() : Piece(){};

    Knight(int loc,bool white) : Piece(loc, white){
        this->letter = 'n';
    }

    Knight(int row, int col, bool white) : Piece(row, col, white){
        this->letter = 'n';
    };

    char getLetter() override { return letter; };

private:
    char letter;
};


#endif //CHESS_KNIGHT_H
