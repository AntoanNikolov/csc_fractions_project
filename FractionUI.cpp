#include <ncurses.h>
#include <iostream>
#include <string>

using namespace std;

int main(){
    
    int ymax, xmax;
 
    int numerator;
    int denominator;
    char operateur; //bc operator is a keyword lol
    
    int newnum;
    int newden;


    initscr();
    noecho();
    cbreak();
    getmaxyx(stdscr, ymax, xmax);

    move(1, 1);
    
    

    endwin();
    return 0;
}