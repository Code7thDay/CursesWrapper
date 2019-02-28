//
// Created by mfbut on 2/24/2019.
//

#include <algorithm>
#include <iostream>
#include "FakeCursesWindow.h"

int FakeCursesWindow::curId = 0;
std::vector<std::unique_ptr<FakeCursesWindow>> FakeCursesWindow::activeWindows;

FakeCursesWindow::FakeCursesWindow(int numRows, int numCols, int rowStart, int colStart) :
    window(numRows, std::vector<FakeCursesCell>(numCols, FakeCursesCell(' '))),
    rowStart(rowStart), colStart(colStart),
    cursorRow(0), cursorCol(0),
    id(curId) {
  ++curId;
}

int FakeCursesWindow::getCurRow() const {
  return cursorRow;
}

int FakeCursesWindow::getCurCol() const {
  return cursorCol;
}

int FakeCursesWindow::getNumRows() const {
  return window.size();
}

int FakeCursesWindow::getNumCols() const {
  return window.front().size();
}

char FakeCursesWindow::getWindowChar(int row, int col) {
  moveCursor(row, col);
  return window.at(row).at(col).getChar();
}

char FakeCursesWindow::getWindowChar() {
  return getWindowChar(getCurRow(), getCurCol());
}

void FakeCursesWindow::moveCursor(int row, int col) {
  cursorRow = row;
  cursorCol = col;
}

void FakeCursesWindow::advanceToNextCell() {
  if (cursorCol == getNumCols() - 1 && cursorRow == getNumRows() - 1) {
    return;
  } else if (cursorCol == getNumCols() - 1) {
    cursorCol = 0;
    cursorRow++;
  } else {
    cursorCol++;
  }
}

void FakeCursesWindow::addCharacter(int row, int col, char value) {
  window.at(row).at(col).letter = value;
  moveCursor(row, col);
  advanceToNextCell();
}

void FakeCursesWindow::addCharacter(char value) {
  addCharacter(getCurRow(), getCurCol(), value);
}

void FakeCursesWindow::addString(int row, int col, const std::string& str) {
  moveCursor(row, col);
  for (const auto& let : str) {
    addCharacter(let);
    advanceToNextCell();
  }
}

void FakeCursesWindow::addString(const std::string& str) {
  addString(getCurRow(), getCurCol(), str);
}

int FakeCursesWindow::getRowStart() const {
  return rowStart;
}

int FakeCursesWindow::getColStart() const {
  return colStart;
}

const std::vector<FakeCursesCell>& FakeCursesWindow::cellAt(int i) const {
  return window.at(i);
}

std::vector<FakeCursesCell>& FakeCursesWindow::cellAt(int i) {
  return window.at(i);
}



void FakeCursesWindow::refresh() {

}

char FakeCursesWindow::getCharInput(int row, int col) {
  moveCursor(row, col);
  return std::cin.get();
}

char FakeCursesWindow::getCharInput() {
  return getCharInput(getCurRow(), getCurCol());
}

std::string FakeCursesWindow::getStringInput(int row, int col) {
  moveCursor(row, col);
  std::string input;
  std::cin >> input;
  return input;
}

std::string FakeCursesWindow::getStringInput() {
  return getStringInput(getCurRow(), getCurCol());
}

void FakeCursesWindow::setAdvanceCursorOn() {

}

void FakeCursesWindow::setAdvanceCursorOff() {

}

void FakeCursesWindow::moveCursorLeft(int amount) {
  const int newCol = std::max(0, getCurCol() - amount);
  moveCursor(getCurRow(), newCol);
}

void FakeCursesWindow::moveCursorRight(int amount) {
  const int newCol = std::min(getNumCols() - 1, getCurCol() + amount);
  moveCursor(getCurRow(), newCol);
}

void FakeCursesWindow::moveCursorUp(int amount) {
  const int newRow = std::max(0, getCurRow() - amount);
  moveCursor(newRow, getCurCol());
}

void FakeCursesWindow::moveCursorDown(int amount) {
  const int newRow = std::min(getNumRows() - 1, getCurRow() + amount);
  moveCursor(newRow, getCurCol());
}

Curses::RowReference FakeCursesWindow::at(int row) {
  return Curses::RowReference(*this, 0);
}

Curses::RowReference FakeCursesWindow::operator[](int row) {
  return Curses::RowReference(*this, 0);
}

void FakeCursesWindow::log(std::ostream& out) const {
  for (int i = 0; i < getNumRows(); ++i) {
    for (int j = 0; j < getNumCols(); ++j) {
      out << cellAt(i).at(j).letter;
    }
    out << std::endl;
  }
}

void FakeCursesWindow::log(std::ostream& out) {
  for (int i = 0; i < getNumRows(); ++i) {
    for (int j = 0; j < getNumCols(); ++j) {
      out << cellAt(i).at(j).letter;
    }
    out << std::endl;
  }
}

void FakeCursesWindow::clear() {
  for (int i = 0; i < getNumRows(); ++i) {
    for (int j = 0; j < getNumCols(); ++j) {
      cellAt(i).at(j).letter = ' ';
    }
  }
}



