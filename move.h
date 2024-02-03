//
// Created by Ara Cantanhede Araujo on 1/26/24.
//

#ifndef CHESS_MOVE_H
#define CHESS_MOVE_H
#pragma once
#include <string>
#include "position.h"
#include "testMove.h"

using std::string;

class Move {
    friend MoveTest;
public:

    // constructors
    Move() : source(Position()), dest(Position()) {}
    Move(string position) : source(Position()), dest(Position()) {};

    // Assign
    void read(string input);
    Move& operator=(string position);

    //Getters
    string getText() {return "stub";}
    Position getSrc() { return source; };
    Position getDes() { return dest; };

    // Letter from piece type
    char letterFromPieceType(PieceType input);
    PieceType pieceTypeFromLetter(char input);

private:
    Position source;
    Position dest;
    PieceType promote;
    bool isWhite;
    string error;
    PieceType capture;
    bool enpassant;
    bool castleK;
    bool castleQ;

};


#endif //CHESS_MOVE_H
