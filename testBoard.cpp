//
// Created by Ara Cantanhede Araujo on 1/27/24.
//

#include "testBoard.h"
#include "uiDraw.h"
#include "pieceType.h"
#include <cassert>
#include "board.h"
#include "rook.h"
#include "knight.h"
#include "bishop.h"
#include "queen.h"
#include "king.h"
#include "pawn.h"
#include "space.h"
#include "piece.h"

void TestBoard::constructor() const {

    // SETUP
    Piece board_array[64] = {
            Rook(8,1,false), Knight(8,2,false), Bishop(8,3,false), Queen(8,4, false), King(8,5,false), Bishop(8,6,false),
            Knight(8,7, false), Rook(8,8, false),
            Pawn(7,1,false), Pawn(7,2,false), Pawn(7,3,false), Pawn(7,4,false), Pawn(7,5,false), Pawn(7,6,false), Pawn(7,7,false), Pawn(7,8,false),
            Space(6,1), Space(6,2), Space(6,3), Space(6,4), Space(6,5), Space(6,6), Space(6,7), Space(6,8),
            Space(5,1), Space(5,2), Space(5,3), Space(5,4), Space(5,5), Space(5,6), Space(5,7), Space(5,8),
            Space(4,1), Space(4,2), Space(4,3), Space(4,4), Space(4,5), Space(4,6), Space(4,7), Space(4,8),
            Space(3,1), Space(3,2), Space(3,3), Space(3,4), Space(3,5), Space(3,6), Space(3,7), Space(3,8),
            Pawn(2,1,true), Pawn(2,2,true), Pawn(2,3,true), Pawn(2,4,true), Pawn(2,5,true), Pawn(2,6,true), Pawn(2,7,true), Pawn(2,8,true),
            Rook(1,1,true), Knight(1,2,true), Bishop(1,3,true), Queen(1,4,true), King(1,5,true), Bishop(1,6,true),
            Knight(1,7,true), Rook(1,8,true)
    };
    // EXERCISE
    Board board = Board();
    //VERIFY
    assert(board.board == board_array);
    assert(board.currentMove == 1);
}

void TestBoard::getCurrent_initial_value() const {
    // SETUP
    // EXERCISE
    Board board = Board();
    // VERIFY
    assert(board.getCurentMove() == 1);
}

void TestBoard::getCurrent_mid_game_value() const {
    // SETUP
    Board board = Board();
    Move move1;
    Move move2;
    // EXERCISE
    board.move(move1);
    board.move(move2);
    // VERIFY
    assert(board.getCurentMove() == 3);
}

void TestBoard::whiteTurn_true() const {
    // SETUP
    // EXERCISE
    Board board = Board();
    // VERIFY
    assert(board.whiteTurn() == true);
}

void TestBoard::whiteTurn_false() const {
    // SETUP
    Board board = Board();
    Move move1;
    // EXERCISE
    board.move(move1);
    // VERIFY
    assert(board.whiteTurn() == false);
}

void TestBoard::get_king_position() const {
    // SETUP
    Board board = Board();
    // EXERCISE
    auto king = board.get(Position(1,4));
    // VERIFY
    assert(king.getLetter() == 'r');
}

void TestBoard::get_space_position() const {
    // SETUP
    Board board = Board();
    // EXERCISE
    auto space = board.get(Position(4,4));
    // VERIFY
    assert(space.getLetter() == ' ');
}

void TestBoard::reset_simple() const {
    // SETUP
    Board board = Board();
    Piece new_board[64] = {
            Rook(8,1,false), Knight(8,2,false), Bishop(8,3,false), Queen(8,4, false), King(8,5,false), Bishop(8,6,false),
            Knight(8,7, false), Rook(8,8, false),
            Pawn(7,1,false), Pawn(7,2,false), Pawn(7,3,false), Pawn(7,4,false), Pawn(7,5,false), Pawn(7,6,false), Pawn(7,7,false), Pawn(7,8,false),
            Space(6,1), Space(6,2), Space(6,3), Space(6,4), Space(6,5), Space(6,6), Space(6,7), Space(6,8),
            Space(5,1), Space(5,2), Space(5,3), Space(5,4), Space(5,5), Space(5,6), Space(5,7), Space(5,8),
            Space(4,1), Space(4,2), Space(4,3), Space(4,4), Space(4,5), Space(4,6), Space(4,7), Space(4,8),
            Space(3,1), Space(3,2), Space(3,3), Space(3,4), Space(3,5), Space(3,6), Space(3,7), Space(3,8),
            Pawn(2,1,true), Pawn(2,2,true), Pawn(2,3,true), Pawn(2,4,true), Pawn(2,5,true), Pawn(2,6,true), Pawn(2,7,true), Pawn(2,8,true),
            Rook(1,1,true), Knight(1,2,true), Bishop(1,3,true), Queen(1,4,true), King(1,5,true), Bishop(1,6,true),
            Knight(1,7,true), Rook(1,8,true)
    };

    board.board[8] = Space(7,1);
    board.board[11] = Space(7,4);
    board.board[24] = Pawn(5,1,false);
    board.board[27] = Pawn(5,4,false);
    board.board[40] = Knight(3,1,true);
    board.board[40] = Space(1,2);

    // EXERCISE
    board.reset();
    // VERIFY
    assert(board.board == new_board);
}

