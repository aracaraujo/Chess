//
// Created by Wade Withers on 1/27/24.
//

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

#include "position.h"
#include "uiDraw.h"
#include "move.h"
#include <set>

using namespace std;

class Piece {
public:
    // Default Constructor
    // Non-Default Constructor
    Piece(int row, int col, bool isWhite = true) : fWhite(isWhite), nMoves(0), position(row,col), lastMove(-1){};

    Piece(const Piece & piece) {*this = piece; }

    virtual ~Piece() {};

    const Piece & operator = (const Piece& rhs) {
        position = rhs.getPosition();
        return *this;
    };

    const Piece & operator = (const Position& rhs)
    {
        nMoves++;
        position = rhs;
        return *this;
    }

    // Getters.

    bool operator == (char letter) const { return getLetter() == letter; };
    bool operator != (char letter) const { return getLetter() != letter; };
    bool isWhite()                 const { return fWhite; };
    bool isMoved()                const {return getNMoves() != 0; };
    int  getNMoves()               const { return nMoves; };
    const Position & getPosition()       const { return position; };
    bool justMoved(int currentMove) const
    {
        return (currentMove - 1 == lastMove);
    }

    // Setters
    void setLastMove(int currentMove) { lastMove = currentMove; };

    // virtual
    virtual char getLetter()                                      const = 0;
    virtual void display(ogstream * pgout)                        const = 0;
    virtual void getMoves(set<Move> & moves, const Board & board) const = 0;

protected:
    void getMovesSlide( set <Move> & moves,
                              const Board & board,
                              const Delta * deltas,
                              int numDelta) const;

    void getMovesNoSlide( set <Move> & moves,
                        const Board & board,
                        const Delta * deltas,
                        int numDelta) const;


    Position position;
    bool fWhite;
    int nMoves;
    int lastMove;
};

/***************************************************
 * PAWN
 ***************************************************/
class Pawn : public Piece {
public:

    Pawn(int row, int col, bool white) : Piece(row, col, white){};

    char getLetter() const override { return 'p'; };
    void getMoves(set<Move> & moves, const Board & board) const override;
    virtual void display(ogstream* pgout) const override
    {
        pgout->drawPawn(position.getLocation(),!isWhite());
    }

private:
    void addPromotion(set<Move> & moves, Move & move) const;
};

/***************************************************
 * KING
 ***************************************************/
class King : public Piece{
public:
    // Non-Default Constructor.
    King(int row, int col, bool white) : Piece(row, col, white) {};

    // Checks if king has moved already.
    bool canCastle() { return getNMoves() == 0; };

    char getLetter() const override { return 'k'; };

    void display(ogstream * pgout) const override {
        pgout->drawKing(position.getLocation(),!isWhite());
    };

    void getMoves(set<Move> & moves, const Board & board) const override;
private:
};

/***************************************************
 * BISHOP
 ***************************************************/
class Bishop : public Piece{
public:

    Bishop(int row, int col, bool white) : Piece(row, col, white){};

    char getLetter() const override { return 'b'; };

    void display(ogstream * pgout) const override {
        pgout->drawBishop(position.getLocation(),!isWhite());
    };

    void getMoves(set<Move> & moves, const Board & board) const override;

private:

};

/***************************************************
 * KNIGHT
 ***************************************************/
class Knight : public Piece{
public:

    Knight(int row, int col, bool white) : Piece(row, col, white){};

    char getLetter() const override { return 'n'; };

    virtual void display(ogstream* pgout) const override
    {
        pgout->drawKnight(position.getLocation(),!isWhite());
    }

    void getMoves(set<Move> & moves, const Board & board) const override;

private:

};

/***************************************************
 * QUEEN
 ***************************************************/
class Queen : public Piece{
public:
    Queen(int row, int col, bool white) : Piece(row, col, white){};

    char getLetter() const override { return 'q'; };
    void getMoves(set<Move> & moves, const Board & board) const override;
    virtual void display(ogstream* pgout) const override
    {
        pgout->drawQueen(position.getLocation(),!isWhite());
    }
private:
};

/***************************************************
 * ROOK
 ***************************************************/
class Rook : public Piece{
public:

    Rook(int row, int col, bool white) : Piece(row,col,white){};

    char getLetter() const override { return 'r'; };
    void getMoves(set<Move> & moves, const Board & board) const override;
    virtual void display(ogstream* pgout) const override
    {
        pgout->drawRook(position.getLocation(),!isWhite());
    }
private:
};

/***************************************************
 * SPACE
 ***************************************************/
class Space : public Piece {
public:
    Space(int row, int col) : Piece(row,col){};

    virtual char getLetter() const override { return ' '; };
    virtual void getMoves(set<Move> & moves, const Board & board) const override{};
    virtual void display(ogstream* pgout) const {};

private:
};


#endif //CHESS_PIECE_H
