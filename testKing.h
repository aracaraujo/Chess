//
// Created by Wade Withers on 1/27/24.
//

#ifndef CHESS_TESTKING_H
#define CHESS_TESTKING_H

#include "king.h"

class TestKing {
public:
    void run();
private:
    // Test isWhite for white piece.
    void testGetLetterWhite();
    void testGetLetterBlack();
    void testCanCastleYes();
    void testCanCastleNo();

    struct RC
    {
        int row;
        int col;
    };
/*    RC moves[8] =
            {
                    {-1,  1}, {0,  1}, {1,  1},
                    {-1,  0},          {1,  0},
                    {-1, -1}, {0, -1}, {1, -1}
            };
*/

};


#endif //CHESS_TESTKING_H
