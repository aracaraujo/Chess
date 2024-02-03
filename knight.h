//
// Created by Ara Cantanhede Araujo on 2/1/24.
//

#ifndef CHESS_KNIGHT_H
#define CHESS_KNIGHT_H
#include "piece.h"

class Knight : public Piece{

public:
    Knight() : Piece(){};

    Knight(int row, int col, bool white) : Piece(row, col, white){};

private:
    Position position;
    bool fWhite;
};


#endif //CHESS_KNIGHT_H
