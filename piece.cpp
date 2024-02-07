//
// Created by Wade Withers on 1/27/24.
//

#include "piece.h"

void Pawn::addPromotion(set<Move> &moves, Move &move) const {
    move.setPromote(QUEEN);
    moves.insert(move);
}

void Pawn::getMoves(set<Move> &moves, const Board &board) const {

}

void King::getMoves(set<Move> &moves, const Board &board) const {

}

void Bishop::getMoves(set<Move> &moves, const Board &board) const {

}

void Knight::getMoves(set<Move> &moves, const Board &board) const {

}

void Queen::getMoves(set<Move> &moves, const Board &board) const {

}

void Rook::getMoves(set<Move> &moves, const Board &board) const {

}
