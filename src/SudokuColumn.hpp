#ifndef SUDOKUCOLUMN_HPP
#define SUDOKUCOLUMN_HPP

#include "SudokuElement.hpp"

class SudokuColumn : public virtual SudokuElement
{
  public:
    SudokuColumn(int**&, int, int); //SudokuBoard, col#, NumberSpace
};

#endif //SUDOKUCOLUMN_HPP