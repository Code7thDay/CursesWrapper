//
// Created by mfbut on 2/25/2019.
//

#ifndef CURSESWRAPPER_FAKECURSESCELL_H
#define CURSESWRAPPER_FAKECURSESCELL_H
#include <vector>

class FakeCursesCell {
 public:
  FakeCursesCell(char letter);
  char getChar() const;
  char letter;
};

#endif //CURSESWRAPPER_FAKECURSESCELL_H
