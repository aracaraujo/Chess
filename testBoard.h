//
// Created by Ara Cantanhede Araujo on 1/27/24.
//

#ifndef CHESS_TESTBOARD_H
#define CHESS_TESTBOARD_H

#pragma once

class TestBoard {

public:

    void run() const
    {
        // Constructor
        constructor();

        // getCurrent
        getCurrent_initial_value();
        getCurrent_mid_game_value();

        // whiteTurn
        whiteTurn_true();
        whiteTurn_false();

        // get
        get_king_position();
        get_space_position();

        // reset
        reset_simple();

        // move
        move_simple();
        move_enpassant();
        move_castleKing();
        move_castleQueen();

        // Assign
        assign_simple();

        // Swap
        swap_simple();
    }

private:

    void constructor() const;

    void getCurrent_initial_value() const;
    void getCurrent_mid_game_value() const;

    void whiteTurn_true() const;
    void whiteTurn_false() const;

    void get_king_position() const;
    void get_space_position() const;

    void reset_simple() const;

    void move_simple() const;
    void move_enpassant() const;
    void move_castleKing() const;
    void move_castleQueen() const;

    void assign_simple() const;

    void swap_simple() const;
};


#endif //CHESS_TESTBOARD_H
