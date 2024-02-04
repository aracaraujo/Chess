//
// Created by Ara Cantanhede Araujo on 2/1/24.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "piece.h"

class Queen : public Piece{

public:
    Queen() : Piece(){};

    Queen(int loc,bool white) : Piece(loc, white){
        this->letter = 'q';
    }

    Queen(int row, int col, bool white) : Piece(row, col, white){
        this->letter = 'q';
    };

    char getLetter() override { return letter; };

private:
    char letter;
};


#endif //CHESS_QUEEN_H
