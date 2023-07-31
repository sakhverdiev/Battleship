#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

#include "GameBoard.h"
#include "Functions.h"

int main() {
    int op = 1;
    char quitGame;
    bool exitGame = false;

    while (!exitGame) {
        system("cls");
        showMenu(op);
        // Menu Control

        switch (_getch()) {
        // Up
        case 72:  // Up key
        case 87:  // W
        case 119: // w
            op = (op - 1 < 1) ? 3 : op - 1;
            break;

        // Down
        case 80:  // Down key
        case 83:  // S
        case 115: // s
            op = (op + 1 > 3) ? 1 : op + 1;
            break;

        // Enter
        case 13:
            switch (op) {
            // Cursor Control
            case 1: {
                system("cls");
                setColor(10);
                showLoadingScreen();

                Board board;
                board.printBoard();

                while (!board.isGameOver()) {
                    char control = _getch();

                    switch (control) {
                    case 'w': // Move up
                    case 'W':
                        board.moveCursor(-1, 0);
                        break;

                    case 's': // Move down
                    case 'S':
                        board.moveCursor(1, 0);
                        break;

                    case 'a': // Move left
                    case 'A':
                        board.moveCursor(0, -1);
                        break;

                    case 'd': // Move right
                    case 'D':
                        board.moveCursor(0, 1);
                        break;

                    case 'f': // Fire
                    case 'F':
                        board.makeMove();
                        break;

                    case 'q': // Quit
                    case 'Q':
                        setColor(12);
                        cout << endl;
                        cout << "Quitting The Game";
                        Sleep(1000);
                        cout << ".";
                        Sleep(1000);
                        cout << ".";
                        Sleep(1000);
                        cout << ".";
                        Sleep(750);
                        return 0;

                    default:
                        setColor(12);
                        cout << endl;
                        cout << "Invalid input!" << endl << endl;
                        Sleep(1000);
                        cout << "Press 'f' if you want to fire" << endl;
                        Sleep(1500);
                        break;
                    }
                    board.printBoard();
                }

                setColor(13);
                cout << endl;
                cout << "Game Over" << endl << endl;
                Sleep(1500);
                cout << "Thanks For Playing The Game" << endl << endl;
                Sleep(1500);

                setColor(12);
                cout << "Returning to Menu";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                cout << ".";
                Sleep(1000);

                break;
            }

            case 2: {
                char skip;

                system("cls");
                setColor(10);
                showLoadingScreen();

                setColor(12);
                cout << endl;
                cout << "How to Play:" << endl << endl;
                Sleep(1000);
                setColor(13);
                cout << "Use the ";
                setColor(12);
                cout << "'WASD or wasd'";
                setColor(13);
                cout << " keys to move the cursor." << endl << endl;
                Sleep(1000);
                cout << "Press ";
                setColor(12);
                cout << "'F or f'";
                setColor(13);
                cout << " to fire the ship." << endl << endl;
                Sleep(1000);
                cout << "Press ";
                setColor(12);
                cout << "'Q or q'";
                setColor(13);
                cout << " to quit the game." << endl << endl;
                Sleep(1000);
                cout << "If you hit all the ships you win the game." << endl << endl;
                Sleep(1000);
                setColor(14);
                cout << "*" << " ==> Your Cursor" << endl;
                Sleep(1000);
                setColor(13);
                cout << char(177) << " ==> Ship" << endl;
                Sleep(1000);
                setColor(10);
                cout << "X" << " ==> Ship is Hit" << endl;
                Sleep(1000);
                setColor(12);
                cout << "M" << " ==> Ship is Miss" << endl << endl;
                Sleep(1000);
                setColor(23);
                cout << "===> Good Luck <==" << endl << endl;;
                Sleep(1000);
                setColor(10);
                cout << "Press a key to return to the menu ==> ";
                cin >> skip;
                break;
            }

            case 3: {
                system("cls");
                setColor(10);
                showLoadingScreen();

                setColor(12);
                exitGame = true;
                cout << endl;
                cout << "Exiting the Game";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                cout << ".";
                Sleep(1000);
                cout << ".";
                Sleep(850);
                break;
            }
            }
            break;

        default:
            break;
        }
    }

    return 0;
}