#include "Fraction.h"
#include <ncurses.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int ymax, xmax;
 
    int num1;
    int den1;
    char operateur; //bc operator is a keyword lol
    
    int num2;
    int den2;
    
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
    move(0,(xmax/2));
    printw("Welcome to the nCurses Calculator!");
    refresh();
    
    echo();
    cbreak();
    getmaxyx(stdscr, ymax, xmax);
    
    // y, x
    move(1, 0);
    scanw("%d", &num1);

    move(3, 0);
    scanw("%d", &den1);
    

    move(ymax / 2, xmax / 2);

    scanw("%c", &operateur);

    move (0, xmax - 1);
    scanw("%d", &num2);
    
    move (3, xmax - 1);
    scanw("%d", &den2);

    endwin();
    return 0;
}