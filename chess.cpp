/**********************************************************************
 * GL Demo
 * Just a simple program to demonstrate how to create an Open GL window, 
 * draw something on the window, and accept simple user input
 **********************************************************************/

#include "uiInteract.h"   // for Interface
#include "uiDraw.h"       // for draw*
#include <set>            // for STD::SET
#include "board.h"
#include "piece.h"
#include "iostream"

using namespace std;

/*************************************
 * All the interesting work happens here, when
 * I get called back from OpenGL to draw a frame.
 * When I am finished drawing, then the graphics
 * engine will wait until the proper amount of
 * time has passed and put the drawing on the screen.
 **************************************/
void callBack(Interface *pUI, void * p)
{

    Board* board = static_cast<Board*>(p);

    if (pUI->getPreviousPosition() == -1 && pUI->getSelectPosition() == -1)
    {
        if (board->operator[](Position(pUI->getSelectPosition())) == ' ')
        {
            pUI->clearSelectPosition();
        }else if (board->operator[](Position(pUI->getSelectPosition())).isWhite() == board->whiteTurn())
            pUI->clearSelectPosition();
    }

    if (pUI->getPreviousPosition() != -1 && pUI->getSelectPosition() != -1) {
        set <Move> possible;
        Move move;
        move.setSrc(Position(pUI->getPreviousPosition()));
        move.setDes(Position(pUI->getSelectPosition()));
        move.complete(*board);

        (*board)[pUI->getPreviousPosition()].getMoves(possible,*board);
        set<Move>::iterator it;
        it = possible.find(move);
        if (it != possible.end())
            board->move(*it);
        pUI->clearSelectPosition();
        pUI->clearPreviousPosition();
    }
    board->display(pUI->getHoverPosition(),pUI->getSelectPosition()); // added possible as argument
}

/*********************************
 * Main is pretty sparse.  Just initialize
 * my Demo type and call the display engine.
 * That is all!
 *********************************/
#ifdef _WIN32
#include <windows.h>
int WINAPI WinMain(
   _In_ HINSTANCE hInstance,
   _In_opt_ HINSTANCE hPrevInstance,
   _In_ PSTR pCmdLine,
   _In_ int nCmdShow)
#else // !_WIN32
int main(int argc, char** argv)
#endif // !_WIN32
{

    Interface ui("Chess");

    // Initialize the game class
    // note this is upside down: 0 row is at the bottom

    ogstream * pgout = new ogstream;

    Board board = Board(pgout);


#ifdef _WIN32
    //  int    argc;
 //  LPWSTR * argv = CommandLineToArgvW(GetCommandLineW(), &argc);
 //  string filename = argv[1];
   if (__argc == 2)
      readFile(__argv[1], board);
#else // !_WIN32
//   if (argc == 2)
//      readFile(argv[1], board);
#endif // !_WIN32

    // set everything into action
    ui.run(callBack, static_cast<void*>(&board));

    return 0;
}
