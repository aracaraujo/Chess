//
// Created by Wade Withers on 1/27/24.
//

#include "testKing.h"
#include "piece.h"
#include <iostream>
#include <cassert>

void TestKing::run() {
    testGetLetterWhite();
    testGetLetterBlack();
    testCanCastleYes();
    testCanCastleNo();
}

void TestKing::testGetLetterWhite() {
    //Setup
    King king;
    king.letter = 'k';

    //Exercise

    //Validate
    assert(king.getLetter() == 'k');

    //Clean up

}

void TestKing::testGetLetterBlack() {
    //Setup
    King king;
    king.letter = 'K';

    //Exercise

    //Validate
    assert(king.getLetter() == 'K');

    //Clean up
}

void TestKing::testCanCastleYes() {
    //Setup
    King king;

    //Exercise

    //Validate
    assert(king.getNumMoves() == 0);
    assert(king.canCastle() == true);

    //Clean up
}

void TestKing::testCanCastleNo() {
    //Setup
    King king;

    //Exercise
    king.incrementNumMoves();

    //Validate
    assert(king.getNumMoves() != 0);
    assert(king.canCastle() == false);

    //Clean up
}


