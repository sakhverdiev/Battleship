#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

const int BOARD_WIDTH = 20;
const int BOARD_HEIGHT = 10;

struct Board {
private:
    char board[BOARD_HEIGHT][BOARD_WIDTH];
    int* ships;
    int numShips;
    int cursorX;
    int cursorY;

public:
    Board() {
        cursorX = 0;
        cursorY = 0;

        for (int i = 0; i < BOARD_HEIGHT; i++) {
            for (int j = 0; j < BOARD_WIDTH; j++) {
                board[i][j] = ' ';
            }
        }

        setColor(12);
        cout << endl;
        cout << "Enter the number of ships: ";
        cin >> numShips;

        ships = new int[numShips];

        srand(time(NULL));
        for (int ship = 0; ship < numShips; ship++) {
            int x = rand() % BOARD_HEIGHT;
            int y = rand() % BOARD_WIDTH;

            while (board[x][y] == char(177)) {
                x = rand() % BOARD_HEIGHT;
                y = rand() % BOARD_WIDTH;
            }
            ships[ship] = x * BOARD_WIDTH + y;
            board[x][y] = char(177);
        }
    }

    // Destructor
    ~Board() {
        delete[] ships;
    }

    void setColor(int color) {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
    }

    void printBoard() {
        system("cls");

        setColor(11);
        cout << "Press 'f' to shoot" << endl;
        cout << "Press 'q' to quit" << endl << endl;

        setColor(14);
        cout << "*" << " ==> Cursor" << endl;
        setColor(13);
        cout << char(177) << " ==> Ship" << endl;
        setColor(10);
        cout << "X" << " ==> Hit" << endl;
        setColor(12);
        cout << "M" << " ==> Miss" << endl << endl;

        setColor(10);

        // Üst çizgi
        for (int i = 0; i < BOARD_WIDTH + 2; i++) {
            setColor(10);
            cout << "*";
        }
        cout << endl;

        for (int i = 0; i < BOARD_HEIGHT; i++) {
            setColor(10);
            cout << "*";
            for (int j = 0; j < BOARD_WIDTH; j++) {
                if (i == cursorX && j == cursorY) {
                    setColor(14);
                    cout << "*";
                }
                else if (board[i][j] == 'X') {
                    setColor(10);
                    cout << board[i][j];
                }
                else if (board[i][j] == 'M') {
                    setColor(12);
                    cout << board[i][j];
                }
                else {
                    setColor(13);
                    cout << board[i][j];
                }
            }
            setColor(10);
            cout << "*" << endl;
        }

        // Alt çizgi
        for (int i = 0; i < BOARD_WIDTH + 2; i++) {
            setColor(10);
            cout << "*";
        }
        cout << endl;
    }

    bool isGameOver() {
        for (int shipIndex = 0; shipIndex < numShips; shipIndex++) {
            int ship = ships[shipIndex];
            int x = ship / BOARD_WIDTH;
            int y = ship % BOARD_WIDTH;
            if (board[x][y] == char(177)) {
                return false;
            }
        }
        return true;
    }

    bool isValidMove(int x, int y) {
        if (x < 0 || x >= BOARD_HEIGHT || y < 0 || y >= BOARD_WIDTH) {
            return false;
        }
        return true;
    }

    void moveCursor(int dx, int dy) {
        int newX = cursorX + dx;
        int newY = cursorY + dy;

        if (isValidMove(newX, newY)) {
            cursorX = newX;
            cursorY = newY;
        }
    }

    void makeMove() {
        int index = cursorX * BOARD_WIDTH + cursorY;
        bool hit = false;

        for (int shipIndex = 0; shipIndex < numShips; shipIndex++) {
            int ship = ships[shipIndex];
            if (ship == index) {
                hit = true;
                break;
            }
        }

        cout << endl;
        if (hit) {
            if (board[cursorX][cursorY] == 'X') {
                setColor(12);
                cout << "Already hit that spot!" << endl;
            }
            else {
                setColor(10);
                cout << "Hit!" << endl;
                board[cursorX][cursorY] = 'X';
            }
        }

        else {
            setColor(12);
            cout << "Miss!" << endl;
            board[cursorX][cursorY] = 'M';
        }
        Sleep(1000);
    }
};