//
// Created by Wade Withers on 1/27/24.
//

#include "piece.h"
#include "board.h"

void Piece::getMovesSlide(set <Move> & moves, const Board &board, const Delta * deltas, int numDelta) const {

    for (int i = 0; i < numDelta; i++)
    {
        Position posMove(position, deltas[i]);

        // slide through the blank spaces
        for (;
                posMove.isValid() && board[posMove] == SPACE;
                posMove += deltas[i])
        {
            Move move;
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());
            moves.insert(move);
        }

        // capture if there is a piece at the end of the slide
        if (posMove.isValid() && board[posMove].isWhite() != fWhite && board[posMove] != SPACE)
        {
            Move move;
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());
            move.setCapture(static_cast<PieceType>(board[posMove].getLetter()));
            moves.insert(move);
        }
    }
}

void Piece::getMovesNoSlide(set <Move> & moves, const Board &board, const Delta * deltas, int numDelta) const{

    for (int i = 0; i <numDelta; i++)
    {
        Position posMove(position,deltas[i]);
        // capture if there is a piece at the end of the slide
        if (posMove.isValid() &&
            (board[posMove].isWhite() != fWhite || board[posMove] == SPACE))
        {
            Move move;
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());
            if (board[posMove] != SPACE)
                move.setCapture(static_cast<PieceType>(board[posMove].getLetter()));
            moves.insert(move);
        }
    }
}


void Pawn::addPromotion(set<Move> &moves, Move &move) const {
    move.setPromote(QUEEN);
    moves.insert(move);
}

void Pawn::getMoves(set<Move> &moves, const Board &board) const {

    {
        Position posMove(getPosition(), isWhite() ? ADD_R : SUB_R);

        if (posMove.isValid() && board[posMove] == SPACE)
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

    if(!isMoved())
    {
        Position posMove(isWhite() ? 3 : 4 , getPosition().getCol());
        Position posCheck(isWhite() ? 2 : 5 , getPosition().getCol());

        if (board[posMove] == ' ' && board[posCheck] == ' ')
        {
            Move move;
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());
            moves.insert(move);
        }
    }

    // Pawn can attack if enemy to right, not at back rank or not on right most column.
    const int cDelta[] = { 1, -1 };
    for (int i = 0; i < 2; i++)
    {
        Position posMove(position.getRow() + (isWhite() ? 1 : -1), position.getCol() + cDelta[i]);

        if (posMove.isValid() && board[posMove] != SPACE && board[posMove].isWhite() != isWhite())
        {
            Move move;
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());
            move.setCapture(static_cast<PieceType>(board[posMove].getLetter()));

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
            move.setCapture(static_cast<PieceType>(board[posMove].getLetter()));
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

    getMovesNoSlide(moves,board,deltas,8);

    // Castle king side
    if (!isMoved())
    {
        Position posSpace(position.getRow(),5);
        Position posMove(position.getRow(),6);
        Position posRook(position.getRow(),7);

        if (board[posMove] == SPACE &&
            board[posSpace] == SPACE &&
            board[posRook] == ROOK &&
            board[posRook].isMoved() == false)
        {
            Move move;
            move.setSrc(getPosition());
            move.setDes(posMove);
            move.setWhiteMove(isWhite());
            move.setCastle(true);
            moves.insert(move);
        }
    }
    // Castle queen side
    if (!isMoved())
    {
        Position posSpace1(position.getRow(),3);
        Position posMove(position.getRow(),2);
        Position posSpace2(position.getRow(),1);
        Position posRook(position.getRow(),0);

        if (board[posMove] == SPACE &&
            board[posSpace1] == SPACE &&
            board[posSpace2] == SPACE &&
            board[posRook] == ROOK &&
            board[posRook].isMoved() == false)
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
    const Delta deltas[] =
            {
                    {-1,1}, {1,1},
                    {-1,-1}, {1,-1}
            };
    getMovesSlide(moves,board,deltas,4);
}

void Knight::getMoves(set<Move> &moves, const Board &board) const {
    const Delta deltas[] =
            {
                    {-1,2},{1,2},
                    {-2,1},{2,1},
                    {-2,-1},{2,-1},
                    {-1,-2},{1,-2}
            };

    getMovesNoSlide(moves,board,deltas,8);
}

void Queen::getMoves(set<Move> &moves, const Board &board) const {
    const Delta deltas[] =
            {
                    {-1,1},{0,1},{1,1},
                    {-1,0},{1,0},
                    {-1,-1},{0,-1},{1,-1}
            };

    getMovesSlide(moves,board,deltas,8);
}

void Rook::getMoves(set<Move> &moves, const Board &board) const {
    const Delta deltas[] =
            {
                    {0,1},
                    {-1,0},{1,0},
                    {0,-1}
            };
    getMovesSlide(moves,board,deltas,4);
}
