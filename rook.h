//
// Created by Ara Cantanhede Araujo on 2/1/24.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H
#include "piece.h"

class Rook : public Piece{

public:
    Rook() : position(Position(0,0)), fWhite(true){};

    Rook(int row, int col, bool white) : position(Position(row,col)), fWhite(white){};

private:
    Position position;
    bool fWhite;
    int nMoves;
    int lastMove;

};


#endif //CHESS_ROOK_H
