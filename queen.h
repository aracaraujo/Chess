//
// Created by Ara Cantanhede Araujo on 2/1/24.
//

#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "piece.h"

class Queen : public Piece{

public:
    Queen() : Piece(){};

    Queen(int row, int col, bool white) : Piece(row, col, white){};

private:
    Position position;
    bool fWhite;

};


#endif //CHESS_QUEEN_H
