//
// Created by Ara Cantanhede Araujo on 2/1/24.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "piece.h"

class Rook : public Piece{

public:
    Rook() : Piece(){};

    Rook(int row, int col, bool white) : Piece(row, col, white){};

private:
    Position position;
    bool fWhite;

};


#endif //CHESS_ROOK_H
