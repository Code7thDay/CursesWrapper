//
// Created by mfbut on 2/24/2019.
//
#include "WindowImplementation.h"

/*
 * I've already added the cut to initialize curses if it hasn't been called
 * and to create the window. You may still need to do more initialization if
 * you have other members
 */
Curses::WindowImplementation::WindowImplementation(int numRows, int numCols, int startRow, int startCol) :
    cursesWindow(nullptr, delwin) {
  if (!stdscr) {
    initscr();
  }
  cursesWindow = std::unique_ptr<WINDOW, decltype(delwin)*>(newwin(numRows, numCols, startRow, startCol), delwin);
}

Curses::WindowImplementation::WindowImplementation(int numRows, int numCols) : WindowImplementation(numRows,
                                                                                                    numCols,
                                                                                                    0,
                                                                                                    0) {

}

//the unique pointer will automatically delete itself
//but if you dynamically allocate any more space for this
//problem make sure to free it here.
Curses::WindowImplementation::~WindowImplementation() {

}

char Curses::WindowImplementation::getWindowChar(int row, int col) {
  return 0;
}

char Curses::WindowImplementation::getWindowChar() {
  return 0;
}

char Curses::WindowImplementation::getCharInput(int row, int col) {
  return 0;
}

char Curses::WindowImplementation::getCharInput() {
  return 0;
}

std::string Curses::WindowImplementation::getStringInput(int row, int col) {
  return std::string();
}

std::string Curses::WindowImplementation::getStringInput() {
  return std::string();
}

void Curses::WindowImplementation::addCharacter(int row, int col, char value) {

}

void Curses::WindowImplementation::addCharacter(char value) {

}

void Curses::WindowImplementation::addString(int row, int col, const std::string& str) {

}

void Curses::WindowImplementation::addString(const std::string& str) {

}

int Curses::WindowImplementation::getRowStart() const {
  return 0;
}

int Curses::WindowImplementation::getColStart() const {
  return 0;
}

int Curses::WindowImplementation::getNumRows() const {
  return 0;
}

int Curses::WindowImplementation::getNumCols() const {
  return 0;
}

int Curses::WindowImplementation::getCurRow() const {
  return 0;
}

int Curses::WindowImplementation::getCurCol() const {
  return 0;
}

void Curses::WindowImplementation::moveCursor(int row, int col) {

}

void Curses::WindowImplementation::moveCursorLeft(int amount) {

}

void Curses::WindowImplementation::moveCursorRight(int amount) {

}

void Curses::WindowImplementation::moveCursorUp(int amount) {

}

void Curses::WindowImplementation::moveCursorDown(int amount) {

}

void Curses::WindowImplementation::setAdvanceCursorOn() {

}

void Curses::WindowImplementation::setAdvanceCursorOff() {

}

Curses::RowReference Curses::WindowImplementation::at(int row) {
  return RowReference(Curses::Window(), 0);
}

Curses::RowReference Curses::WindowImplementation::operator[](int row) {
  return RowReference(Curses::Window(), 0);
}

void Curses::WindowImplementation::refresh() {

}

void Curses::WindowImplementation::log(std::ostream& out) {

}


