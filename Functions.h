#pragma once

#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

void setColor(int color) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}


void showLoadingScreen() {
    cout << "\n\n\n\n\n\n\t\t\t\tLoading ";
    char x = 219;
    for (int i = 0; i <= 27; i++) {
        Sleep(80);
        cout << x;
    }
    system("cls");
}


void showMenu(int op) {
    setColor(32);
    cout << "===> Welcome to Battleship Game <===" << endl << endl;

    for (int i = 1; i <= 3; i++) {
        if (i == op) {
            setColor(10);
            cout << "-> ";
        }
        else {
            setColor(15);
            cout << "  ";
        }

        if (i == 1)
            cout << "New Game" << endl;

        else if (i == 2)
            cout << "How to Play" << endl;

        else if (i == 3)
            cout << "Exit" << endl;

    }
}