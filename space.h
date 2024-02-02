//
// Created by Ara Cantanhede Araujo on 2/1/24.
//

#ifndef CHESS_SPACE_H
#define CHESS_SPACE_H
#include "piece.h"

class Space : Piece {

public:
    Space() : Piece(){};

    Space(int row, int col, bool white) : Piece(row, col, white){};

private:
    Position position;
    bool fWhite;
};


#endif //CHESS_SPACE_H
