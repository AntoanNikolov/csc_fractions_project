#include "Fraction.h"
#include "Fractions.cpp"
#include <ncurses.h>
#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main(){
    
    int ymax, xmax;
    // strings are valid because our constructor handles them
    string num1 = "";
    string den1 = "";
    char operateur; //bc operator is a keyword lol
    
    string num2 = "";
    string den2 = "";

    int resultnum;
    int resultdenom;
    
    // activated after pressing enter on each value to know when to make objects
    // bool num1_done = false;
    // bool den1_done = false;
    // bool operator_done = false;
    
    // bool num2_done = false;
    // bool den2_done = false;

    initscr();
    // title
    move(0, (xmax/2));
    printw("Welcome to the nCurses Calculator!");
    
    refresh();
    
    
    echo();
    cbreak();
    getmaxyx(stdscr, ymax, xmax);
    
    mvprintw((ymax / 2), (xmax / 2) - 13, "%s", "---");
    mvprintw((ymax / 2), (xmax / 2) - 5, "%s", "---");

    // y, x
    //numerator stuff
    move((ymax / 2) - 1, (xmax / 2) - 12);
    while (num1 == "") {
        scanw("%s", &num1); 
        for (int i = 0; i < num1.length(); i++) {
            if (!isdigit(num1.at(i))){
                for (int k = 0; k < num1.length(); k++) {
                    move((ymax / 2) - 1 + k, (xmax / 2) - 12 + k);
                    delch();
                num1 = "";
                }
            }
        }
    }
   

    

    move((ymax / 2) + 1, (xmax / 2) - 12);
    
    scanw("%d", &den1);

    move((ymax / 2), (xmax / 2) - 8);
    scanw("%c", &operateur);
    
    move((ymax / 2) - 1, (xmax / 2) - 4);
    scanw("%d", &num2);
    
    move ((ymax / 2) + 1, (xmax / 2) - 4);
    scanw("%d", &den2);

    move((ymax / 2), (xmax / 2));
    addch('=');

    mvprintw((ymax / 2), (xmax / 2) + 2, "%s", "---");

    //Calculationismings!!!!!!!!!
    Fraction f1(stoi(num1), stoi(den1));
    Fraction f2(stoi(num2), stoi(den2));
    
    if (operateur == '+') {
        Fraction f3 = f1 + f2;  
        resultnum = f3.numerator;
        resultdenom = f3.denominator;
    } 

    else if (operateur == '-') {
        Fraction f3 = f1 - f2;  
        resultnum = f3.numerator;
        resultdenom = f3.denominator;
    }

    else if (operateur == '*') {
        Fraction f3 = f1 * f2;

        resultnum = f3.numerator;
        resultdenom = f3.denominator;
    }

    else if (operateur == '/') {
        Fraction f3 = f1 / f2;
        
        resultnum = f3.numerator;
        resultdenom = f3.denominator;
    }

    else {
        printw("y");
    }


    

    move((ymax / 2) - 1, (xmax / 2) + 4);
    printw(std::to_string(resultnum).c_str());

    move((ymax / 2) + 1, (xmax / 2) + 4);
    printw(std::to_string(resultdenom).c_str());
    
    // make it so that it wont disappear until you enter a character
    move(20,20);
    printw("Press any key to exit..."); 
    refresh();
    getch(); // makes program with for use

    endwin();
    return 0;
}