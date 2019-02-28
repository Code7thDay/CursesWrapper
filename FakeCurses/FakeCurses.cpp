//
// Created by mfbut on 2/24/2019.
//

#include <iostream>
#include "FakeCurses.h"

WINDOW* stdscr = nullptr;

WINDOW* newwin(int numRows, int numCols, int rowStart, int colStart) {
  //throw an exception if the vector doesn't contain stdscr

  FakeCursesWindow::activeWindows.push_back(
      std::make_unique<FakeCursesWindow>(numRows, numCols, rowStart, colStart));
  return FakeCursesWindow::activeWindows.back().get();
}

int delwin(WINDOW* win) {
  for (auto itr = FakeCursesWindow::activeWindows.begin();
       itr != FakeCursesWindow::activeWindows.end(); ++itr) {
    if (win == itr->get()) {
      FakeCursesWindow::activeWindows.erase(itr);
      return 0;
    }
  }
  //throw an exception
  return -1;
}

int getbegx(const WINDOW* win) {
  return win->getColStart();
}

int getbegy(const WINDOW* win) {
  return win->getRowStart();
}

int getmaxx(const WINDOW* win) {
  return win->getNumCols();
}

int getmaxy(const WINDOW* win) {
  return win->getNumRows();
}

int getcurx(const WINDOW* win) {
  return win->getCurCol();
}

int getcury(const WINDOW* win) {
  return win->getCurRow();
}

chtype mvwinch(WINDOW* win, int row, int col) {
  return win->getWindowChar(row, col);
}

chtype winch(WINDOW* win) {
  return win->getWindowChar();
}

void mvwaddch(WINDOW* win, int row, int col, char value) {
  win->addCharacter(row, col, value);
}

void waddch(WINDOW* win, char value) {
  mvwaddch(win, win->getCurRow(), win->getCurCol(), value);
}

void mvwaddstr(WINDOW* win, int row, int col, const char* str) {
  win->addString(row, col, str);
}

void waddstr(WINDOW* win, const char* str) {
  win->addString(str);
}

void wrefresh(WINDOW* win) {
  for (int i = 0; i < win->getNumRows(); ++i) {
    for (int j = 0; j < win->getNumCols(); ++j) {
      auto& stdCell = stdscr->cellAt(i + win->getRowStart()).at(j + win->getColStart());
      const auto& curCell = win->cellAt(i).at(j);
      stdCell.letter = curCell.letter;
    }
  }
  stdscr->moveCursor(win->getCurRow(), win->getCurCol());
}

char mvwgetch(WINDOW* win, int row, int col) {
  win->moveCursor(row, col);

  return std::cin.get();
}

char wgetch(WINDOW* win) {
  return mvwgetch(win, win->getCurRow(), win->getCurCol());
}

void wmove(WINDOW* win, int row, int col) {
  win->moveCursor(row, col);
}

void initscr() {
  stdscr = newwin(ROWS, COLS, 0, 0);
}

void echo() {

}

void noecho() {

}

void cbreak() {

}

void nocbreak() {

}

void raw() {

}

void noraw() {

}





