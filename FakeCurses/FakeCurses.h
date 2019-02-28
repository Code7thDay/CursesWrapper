//
// Created by mfbut on 2/24/2019.
//

#ifndef CURSESWRAPPER_FAKECURSES_H
#define CURSESWRAPPER_FAKECURSES_H

#include "FakeCursesWindow.h"
using WINDOW = FakeCursesWindow;
using chtype = int;
using attr_t = int;

constexpr int ROWS = 100;
constexpr int COLS = 100;
extern WINDOW* stdscr;
void initscr();

WINDOW* newwin(int numRows, int numCols, int rowStart, int colStart);
int delwin(WINDOW* win);

int getbegx(const WINDOW* win);
int getbegy(const WINDOW* win);

int getmaxx(const WINDOW* win);
int getmaxy(const WINDOW* win);

int getcurx(const WINDOW* win);
int getcury(const WINDOW* win);



chtype mvwinch(WINDOW* win, int row, int col);
chtype winch(WINDOW* win);

char mvwgetch(WINDOW* win, int row, int col);
char wgetch(WINDOW* win);

void mvwaddch(WINDOW* win, int row, int col, char value);
void waddch(WINDOW* win, char value);

void mvwaddstr(WINDOW* win, int row, int col, const char* str);
void waddstr(WINDOW* win, const char* str);
void wrefresh(WINDOW* win);

void wmove(WINDOW* win, int row, int col);

void echo();
void noecho();
void cbreak();
void nocbreak();
void raw();
void noraw();


#endif //CURSESWRAPPER_FAKECURSES_H
