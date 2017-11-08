#ifndef SUDOKUROW_HPP
#define SUDOKUROW_HPP

#include "SudokuElement.hpp"

class SudokuRow : public virtual SudokuElement
{
  public:
    SudokuRow(int**&, int, int);
};

#endif //SUDOKUROW_HPP