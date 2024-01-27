//
// Created by Ara Cantanhede Araujo on 1/27/24.
//

#include "testBoard.h"
#include "uiDraw.h"
#include "pieceType.h"
#include <cassert>
#include "board.h"

void TestBoard::constructor() const {

    // SETUP
    PieceType board_array[64] = {
            ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK,
            PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
            ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK
    };
    // EXERCISE
    Board board;
    //VERIFY
    assert(board.board == board_array);
    assert(board.currentMove == 1);
}

void TestBoard::getCurrent_initial_value() const {
    // SETUP
    // EXERCISE
    Board board;
    // VERIFY
    assert(board.getCurentMove() == 1);
}

void TestBoard::getCurrent_mid_game_value() const {
    // SETUP
    Board board;
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
    Board board;
    // VERIFY
    assert(board.whiteTurn() == true);
}

void TestBoard::whiteTurn_false() const {
    // SETUP
    Board board;
    Move move1;
    // EXERCISE
    board.move(move1);
    // VERIFY
    assert(board.whiteTurn() == false);
}

void TestBoard::get_king_position() const {
    // SETUP
    Board board;
    // EXERCISE
    PieceType king = board.get(Position(1,4));
    // VERIFY
    assert(king == KING);
}

void TestBoard::get_space_position() const {
    // SETUP
    Board board;
    // EXERCISE
    PieceType space = board.get(Position(4,4));
    // VERIFY
    assert(space == SPACE);
}

void TestBoard::reset_simple() const {
    // SETUP
    Board board;
    PieceType new_board[64] = {
            ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK,
            PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
            ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK
    };
    PieceType mid_game_board[65] = {
            ROOK, KNIGHT, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK,
            SPACE, PAWN, PAWN, SPACE, PAWN, PAWN, PAWN, PAWN,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            PAWN, SPACE, SPACE, PAWN, SPACE, SPACE, SPACE, SPACE,
            SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            KNIGHT, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE, SPACE,
            PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN, PAWN,
            ROOK, SPACE, BISHOP, QUEEN, KING, BISHOP, KNIGHT, ROOK
    };
    board.board = mid_game_board;
    // EXERCISE
    board.reset();
    // VERIFY
    assert(board.board == new_board);
}

void TestBoard::move_simple() const {
    // SETUP
    Board board;
    Move move("e2e3");
    // EXERCISE
    board.move(move);
    // VERIFY
    assert(board.get(Position(2,4)) == SPACE);
    assert(board.get(Position(3,4)) == PAWN);
}

void TestBoard::move_enpassant() const {
    // SETUP
    Board board;
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




