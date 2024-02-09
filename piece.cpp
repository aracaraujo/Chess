//
// Created by Wade Withers on 1/27/24.
//

#include "piece.h"

void Pawn::addPromotion(set<Move> &moves, Move &move) const {
    move.setPromote(QUEEN);
    moves.insert(move);
}

void Pawn::getMoves(set<Move> &moves, const Board &board) const {
    Position posMove(getPosition(), isWhite() ? ADD_R : SUB_R);
    {
        if (posMove.isValid() && board[posMove] == ' ')
        {
            Move move;
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());

            // Promotion
            if (posMove.getRow() == (isWhite() ? 7 : 0))
            {
                addPromotion(moves, move);
            }
            else
            {
                moves.insert(move);
            }


        }
    }

    // Pawn can attack if enemy to right, not at back rank or not on right most column.
    const int cDelta[] = { 1, -1 };
    for (int i = 0; i < 2; i++)
    {
        Position posMove(position.getRow() + (isWhite() ? 1 : -1), position.getCol() + cDelta[i]);

        if (posMove.isValid() && board[posMove] != ' ' && board[posMove].isWhite() != isWhite())
        {
            Move move;
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());
            move.setCapture(board[posMove].getLetter());

            // Promotion
            if (posMove.getRow() == (isWhite() ? 7 : 0))
            {
                addPromotion(moves, move);
            }
            else
            {
                moves.insert(move);
            }
        }
    }

    // Perform enpassant if on row 4 / 2, enemy pawn to the side,
    // destination spot is empty,
    // pawn to side has only 1 move and has just moved.
    for (int i = 0; i < 2; i++)
    {
        Position posMove(position.getRow() + (isWhite() ? 1 : -1), position.getCol() + cDelta[i]);
        Position posKill(position.getRow(), position.getCol() + cDelta[i]);

        if (posMove.isValid() && position.getRow() == (isWhite() ? 4 : 3) &&
        board[posMove] == ' ' &&
        board[posKill] == 'p' &&
        board[posKill].isWhite() != isWhite() &&
        board[posKill].getNMoves() == 1 &&
        board[posKill].justMoved(board.getCurrentMove()))
        {
            Move move;
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());
            move.setCapture(board[posMove].getLetter());
            move.setEnPassant();
            moves.insert(move);
        }
    }
}

void King::getMoves(set<Move> &moves, const Board &board) const {
    const Delta deltas[] =
            {
                    {-1, 1},  {0, 1},  {1, 1},
                    {-1, 0},                            {1, 0},
                    {-1, -1}, {0, -1}, {1, -1}
            };
    board.getBoard();


    //getMovesNoslide(board, )
    // Move to position if empty or filled by opponent.
    for (int i = 0; i < 8; i++)
    {
        Position posMove(position, deltas[i]);
        if (posMove.isValid() && (board[posMove].isWhite() != fWhite || board[posMove] == SPACE))
        {
            Move move;
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());
            move.setCastle(false);
            moves.insert(move);
        }
    }
}

void Bishop::getMoves(set<Move> &moves, const Board &board) const {

}

void Knight::getMoves(set<Move> &moves, const Board &board) const {

}

void Queen::getMoves(set<Move> &moves, const Board &board) const {

}

void Rook::getMoves(set<Move> &moves, const Board &board) const {

}
