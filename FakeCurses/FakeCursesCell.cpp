//
// Created by mfbut on 2/25/2019.
//

#include "FakeCursesCell.h"


FakeCursesCell::FakeCursesCell(char letter) : letter(letter) {}

char FakeCursesCell::getChar() const {
  return letter;
}
