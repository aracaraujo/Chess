//
// Created by Ara Cantanhede Araujo on 2/1/24.
//

#ifndef CHESS_SPACE_H
#define CHESS_SPACE_H

#include <iostream>
#include "piece.h"

using namespace std;

class Space : public Piece {

public:
    Space(){
        this->letter = ' ';
    };

    Space(int loc) : Piece(loc, true){
        this->letter = ' ';
    }

    Space(int row, int col) : Piece(row,col, true){
        this->letter = ' ';
    };

    char getLetter() override { return letter; };

private:
    char letter;
};


#endif //CHESS_SPACE_H