void TestBoard::move_simple() const {
    // SETUP
    Board board = Board();
    Move move("e2e3");
    // EXERCISE
    board.move(move);
    // VERIFY
    assert(board.get(Position(2,4)).getLetter() == ' ');
    assert(board.get(Position(3,4)).getLetter() == 'p');
}

void TestBoard::move_enpassant() const {
    // SETUP
    Board board = Board();
    PieceType enpassant_board[64] = {
            ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK,
            PAWN, SPACE, PAWN, SPACE, PAWN, PAWN, PAWN, PAWN,
            SPACE, SPACE, SPACE, PAWN, SPACE, SPACE, SPACE, SPACE,
            PAWN, PAWN, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            SPACE, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
            ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK
    };
    board.board = enpassant_board;
    board.board[48] = Space(2,1);

    Move move("a5b6");
    // EXERCISE
    board.move(move);
    // VERIFY
    assert(board.get(Position(1,5)) == SPACE);
    assert(board.get(Position(2,6)) == PAWN);
    assert(board.get(Position(2,5)) == SPACE);
}

void TestBoard::move_castleKing() const {
    // SETUP
    Board board;
    PieceType castle_king_board[64] = {
            ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK,
            PAWN, SPACE, PAWN, SPACE, PAWN, PAWN, PAWN, PAWN,
            SPACE, SPACE, SPACE, PAWN, SPACE, SPACE, SPACE, SPACE,
            PAWN, PAWN, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, PAWN, KNIGHT,
            SPACE, PAWN, PAWN, PAWN, PAWN, PAWN, BISHOP, PAWN,
            ROOK, KNIGHT, BISHOP, QUEEN, KING, SPACE, SPACE, ROOK
    };
    board.board = castle_king_board;
    Move move("e1g1");
    // EXERCISE
    board.move(move);
    // VERIFY
    assert(board.get(Position(1,5)) == SPACE);
    assert(board.get(Position(1,7)) == KING);
    assert(board.get(Position(1,8)) == SPACE);
    assert(board.get(Position(1,6)) == ROOK);
}

void TestBoard::move_castleQueen() const {
    // SETUP
    Board board;
    PieceType castle_queen_board[64] = {
            ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK,
            PAWN, SPACE, PAWN, SPACE, PAWN, PAWN, PAWN, PAWN,
            SPACE, SPACE, SPACE, PAWN, SPACE, SPACE, SPACE, SPACE,
            PAWN, PAWN, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            KNIGHT, PAWN, SPACE, PAWN, SPACE, SPACE, SPACE, SPACE,
            SPACE, BISHOP, PAWN, QUEEN, PAWN, PAWN, PAWN, PAWN,
            ROOK, SPACE, SPACE, SPACE, KING, BISHOP, KNIGHT, ROOK
    };
    board.board = castle_queen_board;
    Move move("e1c1");
    // EXERCISE
    board.move(move);
    // VERIFY
    assert(board.get(Position(1,5)) == SPACE);
    assert(board.get(Position(1,3)) == KING);
    assert(board.get(Position(1,1)) == SPACE);
    assert(board.get(Position(1,4)) == ROOK);
}

void TestBoard::assign_simple() const {
}

void TestBoard::swap_simple() const {
    // SETUP
    Board board;
    // EXERCISE
    board.swap(Position(2,1),Position(3,1));
    // VERIFY
    assert(board.get(Position(2,1)) == SPACE);
    assert(board.get(Position(3,1)) == PAWN);
}




