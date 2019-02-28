//
// Created by mfbut on 2/24/2019.
//

#ifndef CURSESWRAPPER_FAKECURSESWINDOW_H
#define CURSESWRAPPER_FAKECURSESWINDOW_H
#include <vector>
#include <string>
#include <memory>
#include "FakeCursesCell.h"
#include "Window.h"

using chtype = int;
using attr_t = int;

class FakeCursesWindow : public Curses::Window {

 public:
  static std::vector<std::unique_ptr<FakeCursesWindow>> activeWindows;
  FakeCursesWindow(int numRows, int numCols, int rowStart, int colStart);

  virtual char getWindowChar(int row, int col) override;
  virtual char getWindowChar() override;

  virtual char getCharInput(int row, int col) override;
  virtual char getCharInput() override;

  virtual std::string getStringInput(int row, int col) override;
  virtual std::string getStringInput() override;



  void moveCursor(int row, int col);

  virtual void addCharacter(int row, int col, char value) override;
  virtual void addCharacter(char value) override;

  virtual void addString(int row, int col, const std::string& str) override;
  virtual void addString(const std::string& str) override;

  virtual int getRowStart() const override;
  virtual int getColStart() const override;

  virtual int getNumRows() const override;
  virtual int getNumCols() const override;
  virtual int getCurRow() const override;
  virtual int getCurCol() const override;

  const std::vector<FakeCursesCell>& cellAt(int i) const;
  std::vector<FakeCursesCell>& cellAt(int i);
  virtual Curses::RowReference at(int row) override;
  virtual Curses::RowReference operator[](int row) override;
  virtual void log(std::ostream& out) override;
  virtual void refresh() override;
  virtual void moveCursorLeft(int amount) override;
  virtual void moveCursorRight(int amount) override;
  virtual void moveCursorUp(int amount) override;
  virtual void moveCursorDown(int amount) override;
  virtual void setAdvanceCursorOn() override;
  virtual void setAdvanceCursorOff() override;

  void log(std::ostream& out) const;
  void clear();

 protected:
  void advanceToNextCell();

  static int curId;

  std::vector<std::vector<FakeCursesCell>> window;
  int rowStart, colStart;
  int cursorRow, cursorCol;
  const int id;

};

#endif //CURSESWRAPPER_FAKECURSESWINDOW_H
