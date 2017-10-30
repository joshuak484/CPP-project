#ifndef SUDOKU_HPP
#define SUDOKU_HPP

#include "SudokuBoard.hpp"
#include "SudokuRow.hpp"
#include "SudokuColumn.hpp"
#include "SudokuNonomino.hpp"


class Sudoku : public SudokuBoard
{
  private:
    int numberspace;
    SudokuElement** rules;
  public:
    Sudoku();
    void getNewBoard9(int**&);
    bool isValid();
};

#endif //SUDOKU_HPP